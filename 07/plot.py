import matplotlib.pyplot as plt
import numpy as np
from shutil import copyfile
from math import sin, cos

data = np.loadtxt("data", delimiter=",")
points = data[::]

xs = data[:, 0]
ys = data[:, 1]

plt.scatter(xs, ys, s=0.5)
plt.xlabel('w')
plt.ylabel('step(s)')
plt.show()



