
def main():
    A = "reading"
    B = "eating"
    C = "traveling"
    D = "writing"
    E = "running"
    F = "music"
    G = "movies"
    H = "programming"

    interests = {
        "Marco": {A, D, E, F},
        "Anna": {E, A, G},
        "Maria": {G, D, E},
        "Paolo": {B, D, F},
        "Frank": {D, B, E, F, A},
        "Teresa": {F, H, C, D}
        }
    people = list(interests.keys())
    n_people= len(people)
    print("a) Table of common interests:")
    commoninterests = {(people[i], people[j]) : interests[people[i]] & interests[people[j]]
                                for i in range(n_people)
                                for j in range(1+i,n_people)}          

    print(commoninterests)

    print("b) Maximum number of common interests:")
    maxCI = ...
    print(maxCI)

    print("c) Pairs with maximum number of matching interests:")
    maxmatches = ...
    print(maxmatches)

    print("d) Pairs with low similarity:")
    lowJaccard = ...
    print(lowJaccard)


# Start program:
main()

