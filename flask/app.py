import os
import cv2 as cv
import numpy as np
from flask import Flask, render_template, Response

app = Flask(__name__)

face_rec = cv.face.LBPHFaceRecognizer_create()
face_rec.read(r"C:\Users\pushp\Documents\titta\workaholic\vs\openCV\trained_model.yml")  
haar = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_frontalface_default.xml")

dataset_dir = r"C:\Users\pushp\Documents\titta\workaholic\vs\openCV\face recognition input"
p = [i for i in os.listdir(dataset_dir)]

cap = cv.VideoCapture(0)

def generate_frames():
    while True:
        success, frame = cap.read()
        if not success:
            break
        
        frame = cv.flip(frame, 1)
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        faces = haar.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=4)

        for (x, y, w, h) in faces:
            face_region = gray[y:y+h, x:x+w]
            label, confidence = face_rec.predict(face_region)
            name = "Unknown"

            if confidence >= 60 and label < len(p):
                name = p[label]

            cv.putText(frame, name, (x, y-10), cv.FONT_HERSHEY_SIMPLEX, 0.9, (0, 0, 255), 4)
            cv.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 3)

        _, buffer = cv.imencode('.jpg', frame)
        frame_bytes = buffer.tobytes()

        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame_bytes + b'\r\n')

@app.route('/')
def index():
    return render_template("facerecfrontend.html")

@app.route('/video_feed')
def video_feed():
    return Response(generate_frames(), mimetype='multipart/x-mixed-replace; boundary=frame')

if __name__ == "__main__":
    app.run(debug=True)
