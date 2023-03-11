import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation

# plt.rcParams['font.sans-serif'] = ['SimHei']
# plt.rcParams['axes.unicode_minus'] = False
input_txt = "results_try_0.3_0.9.txt"
# input_txt = "results_N_error_2.txt"
x0 = [0.4942, 0.4942, 0.7852, 0.7852, 0.8452, 0.8452, 0.8626, 0.8626]
y0 = [0.5000, -0.5000, 0.5000, 0.7830, 0.5000, 0.4056, 0.5000, 0.5378]
x = []
y = []

t = np.linspace(0.3, 1.0, 50)
t1= np.linspace(-1.0,1.0,50)
z1 = 0 * t + 0.5
z2 = 0 * t1+0.4942
z3 = 0*t1+0.7852
z4 = 0*t1+0.8452
z5 = 0*t1+0.8626

f = open(input_txt)
for line in f:
    line = line.strip('\n')
    # line = line.split('\t')
    line = line.split(',')
    x.append(float(line[0]))  # 读取x
    y.append(float(line[1]))  # 读取y
    # z.append(float(line[2]))  # 读取z

plt.figure(figsize=(8, 8))
# plt.grid()  # 生成网格
plt.scatter(x, y, s=0.005)
plt.scatter(x0, y0, color="r")
# plt.plot(x, y, c='blue',label="Markov dot")
plt.plot(t, z1, c='red')
plt.plot(z2,t1, c='black')
plt.plot(z3, t1, c='black')
plt.plot(z4, t1, c='black')
plt.plot(z5, t1, c='black')
# plt.ylim(0.4,0.8)
# plt.ylim(20,140)
plt.xlabel("λ")
plt.ylabel("x(n)")
# plt.legend()
plt.title("Period Doubling Bifurcation")
plt.savefig("Period Doubling Bifurcation_try.png")
plt.show()
