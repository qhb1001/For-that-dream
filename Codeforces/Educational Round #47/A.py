from sys import stdin, stdout
n, m = map(int, stdin.readline().split())
a, b = list(map(int, stdin.readline().split())), list(map(int, stdin.readline().split()))

cnt, ans = 0, 0
for x in a:
    if b[cnt] >= x:
        ans += 1
        cnt += 1
    if cnt == len(b):
        break

print (ans)