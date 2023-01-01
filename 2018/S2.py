def rotate (m) :
    return list(list(x) for x in zip(*m))[::-1]

def okay (m) :
    for i in range(0, len(m)) :
        for j in range(0, len(m[0])) :
            if j + 1 != len(m) and m[i][j] > m[i][j + 1] :
                return False
            if i + 1 != len(m[0]) and m[i][j] > m[i + 1][j] :
                return False
    return True

n = int(input())
arr = []
for i in range(0, n) :
    arr.append(list(map(int, input().strip().split())))
while not okay(arr) :
    arr = rotate(arr)
for i in range(0, len(arr)) :
    print(' '.join(map(str,arr[i])))
