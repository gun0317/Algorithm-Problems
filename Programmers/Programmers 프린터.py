def solution(priorities, location):
    answer = 0
    pOnly = priorities[:]
    pOnly.sort()
    pOnly.reverse()

    idx = 0
    pANDloc = []
    for p in priorities:
        pANDloc.append([p,idx])
        idx += 1

    while True:
        if pOnly[0] is pANDloc[0][0]:
            answer += 1
            if pANDloc[0][0] is priorities[location] and pANDloc[0][1] is location:
                return answer
            pANDloc.pop(0)
            pOnly.pop(0)
        else:
            pANDloc.append(pANDloc[0])
            pANDloc.pop(0)


    return answer

p = [2,1,3,2]
l = 2
print(solution(p,l))