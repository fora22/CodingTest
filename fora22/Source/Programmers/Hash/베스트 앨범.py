'''
Hash 문제
'''
def solution(genres, plays):
    hash_map = {}
    idx = 0
    for gg, pp in zip(genres, plays):
        if gg not in hash_map:
            hash_map[gg] = [(idx, pp)]
        else:
            hash_map[gg].append((idx, pp))
        idx += 1

    prio_genre = []
    for g in hash_map:
        all_plays = 0
        for _, p in hash_map[g]:
            all_plays += p
        prio_genre.append((g, all_plays))

    answer = []
    prio_genre.sort(key=lambda x: -x[1])
    for g, p in prio_genre:
        if len(hash_map[g]) > 1:
            hash_map[g].sort(key=lambda x: (-x[1], x[0]))    
            answer.append(hash_map[g][0][0])
            answer.append(hash_map[g][1][0])
        else:
            answer.append(hash_map[g][0][0])
    
    return answer

def solution2(genres, plays):
    answer = []
    dic = {}
    album_list = []
    for i in range(len(genres)):
        dic[genres[i]] = dic.get(genres[i], 0) + plays[i]
        album_list.append(album(genres[i], plays[i], i))

    dic = sorted(dic.items(), key=lambda dic:dic[1], reverse=True)
    album_list = sorted(album_list, reverse=True)



    while len(dic) > 0:
        play_genre = dic.pop(0)
        print(play_genre)
        cnt = 0
        for ab in album_list:
            if play_genre[0] == ab.genre:
                answer.append(ab.track)
                cnt += 1
            if cnt == 2:
                break

    return answer

class album:
    def __init__(self, genre, play, track):
        self.genre = genre
        self.play = play
        self.track = track

    def __lt__(self, other):
        return self.play < other.play
    def __le__(self, other):
        return self.play <= other.play
    def __gt__(self, other):
        return self.play > other.play
    def __ge__(self, other):
        return self.play >= other.play
    def __eq__(self, other):
        return self.play == other.play
    def __ne__(self, other):
        return self.play != other.play


g = ["classic", "pop", "classic", "classic", "pop"]

p = [500, 600, 150, 800, 2500]

print(solution2(g, p))