import serial
import time
import calibration as cl

ser = serial.Serial("/dev/ttyACM1")
command = input("Your command? CALIBRATION - mod1 NORMAL - mod2" +
                        '\n' + "Press Ctrl+C to complete.")

def main(data):
        data = data.split(' ')
        cl.plot_update()
        return data

while (True):
	command = input()
	#command = command + '\n'
	ser.write(bytes("getVal", 'utf-8'))
	time.sleep(0.5)
	data = ""
	if (ser.in_waiting > 0):
		data = ""
		while (ser.in_waiting > 0):
			data += ser.read().decode("utf-8")
		data = data.replace("\r\n", "")
		
	#print(data)
	if (command == "mod1"):
                data = data.split(' ')
                cl.calibrate(data[0], data[1])
                cl.plot_calibrate()
        if (command == "mod2"):
                main(data)      

ser.close()

