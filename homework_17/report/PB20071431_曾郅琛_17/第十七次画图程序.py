import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation


# plt.rcParams['font.sans-serif'] = ['SimHei']
# plt.rcParams['axes.unicode_minus'] = False
input_txt = "DLA_10000.txt"

x = []
y = []

f = open(input_txt)

for line in f:
    line = line.strip('\n')
    # line = line.split('\t')
    line = line.split(',')
    x.append(int((line[0])))  # 读取x
    y.append(int((line[1])))  # 读取y
plt.figure(figsize=(8, 8))
# plt.grid()  # 生成网格
plt.scatter(x, y, marker="o", c='blue', s=2, label="散点")
# plt.xlim(20,140)
# plt.ylim(20,140)
plt.xlabel("x")
plt.ylabel("y")
# plt.legend()
plt.title("DLA")
plt.savefig("DLA.png")
plt.show()


