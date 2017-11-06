import serial
import time

ser = serial.Serial("/dev/ttyACM1")
#70 - 400 - разброс нашего датчика, 5 уровней определяется из (400-70)/5 = 66

stop = int(input("Чтобы остановить выполнение программы, нажмите Ctrl+C "))
larity = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0}
larity_str = {0: 'First', 1: 'Second', 2: 'Third', 3: 'Fourth', 4: 'Fifth'}
while (True):
        '''получаем уровень яркости с датчика'''
        if (ser.in_waiting > 0):
                color = ''
                while (ser.in_waiting > 0):
                        color = ser.readline().decode("UTF-8").replace("\r\n", "")

                print(color)
                color = int(color)
        '''если цвет поменялся, то отправляем новую команду на плату '''
        for i in range(5):
                if (color =< (i + 1) * 66):
                        if larity[i] == 1:
                                break
                        else:
                             larity[i] = 1
                             ser.write(bytes("On" + larity_str[i], 'utf-8'))
                        break

ser.close()
