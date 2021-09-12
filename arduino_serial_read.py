# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import re
import serial
from openpyxl import Workbook

ex = Workbook()
ws = ex.active

ser = serial.Serial(port="COM3",baudrate=115200);


i=0
while i<=1500 :
    if ser.readable():
        res = ser.readline();
        print((res.decode()[:len(res)-1]))
        ws.append((res.decode()[:len(res)-1]).split())
        i=i+1
    else :
        print('not yet')

ex.save("C:\ibi_data\hm_normal.xlsx")