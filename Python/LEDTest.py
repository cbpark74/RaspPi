import RPi.GPIO as GPIO
import time

ports = [6, 5, 21, 20]

sleepTimeInSec = 0.1

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
print "blinking LED: start"
for j in range(0,10):
    for i in range(0, 4):

        port = ports[i]
        GPIO.setup(port,GPIO.OUT)
        
        GPIO.output(port, GPIO.HIGH)
        time.sleep(sleepTimeInSec)
        GPIO.output(port, GPIO.LOW)
        time.sleep(sleepTimeInSec)


print "blinking LED: end"
