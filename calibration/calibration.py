import matplotlib.pyplot as plt
import matplotlib.animation as anim
import math
import serial
import ser

correct = [0]*1024
s1, s2 = None 

def calibrate(s1, s2):
        correct[s1] = (correct[s1] + (s1 - s2)) / 2
	#s1 = s1
	#s2 += correct[s1]

#чертит график в реальном времени
def plot_update():
	sen1 = []
	sen2 = []
	fig = plt.figure("Неоткалиброванные измерения двух датчиков")
	fig2 = plt.figure("Откалиброванные измерения двух датчиков")
	ax = fig.add_subplot(1,1,1)
	a2x = fig.add_subplot(1,1,1)
	
	def update(i):
		sen1i = ser.main()[0]
		sen2i = ser.main()[1]
		sen1.append(sen1i)
		sen2.append(sen2i)
		x = range(len(sen1))
		ax.clear()
		ax.plot(x[:50], sen1[-50:])
		ax.plot(x[:50], sen2[-50:])

	a = anim.FuncAnimation(fig, update, repeat=False)
	def update2(i):
		sen1i = ser.main()[0]
		sen2i = ser.main()[1] + correct[ser.main()[0]]
		sen1.append(sen1i)
		sen2.append(sen2i)
		x = range(len(sen1))
		a2x.clear()
		a2x.plot(x[:50], sen1[-50:])
		a2x.plot(x[:50], sen2[-50:])
	
	a2 = anim.FuncAnimation(fig2, update2, repeat=False)
	plt.show()

def plot_calibrate():
	plt.plot(correct)
	plt.show()
