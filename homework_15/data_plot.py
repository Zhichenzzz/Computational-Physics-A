import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
input_txt = "beta=1.0_00.txt"
# input_txt = "results_N_error_2.txt"

x = []
y = []
z = []
f = open(input_txt)
for line in f:
    line = line.strip('\n')
    # line = line.split('\t')
    line = line.split(',')
    x.append(float(line[0]))  # 读取x
    y.append(float(line[1]))  # 读取y
    # z.append(float(line[2]))  # 读取z
ax = plt.figure().add_subplot(111, projection='3d')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

ax.scatter(x, y, 55, c='b', s=1, marker='^')
X = np.arange(-4, 4, 0.05)
Y = np.arange(-4, 4, 0.05)  # 前两个参数为自变量取值范围
X, Y = np.meshgrid(X, Y)

Z = np.exp(2*(X * X + Y * Y) - 0.5*(X**4+Y**4)-0.5*(X-Y)**4) # z关于x,y的函数关系式,此处为锥面
ax.plot_surface(X, Y, Z, cmap='rainbow')
plt.title("Boltzmann && Markov")  # 数字与cpp文件对应
plt.show()

# plt.figure(figsize=(6, 6))
# # plt.grid()  # 生成网格
# plt.scatter(0,0,color="red",label="Beginning")
#
# plt.plot(x, y, c='blue',label="Markov dot")
# # plt.plot(x, z, c='red',label="γ-Efficiency")
# # plt.ylim(0,1.0)
# # plt.ylim(20,140)
# plt.xlabel("x")
# plt.ylabel("y")
# plt.legend()
# plt.title("Markov Chain(β=0.2)")
# plt.savefig("Markov Chain(β=0.2)00.png")
# plt.show()
