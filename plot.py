import pandas as pd
data = pd.read_csv('raw_data_time.txt',sep='\s+',header=None)
data = pd.DataFrame(data)

import matplotlib.pyplot as plt
x = data[0]
y = 4.372632130980492e-03/data[2]
plt.plot(x, y,'r--')
plt.show()
