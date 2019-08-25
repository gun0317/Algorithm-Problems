def solution(clothes):
    answer = 1
    dic = {}
    for atom in clothes:
        if dic.get(atom[1]) is None:
            dic[atom[1]] = 2
        else:
            dic[atom[1]] += 1

    for val in dic.values():
        answer *= val

    return answer-1


cloth = [["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]
print(solution(cloth))