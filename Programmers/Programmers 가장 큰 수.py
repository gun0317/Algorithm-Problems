def solution(numbers):
    answer = ''
    firsts = []
    idx = 0
    numbers.sort(reverse=True)
    for num in numbers:
        numLen = len(str(num))
        first = num // (10 ** (numLen - 1))
        firsts.append([first, numLen, num, idx])
        idx += 1

    #firsts.sort(key=lambda firsts: firsts[1])
    firsts.sort(key=lambda firsts: firsts[0], reverse=True)
    print(firsts)
    for atom in firsts:
        answer += str(numbers[atom[3]])

    return answer


print(solution([3, 30, 34, 15, 9]))
