Input = lambda: map(int, input().split())
n, m, q = Input()
s = input()
t = input()

pre = [ 0 for i in range(n + 5)]
for i in range(0, n - m + 1):
    if s[i:i+m] == t:
        pre[i + 1] = 1

for i in range(1, n + 3):
    pre[i] += pre[i - 1]

for i in range(q):
    l, r = Input()
    if r - l + 1 < m:
        print(0)
        continue
    
    print(pre[r - m + 1] - pre[l - 1])
