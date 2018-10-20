# 세자리수 x 세자리수 곱셈의 계산 식을 출력하는 프로그램을 작성하시오.

a = int(input())
b = int(input())

print(a * ((b % 100) % 10))
print(a * ((int)((b % 100) / 10)))
print(a * ((int)(b / 100)))
print(a * b)
