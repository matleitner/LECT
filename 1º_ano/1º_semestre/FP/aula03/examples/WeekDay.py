"""
Simple program to find the week day for a date.

Formulas & program by
jmr@ua.pt, 2013-09-23 (monday)
"""

# Days since latest month zero (March) until beginning of current month
#                   Mar  Apr  May  Jun  Jul  Aug  Sep  Oct  Nov  Dec  Jan  Feb
#              m =    0    1    2    3    4    5    6    7    8    9   10   11
DAYS_UNTIL_MONTH = (  0,  31,  61,  92, 122, 153, 184, 214, 245, 275, 306, 337)
# DAYS_UNTIL_MONTH[m] == (153*m + 2)//5

def julianDay(y, m, d):
    """Return the Julian day number for (y, m, d)."""
    assert y >= 0
    assert 1 <= m <= 12

    # yc, mc: ano corrigido e mes corrigido (auxiliares do cálculo)
    if m < 3:
        yc = y - 1
        mc = m + 12 - 3
    else:
        yc = y
        mc = m - 3

    # jd: data juliana calculada = num dias desde uma data de referência
    jd = 365*yc + yc//4 - yc//100 + yc//400
    jd += DAYS_UNTIL_MONTH[mc] + d

    return jd


WEEKDAY = ("Sab", "Dom", "Seg", "Ter", "Qua", "Qui", "Sex")

def weekDay(y, m, d):
    jd = julianDay(y, m, d)
    # wd: numero do dia da semana 0=Sab, 1=Dom, etc.
    wd = (jd + 3)%7
    return WEEKDAY[wd]


def inputYMD(msg):
    """Ask for and return a date."""
    date = input(msg).split()
    y = int(date[0])
    m = int(date[1])
    d = int(date[2])
    return y, m, d
    

def main():
    # y, m, d: ano, mes, dia (representados por numeros)
    y, m, d = inputYMD("Data (aaaa mm dd)? ")
    print("{:4d}-{:02d}-{:02d}: {:s}\n".format(y, m, d, weekDay(y, m, d)))
    print(julianDay(y, m, d))


main()

