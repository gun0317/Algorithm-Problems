nm = input()
n = int(nm.split()[0])
m = int(nm.split()[1])
toPrint = 1
for i in range(n):
    for j in range(m):
        print(toPrint,end=' ')
        toPrint += 1
    print()
