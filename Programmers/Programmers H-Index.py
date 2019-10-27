def solution(citations):
    citations.sort()
    n = len(citations)

    for i in range(n,-1,-1):
        if 0<=n-i<=n-1:
            if citations[n-i]>=i:
                return i
    
    return 0
    

c = [3,0,1,6,5]
print(solution(c))
