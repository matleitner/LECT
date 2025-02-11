import json


def table(lst):
    print(f"{'Number':>6s}  {'Name':6}  {'Group':6s}  {'Grade':>6s}")
    for num, grade, name, group in lst:
        print(f"{num:6d}  {name:<6.6s}  {group:6s}  {grade:6.1f}")
    print()


def main():
    # Load data from json file
    with open("grades.json") as f:
        lst1 = json.load(f)

    print("Each element in lst1 contains [Number, Grade, Name, Group] fields.")
    print(f"For example {lst1[0] = }.", end="\n\n")

    # Print the data
    print("lst1")
    table(lst1)

    # Sort lst1 by order of decreasing GRADE
    lst2 = sorted(lst1 , key = lambda reg: reg[1],reverse=True)

    print("lst2")
    table(lst2)

    # Sort lst2 by order of increasing GROUP
    lst3 = sorted(lst2, key = lambda reg: reg[3])
    
    print("lst3")
    table(lst3)


if __name__ == '__main__':
    main()
