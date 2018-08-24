Input = lambda:map(int, input().split())
n, m = Input()
dx = []
sum = 0
for i in range(n):
    a, b = Input()
    sum += a
    dx.append(a - b)

ans = 0
for x in sorted(dx, reverse = True):
    if sum <= m:
        break
    sum -= x
    ans += 1

if sum <= m:
    print(ans)
else:
    print(-1)