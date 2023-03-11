import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation


plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
input_txt = "D:\Courses\ComputerPhysics\homework_11\DBM_eta0.5.txt"
x = []
y = []

f = open(input_txt)
for line in f:
    line = line.strip('\n')
    # line = line.split('\t')
    line = line.split(',')
    x.append(float(line[0]))  # 读取x
    y.append(float(line[1]))  # 读取y

plt.figure(figsize=(6, 6))
# plt.grid()  # 生成网格
plt.scatter(x, y, marker="o", c='blue', s=15, label="散点")
plt.xlim(20,140)
plt.ylim(20,140)
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("DBM Result")
plt.savefig("DBM_eta0.5.png")
plt.show()


