
def parseMDY(date):
    """Return (year, month, day) from date in MM/DD/YYYY format."""
    data = date.split('/')
    if len(data)==1:
        return (date,0,0)
    else:
        return (date[2])
print(parseMDY('12/25/2024'))
