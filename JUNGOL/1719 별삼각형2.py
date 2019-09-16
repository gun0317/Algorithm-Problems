nm = input()
n = int(nm.split()[0])
m = int(nm.split()[1])

if n % 2 == 0 or n <= 0 or n > 100 or m > 4 or m < 1:
    print("INPUT ERROR!")

else:
    if m == 1:
        for r in range(1, n // 2 + 1):
            for star in range(r):
                print('*', end='')
            print()
        for r in range(n // 2 + 1, 0, -1):
            for star in range(r):
                print('*', end='')
            print()

    if m == 2:
        mid = n // 2 + 1
        for r in range(mid - 1, -1, -1):
            for sp in range(r):
                print(' ', end='')
            for stars in range(mid - r):
                print('*', end='')
            print()
        for r in range(1, mid):
            for sp in range(r):
                print(' ', end='')
            for stars in range(mid - r):
                print('*', end='')
            print()

    if m == 3:
        for r in range(n // 2 + 1):
            for sp in range(r):
                print(' ', end='')
            for star in range(n - r * 2):
                print('*', end='')
            print()
        for r in range(n // 2 - 1, -1, -1):
            for sp in range(r):
                print(' ', end='')
            for star in range(n - r * 2):
                print('*', end='')
            print()

    if m == 4:
        mid = n // 2 + 1
        for row in range(mid):
            for sp in range(row):
                print(' ', end='')
            for stars in range(mid - row):
                print('*', end='')
            print()
        for row in range(mid - 1):
            for sp in range(mid - 1):
                print(' ', end='')
            for stars in range(row + 2):
                print('*', end='')
            print()
