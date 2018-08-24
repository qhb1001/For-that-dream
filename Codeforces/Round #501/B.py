n = int(input())
s = input()
t = input()

if sorted(s) != sorted(t):
    print(-1)
    exit()

if s == t:
    print(0)
    exit()

s_ = list(s)
ans = list()
for i, ele in enumerate(t, 1):
    ind = s_.index(ele)
    ans += range(i, i + ind)[::-1]
    del s_[ind]

print(len(ans))
print(' '.join(map(str, ans)))