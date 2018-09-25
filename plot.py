import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt('trajectory.dat', unpack=True)

plt.plot(data[0], data[2], 'r.-')
plt.show()


