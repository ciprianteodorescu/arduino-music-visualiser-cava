import serial
import time


ser = serial.Serial('/dev/ttyACM2', 230400)

while True:
	initial = input()
	listed = initial.split(';')
	listed.remove('')
#	ser.write(str('S').encode('utf-8'))
	for e in listed:
		ser.write((str(e) + ' ').encode('utf-8'))
		print(str(e) + ' ', end='')
	ser.write(str('\n').encode('utf-8'))
#	ser.write(str('E').encode('utf-8'))
	print('\n')
