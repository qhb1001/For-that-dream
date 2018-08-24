n, k, s = map(int, input().split())
ans = []
idx = 1
flag = True

for i in range(1, k + 1):
    t = min(n - 1, s - (k - i))
    if t <= 0:
        flag = False
        break
    
    if idx + t <= n:
        idx += t
        ans.append(idx)
        s -= t
    else:
        idx -= t
        ans.append(idx)
        s -= t

if s != 0 or flag == False:
    print("NO")
else:
    print("YES")
    print(' '.join(map(str, ans)))