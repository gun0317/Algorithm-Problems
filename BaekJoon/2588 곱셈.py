
def list_appending(num, lst):
    lst.append(num%10)
    lst.append(num//10-num//100*10)
    lst.append(num//100)
    
    return lst


A = int(input())
B = int(input())
a_list = []
a_list = list_appending(A,a_list)
b_list = []
b_list = list_appending(B,b_list)
ans = []

for b in b_list:
    local = 0
    pos = 1
    for a in a_list:
        local += pos*a*b
        pos *= 10
    ans.append(local)

pos = 1
ans_fin = 0
for val in ans:
    print(val)
    ans_fin += val*pos
    pos*=10

print(ans_fin)
