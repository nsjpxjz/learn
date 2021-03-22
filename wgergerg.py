import cv2 as cv
import numpy as np
img=cv.imread('u=1126872681,3306032964&fm=26&gp=0.jpg')
cv.imshow('dq',img)
r,c,h=img.shape
x=np.zeros((r,c,h,8),dtype=np.uint8)
for i in range(8):
    x[:,:,:,i]=2**i
r=np.zeros((r,c,h,8),dtype=np.uint8)
for i in range(8):
    r[:,:,:,i]=cv.bitwise_and(img,x[:,:,:,i])
    mask=r[:,:,:,i]>0
    r[mask]=255
    cv.imshow(str(i),r[:,:,:,i])
cv.waitKey()
cv.destroyAllWindows()