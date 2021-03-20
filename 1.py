#输出灰度图像
import cv2
#读取彩图
img = cv2.imread('E:/opencv py/1.jpg', 1)
#转化为灰度图像
dst = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
#输出
cv2.namedWindow('1.jpg', cv2.WINDOW_NORMAL)
cv2.imshow('1.jpg', dst)
cv2.waitKey(0)
cv2.imshow('1.jpg', img)
cv2.waitKey(0)
