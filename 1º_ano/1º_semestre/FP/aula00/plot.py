# Try running this program.
# Then change it to generate another subplot with the product of y1 and y2.

import numpy as np
import matplotlib.pyplot as plt

plt.figure(3)

t = np.arange(0.0, 5.0, 0.1)  # try printing t
#print(t)
plt.subplot(2, 2, 1)
y1 = np.exp(-t)
plt.plot(t, y1, 'b')  # try 'g' or 'bo' or 'k+'

plt.subplot(2, 2, 2)
y2 = np.cos(2*np.pi*t)
plt.plot(t, y2, 'ro-')

plt.subplot(2,1,2)
y3 = y2 * y1
plt.plot(t, y3, 'go-')
plt.show()

#(x,y, numero onde fica o grafico)

#por exemplo x = 2 e y =2 cria uma caixa 2 por 2 e o 3o
#  argumento é onde fica o graf 