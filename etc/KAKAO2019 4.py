import re


def solution(words, queries):
    answer = []
    length = {}
    for w in words:
        length[w] = len(w)

    for q in queries:
        patt = ""
        localAns = 0
        regLen = len(q)
        for char in q:
            if char == "?":
                patt += '.'
            else:
                patt += char
        reg = re.compile(patt)
        for w, l in length.items():
            if regLen == l:
                if reg.search(w):
                    localAns += 1
        answer.append(localAns)

    return answer


w = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
q = ["fro??", "????o", "fr???", "fro???", "pro?"]
print(solution(w, q))
