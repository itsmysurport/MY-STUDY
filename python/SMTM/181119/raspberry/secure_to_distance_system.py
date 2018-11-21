import RPi.GPIO as GPIO
import time
from picamera import PiCamera

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

trig = 13
pwm_pin = 18
echo = 19
led = 24
recStat = False
ledStat = False

GPIO.setup(trig, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)
GPIO.setup(pwm_pin, GPIO.OUT)
GPIO.setup(led, GPIO.OUT)

camera = PiCamera()
pwm = GPIO.PWM(pwm_pin, 50)
pwm.start(0)

while True:
    if ledStat == False:
        GPIO.output(led, GPIO) #unlocked
    else:
        GPIO.output(led, True)  #locked

    GPIO.output(trig, False)
    time.sleep(0.5)

    GPIO.output(trig, True)
    time.sleep(0.00001)
    GPIO.output(trig, False)

    while GPIO.input(echo) == False:
        pulse_start = time.time()
    while GPIO.input(echo) == True:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17000
    distance = round(distance, 2)
    print("Distance : ", distance, "cm")

    if distance < 6:
        if recStat == False:
            print('recstart')
            camera.start_preview()
            camera.start_recording('/home/pi/video.h264')
            recStat = True
        pwm.ChangeDutyCycle(50)
        ledStat = True
    else:
        ledStat = False
        pwm.ChangeDutyCycle(0)

        if recStat == True:
            print('recstop')
            camera.stop_recording()
            camera.stop_preview()
            recStat = False
    time.sleep(2)

except:
    GPIO.cleanup()
