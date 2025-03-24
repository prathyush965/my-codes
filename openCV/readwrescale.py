import cv2 as cv

def rescaleFrame(img,scale=0.2):
    width = int(img.shape[1]*scale)
    height = int(img.shape[0]*scale)
    dimensions = (width,height)
    return cv.resize(img,dimensions,interpolation=cv.INTER_AREA)

img = cv.imread(r"C:\Users\pushp\Documents\titta\workaholic\vs\openCV\photos\DSC08053.JPG")
img_resized = rescaleFrame(img)
cv.imshow("DSC08053", img_resized)

cv.waitKey(0)
cv.destroyAllWindows()