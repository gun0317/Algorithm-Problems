import heapq as pq


def solution(scoville, K):
    answer = 0
    pq.heapify(scoville)
    while True:
        if scoville[0] < K and len(scoville) > 1:
            a = pq.heappop(scoville)
            b = pq.heappop(scoville)
            pq.heappush(scoville, a + 2 * b)
            answer += 1
        elif scoville[0] < K and len(scoville) == 1:
            return -1
        elif scoville[0] >= K:
            return answer


s = [1, 2, 3, 8, 10, 12]
k = 7
print(solution(s, k))
