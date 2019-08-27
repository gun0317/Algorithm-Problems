import heapq as pq

def solution(operations):
    answer = [0,0]
    minH = []

    for op in operations:
        order = op.split()[0]
        num = int(op.split()[1])
        print(order, " ", num)
        if order is 'I':
            # insertion
            pq.heappush(minH,num)
        elif order is 'D':
            if len(minH) is 0:
                continue
            if num is 1:
                # max del
                maxSorted = sorted(minH,reverse=True)
                minH.pop()
                pq.heapify(minH)
            if num is -1:
                # min del
                pq.heappop(minH)

    if len(minH) is not 0:
        answer[1] = minH[0]
        minH.sort(reverse=True)
        answer[0] = minH[0]

    return answer

o = ["I 7", "I 5", "I -5", "D -1"]
print(solution(o))