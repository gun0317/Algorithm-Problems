n = int(input())
if n > 100 or n % 2 == 0:
    print("INPUT ERROR!")

else:
    mid = n // 2 + 1
    toPrint = -1
    sp = -1
    for r in range(mid):
        toPrint += 2
        sp += 1
        for s in range(sp):
            print(' ', end='')
        for stars in range(toPrint):
            print('*', end='')
        print()
    for r in range(1, mid):
        toPrint -= 2
        sp -= 1
        for s in range(sp):
            print(' ',end='')
        for stars in range(toPrint):
            print('*',end='')
        print()
