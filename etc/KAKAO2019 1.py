def solution(s):
    answer = 1001
    l = len(s)
    if l is 1:
        return 1

    for subStrLen in range(1, l // 2 + 1):
        startIdx = 0
        localAns = 0
        while startIdx + subStrLen <= l:
            subStr = s[startIdx:startIdx+subStrLen]
            subStartIdx = startIdx
            subLocalAns = 0
            while subStartIdx + subStrLen <= l:
                subSubStr = s[subStartIdx:subStartIdx+subStrLen]
                if subStr == subSubStr:
                    subLocalAns += 1
                    subStartIdx += subStrLen
                else:
                    break
            startIdx = subStartIdx
            if subLocalAns == 1000:
                localLen = 4
            elif subLocalAns >= 100:
                localLen = 3
            elif subLocalAns >= 10:
                localLen = 2
            elif subLocalAns > 1:
                localLen = 1
            else:
                localLen = 0
            localAns += localLen + subStrLen
        localAns += l - startIdx
        if answer > localAns:
            answer = localAns

    return answer


_s = "xababcdcdababcdcd"
print(solution(_s))
