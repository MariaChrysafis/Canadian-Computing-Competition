s = str(input())
v = [1, 2, 3, 4]
for c in s:
    if c == 'V':
        v[0], v[1] = v[1], v[0]
        v[2], v[3] = v[3], v[2]
    else:
        v[0], v[2] = v[2], v[0]
        v[1], v[3] = v[3], v[1]
print(v[0], v[1])
print(v[2], v[3])
