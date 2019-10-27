import math

def solution(progresses, speeds):
    answer = []
    queue = 0
    days_left = []
    
    for i in range(len(progresses)):
        days_left_int = math.ceil((100-progresses[i])/speeds[i])
        days_left.append(days_left_int)
    print(days_left)
    cur = days_left[0]
    queue = 1
    for i in range(1,len(days_left)):
        print(cur,days_left[i])
        if cur >= days_left[i]:
            queue+=1
        elif cur < days_left[i]:
            answer.append(queue)
            queue = 1
            cur = days_left[i]
    answer.append(queue)

    
    

    
    
    return answer


p = [93,30,55]
s = [1,30,5]
print(solution(p,s))
