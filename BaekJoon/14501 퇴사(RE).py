N = int(input())

durations = [0]
prices = [0]
ans = 0

for i in range(N):
    t, p = map(int, input().split())
    durations.append(t)
    prices.append(p)


def back(curDay, curPrice):
    global ans
    for day in range(curDay, N+1):
        nextDay = day + durations[day]
        if nextDay <= N + 1:
            nextPrice = curPrice + prices[day]
            if ans < nextPrice:
                ans = nextPrice
            back(nextDay, curPrice + prices[day])


back(1, 0)

print(ans)
