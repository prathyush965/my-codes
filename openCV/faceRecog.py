import cv2 as cv 
import numpy as np
import os

face_rec = cv.face.LBPHFaceRecognizer_create()
face_rec.read(r'C:\Users\pushp\Documents\titta\workaholic\vs\openCV\trained_model.yml')
haar = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_frontalface_default.xml")

p = []
for i in os.listdir(r'C:\Users\pushp\Documents\titta\workaholic\vs\openCV\face recognition input'):
    p.append(i)

cap = cv.VideoCapture(0)

while True:
    isTrue,frame=cap.read()
    frame = cv.flip(frame, 1)
    gray = cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    frame_rect = haar.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=4)

    for(x,y,w,h) in frame_rect:
        region = gray[y:y+h,x:x+w]

        label,confidence = face_rec.predict(region)
        per_name = "Unknown"
         
        if confidence >= 60 and label < len(p):  
            per_name = p[label] 
        
        cv.putText(frame,per_name,(x,y-10),cv.FONT_HERSHEY_SIMPLEX,0.9,(0,0,255),4)
        cv.rectangle(frame,(x,y),(x+w,x+h),(255,0,0),3)
    
    cv.imshow('Face Recognition', frame)
    
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
print("confidence rate: ",confidence)
cap.release()
cv.destroyAllWindows()
