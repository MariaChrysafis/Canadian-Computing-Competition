n = int(input())
arr = []
for i in range(0, n) :
    arr.append(int(input()))
arr.sort()
tot = []
for i in range(1, n - 1) :
    tot.append((arr[i] + arr[i - 1])/2 - (arr[i] + arr[i + 1])/2)
print(-max(tot))
