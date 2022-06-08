import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#def f(x):
 #   return x
data = pd.read_csv('data_accuracy.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

xtheo = np.linspace(0,16,16)
x = data[0]
y = data[6]
plt.xlabel("n threads")
plt.ylabel("Relative difference")
plt.title("Relative difference vs the number of threads (16 cores)")

plt.plot(x, y,'r')
#plt.plot(xtheo,f(xtheo))
plt.legend(["Exp N=12000 per thread"])
plt.show()
