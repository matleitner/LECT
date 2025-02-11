"""
Simple program to find the week day for a date.

Formulas & program by
jmr@ua.pt, 2013-09-23 (monday)
"""

# Constant tables for date computations
DAYS_UNTIL_MONTH = (0, 31, 61, 92, 122, 153, 184, 214, 245, 275, 306, 337)
WEEKDAY = ("Sab", "Dom", "Seg", "Ter", "Qua", "Qui", "Sex")


# y, m, d;  // ano, mes, dia (representados por numeros)
# yc, mc;   // ano corrigido e mes corrigido (auxiliares do calculo)
# jd;       // dia "juliano" calculado = num dias desde uma data de referencia
# wd;       // numero do dia da semana 0=Sab, 1=Dom, etc.

date = input("Data (aaaa mm dd)? ").split()
y = int(date[0])
m = int(date[1])
d = int(date[2])

if m < 3:
    yc = y - 1
    mc = m + 12 - 3
else:
    yc = y
    mc = m - 3

jd = 365*yc + yc//4 - yc//100 + yc//400 + DAYS_UNTIL_MONTH[mc] + d

wd = (jd + 3)%7

print("{:4d}-{:02d}-{:02d}: {:s}\n".format(y, m, d, WEEKDAY[wd]))

