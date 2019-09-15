def isCorrect(p):
    # isCorrect?
    stk = []
    idx = 1
    correctSoFar = 0
    for char in p:
        if len(stk) > 0:
            if stk[-1] == '(' and char == ')':
                stk.pop()
            elif char == '(':
                stk.append(char)
            elif stk[-1] == ')':
                break
        elif len(stk) == 0:
            if char == '(':
                stk.append(char)
            else:
                break
        if len(stk) == 0:
            correctSoFar = idx
        idx += 1

    return correctSoFar


def balancedIdx(p):
    left = 0
    right = 0
    balanced = 0
    for char in p:
        if char == '(':
            left += 1
        elif char == ')':
            right += 1
        balanced += 1
        if left == right:
            return balanced


def fun(p, balIdx):
    if p == "":
        return p
    ans = ""
    balIdx = balancedIdx(p)
    u = p[0:balIdx]
    v = p[balIdx:]
    if isCorrect(u) == len(u):
        # TODO
        p = v
        ans += u
        ans += fun(v, balIdx)
        return ans
    else:
        ans = "("
        ans += fun(v, balIdx)
        ans += ')'
        u = u[1:-1]
        newU = ""
        for c in u:
            if c == '(':
                newU += ')'
            else:
                newU += '('
        ans += newU
        return ans


def solution(p):
    # Corner case: already correct p
    correctSoFar = isCorrect(p)
    if correctSoFar == len(p):
        return p
    # Ordinary case: p is balanced only
    answer = fun(p, 0)

    return answer


_p = "()))((()"
print(solution(_p))
