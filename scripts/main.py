#! /usr/bin/env python3
import concurrent.futures
import serial
import time
import cv2
import numpy as np
import urllib.request


url='http://192.168.2.112/cam-lo.jpg'
def control_keyboard(port, key):
    msg = {97:"a",
           119:"w",
           115:"s",
           100:"d",
           50:"u",
           56:"b",
           52:"l",
           54:"r"}

    data = port.read(4).decode()
    # print(str(msg[key]))
    if data !="":
        print(data)
    port.write(str(msg[key]).encode())


def run():
    SETUP 		 = False
    port 		 = None
    prev = time.time()
    while(not SETUP):
        try:
            port = serial.Serial("COM4", 115200, timeout=1)

        except: # Bad way of writing excepts (always know your errors)
            if(time.time() - prev > 2): # Don't spam with msg
                print("No serial detected, please plug your uController")
                prev = time.time()

        if(port is not None): # We're connected
            SETUP = True
        
    cv2.namedWindow("Camera left: ", cv2.WINDOW_AUTOSIZE)
    frame = cv2.imread("D:/User/firmware/Screen/hinh-anh-mat-cuoi2-1.png")
    # frame = cv2.VideoCapture(0)
    while True:

        cv2.imshow("Camera left: ", frame)
        key = cv2.waitKey(1)
        if key!=-1:
            # print(key)
            try :
                control_keyboard(port,key)
            except:
            # print('err')
                pass
        if key==ord('x'):
            break
    cv2.destroyAllWindows()

if __name__ == '__main__':
    print("started")
    with concurrent.futures.ProcessPoolExecutor() as executer:
            f = executer.submit(run)
