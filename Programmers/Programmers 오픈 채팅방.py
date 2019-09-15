def solution(record):
    preAnswer = []
    answer = []
    users = {}

    for command in record:
        mystr = command.split()
        order = mystr[0]
        uid = mystr[1]
        if order == "Enter":
            users[uid] = mystr[2]
            preAnswer.append(uid+" in")
        if order == "Leave":
            preAnswer.append(uid+" out")
        if order == "Change":
            users[uid] = mystr[2]

    for line in preAnswer:
        mystr = line.split()
        uid = mystr[0]
        inout = mystr[1]
        if inout == "in":
            answer.append(users[uid]+"님이 들어왔습니다.")
        else:
            answer.append(users[uid] + "님이 나갔습니다.")


    return answer


r = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
print(solution(r))