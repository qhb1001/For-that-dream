s = input() + '2'
t = s.replace('1', '')
i = t.find('2') # if there doesn't exist '2', it returns -1
print (t[:i] + '1' * s.count('1') + t[i: -1])