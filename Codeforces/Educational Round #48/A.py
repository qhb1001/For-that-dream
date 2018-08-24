Input = lambda:map(int, input().split())

n, m = Input()
l = list(Input())

now = 0
ans = []
for x in l:
    ans.append((now + x) // m)
    now = (x + now) % m

print(' '.join(map(str, ans)))    