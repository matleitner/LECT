
def parseMDY(date):
    """Return (year, month, day) from date in MM/DD/YYYY format."""
    data = date.split('/')
    if len(data)==1:
        return (int(data[0]),0,0)
    else:
        return (int(data[2]), int(data[0]), int(data[1]))


def yearsBetween(date1, date2):
    """Return integer number of years between two (y, m, d) dates."""
    if date1>date2:
        return date1[0]-date2[0]
    else:
        return date2[0]-date1[0]


def main():
    # Test parseMDY
    print(f"{parseMDY('12/25/2024') = }")  # (2024, 12, 25)
    print(f"{parseMDY('4/25/1974') = }")   # (1974, 4, 25)
    print(f"{parseMDY('1755') = }")        # (1755, 0, 0)

    # Test yearsBetween
    print(f"{yearsBetween((1900, 6, 1), (1935, 5, 31)) = }")  # 34
    print(f"{yearsBetween((1900, 6, 1), (1935, 6, 1)) = }")   # 35
    print(f"{yearsBetween((1900, 6, 1), (1936, 5, 31)) = }")  # 35


# This program may be used as a module too
if __name__ == "__main__":
    main()

