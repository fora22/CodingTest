def getNumTime(time):
    return int(time[:2]) * 60 + int(time[3:]) # int형으로 시간을 바꿈

def task_processing(time):
    numTime = getNumTime(time) + 10  # 10분동안 업무처리

    return numTime

def solution(booked, unbooked):
    # booked 와 unbooked 의 길이는 1 이상이므로 최소 2명의 손님은 무조건 오게됨
    answer = []    

    # booked 와 unbooked 사이에서 가장 빠르게 도착한 손님 구하기
    if getNumTime(booked[0][0]) <= getNumTime(unbooked[0][0]):
        task = booked[0]
        booked.pop(0)
    else:
        task = unbooked[0]
        unbooked.pop(0)
    answer.append(task[1])  # 먼저 도착한 손님 update

    while (len(booked) + len(unbooked)) != 0:   # queue 가 비어있다면 break
        taskEndTime = task_processing(task[0])  # 첫 손님의 업무 처리 후 시간 구하기
        if len(booked) != 0 and taskEndTime >= getNumTime(booked[0][0]):     # 예약 손님 중에 업무처리가 가능하다면 예약 손님 처리
            task = booked[0]
            booked.pop(0)
        else:                               # 이외일 경우 예약 안된 손님 처리
            task = unbooked[0]
            unbooked.pop(0)
        answer.append(task[1])  # 다음 손님 update
        
    return answer


b = [
    [["09:10", "lee"]]	, 
    [["09:55", "hae"], ["10:05", "jee"]],
    [["09:10", "lee"], ["09:20", 'b']],
    [["09:11", "lee"], ["09:12", "a"],["09:14", "b"],["09:16", "c"]]
]
ub = [
    [["09:00", "kim"], ["09:05", "bae"]],
	[["10:04", "hee"], ["14:07", "eom"]],
    [["09:00", "kim"], ["09:05", "bae"], ["09:15", "a"]],
    [["09:10", "kim"], ["09:13", "aa"],["09:15", "bb"],["09:17", "cc"]]
]

for i in range(len(b)):
    solution(b[i], ub[i])
