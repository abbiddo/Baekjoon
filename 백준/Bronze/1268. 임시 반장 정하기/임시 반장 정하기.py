n = int(input())
ban = []  # 학생별 1~5학년까지 속했던 반
same = [0] * n  # 행 번 학생이 열 번 학생과 같은 반이었는지 여부
for i in range(n):
    ban.append(list(map(int, input().split())))
    same[i] = [0] * n

for i in range(5):  # i 학년
    for j in range(n):  # j번의 i 학년
        for k in range(j + 1, n):  # k번의 i 학년을 비교
            # j번과 k번이 i학년 때 같은 반이었으면
            if ban[j][i] == ban[k][i]:
                # same을 1로 바꾼다.
                same[k][j] = 1
                same[j][k] = 1
                # += 1을 하면 같은 반이였던 횟수가 same에 저장

cnt = []  # 학생별 같은 반이였던 학생 수
for s in same:
    cnt.append(s.count(1))

print(cnt.index(max(cnt)) + 1)