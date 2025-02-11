def min (s : str):

    for i in range(1,len(s)):
        for d in range(i,len(s)):
            if d != i:
                for e in range(i-1,-1,-1):
                        print(i,d,e)
                        if s[i]==s[d]==s[e]:
                            s =s[:e]+s[e+1:d]+s[d+1:]
                            break
                        print("asd",end)
                            
                        
                        else:
                            print("ajuda")
    return min(s)


print("i,d,e")
print(min("anaas"))


