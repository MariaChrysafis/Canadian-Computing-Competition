n = int(input())
x = []
y = []
for i in range(0, n) :
    s = input().split(',')
    x.append(int(s[0]))
    y.append(int(s[1]))
print(str(min(x) - 1) + ',' + str(min(y) - 1))
print(str(max(x) + 1) + ',' + str(max(y) + 1))

