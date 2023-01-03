t = int(input())
n = int(input())
arr1 = list(map(int, input().split(' ')))
arr2 = list(map(int, input().split(' ')))
arr1.sort()
arr2.sort()
if t == 2 :
    arr1.reverse()
ans = 0
for i in range(0, n) :
    ans += max(arr1[i], arr2[i])
print(ans)
