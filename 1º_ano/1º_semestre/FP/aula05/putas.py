numseats = 6
votes = [15300, 12000, 6600, 5100]

lugares = []
for i in range(len(votes)):
    lugares.append(0)
for i in range(numseats):
    if votes[i]== max(votes):
        index = i
    q = max(votes)//(lugares[index]+1)
        
    votes[index]= q
    lugares[index]+=1

    print("q:",q)
    print("index",index)
    print("numseats",numseats)
    print("votes",votes)
    print(lugares)
    print("\n")