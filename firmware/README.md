import argparse
import time
import cv2
import numpy as np
from ultralytics import YOLO


def parse_args():
    p = argparse.ArgumentParser(description="YOLO sobre stream MJPEG de ESP32-CAM")
    p.add_argument("--url", required=True, help="URL del stream (ej. http://IP:81/stream)")
    p.add_argument("--model", default="yolov8n.pt", help="Modelo YOLO")
    p.add_argument("--conf", type=float, default=0.35, help="Umbral de confianza")
    p.add_argument("--save", action="store_true", help="Guardar video")
    p.add_argument("--show", action="store_true", help="Mostrar video")
    p.add_argument("--max_w", type=int, default=640, help="Ancho máximo (0 = no escalar)")
    p.add_argument("--reconnect", type=int, default=3, help="Intentos de reconexión")
    return p.parse_args()


def open_capture(url: str):
    
    cap = cv2.VideoCapture(url)
    cap.set(cv2.CAP_PROP_BUFFERSIZE, 1)
    return cap


def main():
    print("🚀 Iniciando detección...")

    args = parse_args()
    model = YOLO(args.model)

    cap = open_capture(args.url)

    if not cap.isOpened():
        print(f"❌ No se puede abrir el stream: {args.url}")
        return

    writer = None
    prev_time = time.time()
    fps = 0.0
    reconnects_left = args.reconnect

    while True:
        ok, frame = cap.read()

        if not ok or frame is None:
            print("⚠️ Frame nulo. Reconectando...")
            cap.release()
            time.sleep(1)
            cap = open_capture(args.url)

            if not cap.isOpened():
                reconnects_left -= 1
                if reconnects_left < 0:
                    print("❌ Sin conexión. Saliendo...")
                    break
                continue

            reconnects_left = args.reconnect
            continue

        # Redimensionar (mejora FPS)
        if args.max_w > 0 and frame.shape[1] > args.max_w:
            h = int(frame.shape[0] * (args.max_w / frame.shape[1]))
            frame = cv2.resize(frame, (args.max_w, h))

        # YOLO
        results = model(frame, conf=args.conf, verbose=False)
        annotated = frame.copy()

        for r in results:
            if r.boxes is None:
                continue

            for box in r.boxes:
                cls_id = int(box.cls[0])
                conf = float(box.conf[0])
                x1, y1, x2, y2 = map(int, box.xyxy[0])

                label = f"{model.names[cls_id]} {conf:.2f}"

                cv2.rectangle(annotated, (x1, y1), (x2, y2), (0, 255, 0), 2)
                cv2.putText(annotated, label, (x1, y1 - 5),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

        # FPS
        now = time.time()
        fps = fps * 0.9 + (1.0 / max(1e-6, now - prev_time)) * 0.1
        prev_time = now

        cv2.putText(annotated, f"FPS: {fps:.1f}", (10, 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

        # Mostrar
        if args.show:
            cv2.imshow("ESP32-CAM + YOLO", annotated)

            if cv2.waitKey(1) & 0xFF in [27, ord('q')]:
                break

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    main()