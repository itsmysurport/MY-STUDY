def get_dict(N):
    s = { }
    for i in range (0,N):
        name, score = input('"이름, 점수" 순으로 입력하세요. >> ').split(',')
        score = int(score)
        s[score] = name
    return s

N = int(input('몇 명을 입력 하시겠습니까? :'))
scores = get_dict(N)

for i in range (0, N):
    print(scores[max(scores)], max(scores))
    del scores[max(scores)]
