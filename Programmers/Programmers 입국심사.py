def solution(n, times):
    times.sort()
    left = 1
    right = times[0] * n
    answer = right
    while left <= right:
        mid = (left + right) // 2
        processed = 0
        for t in times:
            processed += mid // t
        if processed >= n:
            if answer > mid:
                answer = mid
            right = mid - 1
        elif processed < n:
            left = mid + 1

    return answer

nn = 5
t = [2,2]
print(solution(nn,t))