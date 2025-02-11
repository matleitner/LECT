def hondt(votes, numseats):
   lugar = [0]*len(votes)
   while numseats>0:
        for p in range(len(votes)):
            for l in range(1,len(votes)):
                if p  !=l and votes[p]!= votes[l]:
                    numseats-=1
                    maximo=0
                    for i in range(len(votes)):
                        if votes[i]>maximo:
                            maximo=votes[i]
                            index=i
                    lugar[index]+=1
                    q=votes[index]/(lugar[index]+1)
                    votes[index]=q
                elif p!=l and votes[p]!= votes[l]:
                    numseats-=1
                    if lugar[p]<lugar[l]:
                        lugar[p]+=1
                        q=votes[p]/(lugar[p]+1)
                        votes[p]=q

                    elif lugar[p]>lugar[l]:
                        lugar[l]+= 1
                        q=votes[l]/(lugar[l]+1)
                        votes[l]=q
                    
   return lugar       

