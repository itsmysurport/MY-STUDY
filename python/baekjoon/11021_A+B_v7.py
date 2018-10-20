# 두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

set = int(input())

for i in range (0, set):
    a, b = map(int, input().split())
    print('Case #{}: {}'.format(i+1, a+b))
