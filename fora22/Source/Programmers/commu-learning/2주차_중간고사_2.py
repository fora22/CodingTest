from collections import Counter

def solution(people, tshirts):
    p_cnt = Counter(people); ts_cnt = Counter(tshirts)
        
    notGetClothesPeople = sorted((p_cnt - ts_cnt).elements(), reverse=True)  # 옷을 못받은 사람들
    extraClothes = ts_cnt - p_cnt           # 여분의 옷
    cnt = len(people) - len(notGetClothesPeople)   

    for p in notGetClothesPeople:
        if len(extraClothes) == 0:
            break
        clothesNum = max(extraClothes)      # 제일 큰 사이즈의 옷 사이즈 구함
        if p in list(range(clothesNum)):    # 참가자 사이즈가 옷사이즈보다 작을 경우
            cnt += 1
            extraClothes = extraClothes - Counter({clothesNum: 1})


    answer = cnt
    return answer

p = [[2, 3], [1,2,3], [3,3,3,3]]
t = [[1,2,3], [1,1], [4,4,4]]

for i in range(len(p)):
    print(solution(p[i], t[i]))