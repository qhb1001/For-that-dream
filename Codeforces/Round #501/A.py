n, m = map(int, input().split())
ans = list(range(1 + m))
for i in range(n):
    l, r = map(int, input().split())
    for j in range(l, r + 1):
        ans[j] = 0
b = []
for i in range(1 + m):
    if ans[i] != 0:
        b.append(i)

print(len(b))
print(*b)