import cv2 as cv
def rescaleFrame(img,scale=0.65):
    width = int(img.shape[1]*scale)
    height = int(img.shape[0]*scale)
    dimensions = (width,height)
    return cv.resize(img,dimensions,interpolation=cv.INTER_AREA)

img=cv.imread(r'C:\Users\pushp\Documents\titta\workaholic\vs\openCV\photos\sample.jpg')
img2=rescaleFrame(img)
cv.imshow('sample',img2)

edge=cv.Canny(img2,125,175)
cv.imshow('Edge',edge)

cv.waitKey(0)
cv.destroyAllWindows