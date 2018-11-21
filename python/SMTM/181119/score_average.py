count = 0
sum = 0
print('종료를 원하면 음수를 넣으세요')
while True:
    a = int(input('점수를 입력하세요:'))
    if a < 0:
        print('%d개의 점수의 합은 %d이며 평균은 %0.2f입니다.' % (count, sum, sum/count))
        break
    else:
        sum += a
        count += 1
