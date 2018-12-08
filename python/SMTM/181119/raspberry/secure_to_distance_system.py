import RPi.GPIO as GPIO         #라즈베리파이의 GPIO를 사용하기 위해서 사용합니다.
import time                     #데이터베이스에 현재의 시간을 전송하기 위해서 사용합니다.
from picamera import PiCamera   #파이카메라 모듈을 사용합니다.

#GPIO 기초적인 설정을 해 주는 코드입니다.
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#어떤 핀이 어디에 꽂혀있는지 설명하는 코드입니다.
trig = 13
pwm_pin = 18
echo = 19
led = 24

#Boolean 변수를 이용해서 현재 영상과 LED의 동작 여부를 확인합니다.
recStat = False
ledStat = False

#센서를 사용하기 위한 기초적인 세팅방법입니다.
GPIO.setup(trig, GPIO.OUT)
GPIO.setup(echo, GPIO.IN)
GPIO.setup(pwm_pin, GPIO.OUT)
GPIO.setup(led, GPIO.OUT)

#카메라 설정입니다.
camera = PiCamera()
#서보모터 설정 및 시작입니다.
pwm = GPIO.PWM(pwm_pin, 50)
pwm.start(0)

while True:
    if ledStat == False:            #LED가 꺼져있다면
        GPIO.output(led, False)     #LED를 켜 줍니다
    else:                           #LED가 켜져있다면
        GPIO.output(led, True)      #LED를 꺼줍니다.

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
