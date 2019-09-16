nm = input()
n = int(nm.split()[0])
m = int(nm.split()[1])

if n<0 or n%2 == 0 or m<0 or m>3:
    print("INPUT ERROR!")
else:
    if m == 1:
        even = 0
        toPrint = 0
        for r in range(1,1+n):
            if even == 0:
                for i in range(r):
                    toPrint += 1
                    print(toPrint,end=' ')
                even = 1
            else:
                toPrint += r+1
                for i in range(r):
                    toPrint -= 1
                    print(toPrint,end=' ')
                even = 0
                toPrint += r - 1
            print()

    if m == 2:
        for r in range(n):
            for sp in range(r):
                print(' ',end=' ')
            for digits in range((n-r)*2-1):
                print(r,end=' ')
            print()

    if m == 3:
        mid = n//2 + 1
        for r in range(1, mid+1):
            toPrint = 1
            for digits in range(r):
                print(toPrint,end=' ')
                toPrint += 1
            print()
        for r in range(1, mid):
            toPrint = 1
            for digits in range(mid - r):
                print(toPrint, end=' ')
                toPrint += 1
            print()
