import serial
import time

ser = serial.Serial("/dev/ttyACM0")
#200 - 400; 70 - 200
while(True):
	if (ser.read() > 200):
		ser.write(bytes(command, "utf-8"))
	command = input("Your command (On 'blue/red'/Off): ")
	ser.write(bytes(command, 'utf-8'))
ser.close()
#cur = 0
#result = int(ser.readline().decode().strip())
ser.write(bytes("On",'utf-8'))
#while(True):
#	result = int(ser.readline().decode().strip())
#	print(result)
#	if(cur != result):
#		cur = result
#		#if (result < 150):
#		ser.write(bytes("On", 'utf-8'))
#		#else:
#		#	ser.write(bytes("Off", 'utf-8'))
