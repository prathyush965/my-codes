import os
import cv2 as cv
import numpy as np

p = []
for i in os.listdir(r'C:\Users\pushp\Documents\titta\workaholic\vs\openCV\face recognition input'):
    p.append(i) 

dataset_dir = r"C:\Users\pushp\Documents\titta\workaholic\vs\openCV\face recognition input"
haar = cv.CascadeClassifier(cv.data.haarcascades + "haarcascade_frontalface_default.xml")

face = []
label = []

def train():
    for pers in p:
        per_path= os.path.join(dataset_dir,pers)
        per_label = p.index(pers)
        
        for img in os.listdir(per_path):
            img_path = os.path.join(per_path,img)
            
            img =  cv.imread(img_path)
            gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
            
            face_detect = haar.detectMultiScale(gray,1.1,4)
            for (x,y,w,h) in face_detect:
                region = gray[y:y+h,x:x+w]
                face.append(region)
                label.append(per_label)

train()
print("training complete......")

face = np.array(face,dtype='object')
label = np.array(label)

face_rec = cv.face.LBPHFaceRecognizer_create()
face_rec.train(face,label)

face_rec.save('trained_model.yml')
np.save('face.npy',face)
np.save('label.npy',label)