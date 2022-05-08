'''
Hash 문제
참고
https://coding-grandpa.tistory.com/85
'''

################################################################################################
import collections
def solution2(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]
################################################################################################

def solution(participant, completion):
    dict_p = {}
    sumHash = 0

    # 참가자의 hash dictionary 만들기
    for p in participant:
        dict_p[hash(p)] = p
        sumHash += hash(p)

    for c in completion:
        sumHash -= hash(c)

    
    answer = dict_p[sumHash]
    return answer

from collections import Counter

def solution3(participant, completion):

    every_runner = collections.Counter(participant)
    run_over = collections.Counter(completion)
    every_runner.subtract(run_over)
    return next(every_runner.elements())



if __name__ == "__main__":
    p = [
        ["leo", "kiki", "eden"],
        ["marina", "josipa", "nikola", "vinko", "filipa"],
        ["mislav", "stanko", "mislav", "ana"]
        ]
    c = [
        ["eden", "kiki"],
        ["josipa", "filipa", "marina", "nikola"],
        ["stanko", "ana", "mislav"]
        ]

    result = solution3(p[0], c[0])
    print(result)
