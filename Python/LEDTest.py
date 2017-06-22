import RPi.GPIO as GPIO
import time

port = 5

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(port,GPIO.OUT)
print "LED on"
GPIO.output(port, GPIO.LOW)
time.sleep(1)
print "LED off"
GPIO.output(port, GPIO.HIGH)
