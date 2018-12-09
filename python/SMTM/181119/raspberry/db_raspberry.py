# PiCamera와 Python을 이용한 모션 감지 코드입니다
# Motion 라이브러리를 Python 위에서 구현하기에는 어려운 점이 있어서
# Motion 알고리즘을 대신 사용했습니다.
# 하지만 기능은 동일하며, Motion 알고리즘이 더 빠릅니다.
from datetime import datetime
import pymysql

import picamera
import picamera.array
import time

conn = pymysql.connect(host ='localhost', user = 'root', password='', db='mydb', charset='utf8')
sql = "INSERT INTO table1 (tm) VALUES (%s);"
mydb == varchar(60)

threshold = 10    # 픽셀 변화량 기준을 지정합니다
sensitivity = 100 # 바뀐 픽셀 수가 sensitivity 이상이면 모션을 감지하기 위해서 설정합니다.

def event():
    global conn, curs, sql
    now = datetime.now()                    # 현재 시간을 받아옵니다
    # 현재시간을 ex) 18-12-25 00:10:12 이런 식으로 알려줍니다.
    tm = "%s-%s-%s %s:%s:%s" % (now.year, now,month, now.day, now.hour, now.minute, now.second)
    curs.execute(sql, tm)
    conn.commit()
    print('COMPLETE!')

def takeMotionImage(width, height):
    with picamera.PiCamera() as camera:
        time.sleep(1)
        camera.resolution = (width, height)
        with picamera.array.PiRGBArray(camera) as stream:
            camera.exposure_mode = 'auto'
            camera.awb_mode = 'auto'
            camera.capture(stream, format='rgb')
            return stream.array

def scanMotion(width, height):
    motionFound = False     # 모션감지를 False로 초기화
    data1 = takeMotionImage(width, height)          # 지금 카메라에 찍힌 이미지를 data1 오브젝트에저장
    while not motionFound:  # 모션감지가 될 때 까지 반복
        data2 = takeMotionImage(width, height)      # 지금 카메라에 찍힌 이미지를 data2 오브젝트에저장
        diffCount = 0       # 카운트 설정

        # width와 height만큼의 픽셀을 하나씩 하나씩 다름을 비교합니다.
        for w in range(0, width):
            for h in range(0, height):
                # diff는 픽셀이 얼만큼 다른지를 int형으로 변환하여 저장합니다
                # 그 이유는 unsigned short의 오버플로우를 막기 위해서 변환합니다.
                diff = abs(int(data1[h][w][1]) - int(data2[h][w][1]))   # data1과 data2가 얼마나 다른지 측정
                if  diff > threshold:               # 기존 설정값보다 다르면
                    diffCount += 1                  # Count 추가
            if diffCount > sensitivity:             # 픽셀 변화수 보다 Count가 높다면
                break;                              # Break함수로 반복문 탈출후 36번째 줄에서
        if diffCount > sensitivity:
            motionFound = True                      # 모션 움직임을 감지했다고 True로 바꿈
        else:
            data2 = data1
    return motionFound                              # 모션이 감지되었는지 안되었는지를 보냄

def motionDetection():
    print "Scanning for Motion threshold=%i sensitivity=%i...  % (threshold, sensitivity)
    while True:
        if scanMotion(224, 160):                # 모션이 감지되면,
        print("Motion detected")
        event()                             # 데이터를 전송합니다

if __name__ == '__main__':
    try:
        print("POWER ON")
        motionDetection()
    finally:
        print("Exiting Program")
