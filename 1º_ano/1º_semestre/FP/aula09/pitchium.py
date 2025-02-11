words = {}

print(ord('z'))



with open('wordlist.txt','r', encoding='utf8') as f:
    for line in f:
        words[(line[0])]=line.strip('\n')
        
    print(words)