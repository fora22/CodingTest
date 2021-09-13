import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

stages = list(map(int, input().split()))
stages.sort()
print(stages)


import copy
testStages = copy.deepcopy(stages)

for st in range(1, max(stages) + 1):
    countStages = testStages.count(st)
    lenS = len(testStages)
    fail = countStages / lenS
    testStages.remove(st)
    print(testStages)    

