n, m = map(int, input().split())
sum = 0
dx = []

for i in range(n):
    a, b = map(int, input().split())
    sum += a
    dx.append(a - b)

dx.sort(reverse = True)
ans = 0
for x in dx:
    if sum <= m:
        break
    sum -= x
    ans += 1

if sum <= m:
    print(ans)
else:
    print(-1)
