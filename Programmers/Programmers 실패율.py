def solution(N, stages):
    answer = []
    failrate = []
    cleared = [0] * (N + 1)
    arrived = [0] * (N + 2)
    for visit in stages:
        arrived[visit] += 1
    del arrived[0]
    Rarrived = reversed(arrived)
    sum = 0
    idx = N
    for a in Rarrived:
        sum += a
        cleared[idx] = sum
        idx -= 1
    print(arrived)
    print(cleared)

    for i in range(0, N):
        if cleared[i] == 0:
            failrate.append([i+1,0])
        else:
            failrate.append([i + 1, arrived[i] / cleared[i]])

    failrate.sort(key=lambda failrate: failrate[0], reverse=True)
    failrate.sort(key=lambda failrate: failrate[1])
    failrate.reverse()
    print(failrate)

    for f in failrate:
        answer.append(f[0])

    return answer


n = 5
s = [2, 1, 2, 6, 2, 4, 3, 3]
print(solution(n, s))
