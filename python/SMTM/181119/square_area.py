width = int(input('가로 값을 넣으세요:'))
while width < 0:
    width = int(input('양수를 넣으세요:'))

height = int(input('세로 값을 넣으세요:'))
while height < 0:
    height = int(input('양수를 넣으세요:'))

print('사각형의 면적: %d' % (width * height))
