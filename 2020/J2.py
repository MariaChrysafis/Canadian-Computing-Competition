p = int(input())
n = int(input())
r = int(input())
i = 0
while True :
    if r == 1:
        if (i + 1) * n > p :
            print(i)
            break
    elif n * (pow(r, i + 1) - 1)/(r - 1) > p :
        print(i)
        break
    i += 1
