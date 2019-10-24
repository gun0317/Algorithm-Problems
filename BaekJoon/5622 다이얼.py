input_str = input()
dial = []
for char in input_str:
    if 'A'<=char<='C':
        dial.append(2)
    elif 'D'<=char<='F':
        dial.append(3)
    elif 'G'<=char<='I':
        dial.append(4)
    elif 'J'<=char<='L':
        dial.append(5)
    elif 'M'<=char<='O':
        dial.append(6)
    elif 'P'<=char<='S':
        dial.append(7)
    elif 'T'<=char<='V':
        dial.append(8)
    elif 'W'<=char<='Z':
        dial.append(9)
print(sum(dial)+len(dial))
