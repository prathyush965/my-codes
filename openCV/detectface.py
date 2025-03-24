import cv2 as cv

cap = cv.VideoCapture(0) 
haar = cv.CascadeClassifier(cv.data.haarcascades + 'haarcascade_frontalface_default.xml')

while True:
    isTrue,frame=cap.read()
    cv.imshow("WebCam",frame)

    gray=cv.cvtColor(frame,cv.COLOR_BGR2GRAY)
    frame_rect = haar.detectMultiScale(gray,scaleFactor=1.1,minNeighbors=3)

    for(x,y,w,h) in frame_rect:
        cv.rectangle(frame,(x,y),(x+w,y+h),(0,0,255),thickness=3)
    cv.imshow('detected feed',frame)
    
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv.destroyAllWindows()