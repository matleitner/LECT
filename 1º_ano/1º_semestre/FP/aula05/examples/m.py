def maxNum(votes):
    a = 0
    for i in range(len(votes)):
                if votes[i]>a:
                    a=votes[i]
                    index=i
    return a, index
votes = [15300, 12000, 6600, 5100]
caralhos = [0,0,0,0]
g = 6
q=max(votes)
while g>0:
    max, index = maxNum(votes)
    votes[index]=q
    q = max/(caralhos[index]+1)
    print(max)
    print(index)
    caralhos[index]+=1
    g-=1
    print(votes)
    print(caralhos)
