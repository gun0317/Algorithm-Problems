def solution(record):
    temp = []
    forever = []

    for record_atom in record:
        splited = record_atom.split()
        order = splited[0]
        if order == "RECEIVE":
            mail_addr = splited[1]
            temp.append(mail_addr)
        elif order == "DELETE":
            if len(temp)>0:
                temp.pop(-1)
        elif order == "SAVE":
            for t in temp:
                forever.append(t)
            temp.clear()

    return forever

r = ["RECEIVE abcd@naver.com", "RECEIVE zzkn@naver.com", "DELETE", "RECEIVE qwerty@naver.com", "SAVE", "RECEIVE QwerTY@naver.com"]
print(solution(r))

