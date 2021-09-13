import os
import sys
dirName = os.path.dirname(os.path.abspath(__file__))
sys.stdin = open(os.path.abspath(dirName + "/input.txt"), 'r')

N = int(input())
cards = []
for i in range(N):
    cards.append(int(input()))
print(cards)

count = cards[0]

lenCards = len(cards)

for i in range(1, lenCards):
    if i != (lenCards-1):
        count += cards[i]
        count *= 2
    else:
        count += cards[i]

print(count)



