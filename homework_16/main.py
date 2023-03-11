import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation


# plt.rcParams['font.sans-serif'] = ['SimHei']
# plt.rcParams['axes.unicode_minus'] = False
# input_txt = "beta=1.0_00.txt"

def Function(k, x):
    x = k * math.sin(math.pi * x)
    return x


plt.xlabel('λ')
plt.ylabel('x(n)')
plt.title("Period Doubling Bifurcation")
# plt.xlim(-1.0, 1.0)
# plt.ylim(-1.0, 1.0)

N = 1000
M = 10000

for n in range(-N, N):
    y = [0.01]
    for m in range(0, M):
        y1 = Function(n / N, y[m])
        y.append(y1)
    x = np.linspace(n / N, n / N, M + 1)
    plt.scatter(x, y, s=0.002)


plt.savefig("Period Doubling Bifurcation_+-.png")
plt.show()
