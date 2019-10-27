import operator

def solution(genres, plays):
    answer = []
    plays_per_genres = {}
    ranking_in_genres = {}
    for g in genres:
        ranking_in_genres[g] = []
        plays_per_genres[g] = 0
    
    for i in range(len(genres)):
        plays_per_genres[genres[i]] += plays[i]
        ranking_in_genres[genres[i]].append([i,plays[i]])

    sorted_genres = sorted(plays_per_genres.items(), key=operator.itemgetter(1), reverse=True)
    #sorted_ ranking_in_genres 이거 조회수대로 정렬하고
    
    for genre in ranking_in_genres:
        local_ranking = sorted(ranking_in_genres[genre], key=operator.itemgetter(1),reverse=True)
        ranking_in_genres[genre] = local_ranking
    
    print(sorted_genres)
    print(ranking_in_genres)
    
    for genre in sorted_genres:
        stopper = 0
        for song in ranking_in_genres[genre[0]]:
            if stopper == 2:
                break
            answer.append(song[0])
            stopper+=1
        
                
    
    return answer

g = ['classic', 'pop', 'classic', 'classic', 'pop']
p = [500, 600, 150, 800, 2500]
print(solution(g,p))
