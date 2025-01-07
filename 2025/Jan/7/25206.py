import sys

input = sys.stdin.readline

cnt = 0
total = 0

grade = {
    'A+': 4.5,
    'A0': 4.0,
    'B+': 3.5,
    'B0': 3.0,
    'C+': 2.5,
    'C0': 2.0,
    'D+': 1.5,
    'D0': 1.0,
    'F': 0
}

while True:
    try:
        title, c, g = input().rstrip().split()
        # print(title, score, pf)

        if g == 'P':
            continue

        tmp = float(c)
        cnt += tmp
        score = grade[g] * tmp
        total += score

    except ValueError:
        break

gpa = total / cnt
print(gpa)
