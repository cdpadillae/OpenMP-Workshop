import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#def f(x):
#    return x
data = pd.read_csv('data_integral.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

xtheo = np.linspace(0,16,16)
x = data[0]
y = 0.0209906/(data[1]*x)
plt.xlabel("n threads")
plt.ylabel("Parallel Efficiency")
plt.title("Parallel Efficiency for Integral Calculation-Computer with 16 cores")

plt.plot(x, y,'r')
#plt.plot(xtheo,f(xtheo))
plt.legend(["Exp N=10000000"])
plt.show()
