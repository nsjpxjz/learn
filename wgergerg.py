import cv2 as cv
import numpy as np
img=cv.imread("u=1126872681,3306032964&fm=26&gp=0.jpg")
hasv=cv.cvtColor(img, cv.COLOR_BGR2HSV)
h,s,v=cv.split(hasv)
v[:,:,]=255
newhasv=cv.merge([h,s,v])
cv.imshow('happy',hasv)
art=cv.cvtColor(newhasv,cv.COLOR_HSV2BGR_FULL)
cv.imshow('art',art)
cv.waitKey()