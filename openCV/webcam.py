import cv2 as cv

#def changeRes(width,height):
    #cap.set(3,width)
    #cap.set(4,height)

cap = cv.VideoCapture(0)
#changeRes(640,1080)
while True:
    isTrue,frame=cap.read()
    cv.imshow("WebCam",frame)
    
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
    
cap.release()
cv.destroyAllWindows 