def hondt(votes, numseats):
    lugar = [0]*len(votes)
    while numseats>0:
        for k in range(len(votes)):
            for p in range(len(votes)):
                if votes[k] != votes[p]: 
                    numseats-=1
                    maximo=0
                    for i in range(len(votes)):
                        if votes[i]>maximo:
                            maximo=votes[i]
                            index=i
                        lugar[index]+=1
                    q=votes[index]/(lugar[index]+1)
                    votes[index]=q
                else:
                    numseats -=1
                    if lugar[p]<lugar[k]:
                        lugar[p]+=1
                        q=votes[p]/(lugar[p]+1)
                        votes[p]=q
                    
                    
                    else:
                        lugar[k]+=1
                        q=votes[k]/(lugar[k]+1)
                        votes[k]=q
                    
    return lugar       


print(hondt([7000, 6000, 12000], 5))