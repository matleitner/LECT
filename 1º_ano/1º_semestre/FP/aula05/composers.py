# jmr 2024 o programa

import sys

# Add auxiliary functions here.
...


def load_lifetimes_file(file_name):
    """Load birth, death, name data from a file."""
    lst = []
    with open(file_name, 'r') as file:
        for line in file:
            # Strip spaces and newline from line
            line = line.strip()
            # Ignore empty lines and comments
            if line == "" or line[:1] == "#":
                continue  # skip to next line
            # Change this to split the line, parse dates
            # and store (date1, date2, name) tuple.
            separados = line.split('\t')
            line=(separados[0],separados[1],separados[2])
            lst.append(line)
    return lst


def main():
    file_name = 'composers.txt'  # Replace with your file name
    lifes = load_lifetimes_file(file_name)

    print("{:^75}".format('THE DEAD COMPOSERS SOCIETY'))
    print('{:^75}'.format("=========================="))
    print('{:^11s}{:^51s}{:>11s}'.format('Born in:','Died in:','Name:'))
    for info in lifes:
        # Change this to show Name, Age and Date-of-death in aligned columns.
        print('{:<11s}{:^50s}{:>11s}'.format(info[0],info[1],info[2]))


if __name__ == "__main__":
    main()

