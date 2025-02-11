# 

def hondt(votes, numseats):
   lugar = [0]*len(votes)
   while numseats>0:
        numseats-=1
        maximo=0
        for i in range(len(votes)):
            if votes[i]>maximo:
                maximo=votes[i]

        for i in range(len(votes)):
            for j in range(1, len(votes)):
                if votes[i] == votes[j]:
                    if lugar[i] < lugar[j]:
                        lugar[i] += 1
                        q=votes[i]/(lugar[i]+1)
                        votes[i]=q
                else: 
                    q=votes[i]/(lugar[i]+1)
                    votes[i]=q
                    lugar[i] += 1
        print(votes)
   return lugar       


print(hondt([7000, 6000, 12000], 5))