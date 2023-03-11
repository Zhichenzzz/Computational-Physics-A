import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation  # 动图的核心函数
import seaborn as sns  # 美化图形的一个绘图包
from matplotlib import animation

sns.set_style('darkgrid')  # 设置图形主图

# 创建画布
# fig, ax = plt.subplots()
# fig.set_tight_layout(True)


input_txt = "DLA_10000.txt"
x = []
y = []

f = open(input_txt)
for line in f:
    line = line.strip('\n')
    # line = line.split('\t')
    line = line.split(',')
    x.append(float(line[0]))  # 读取x
    y.append(float(line[1]))  # 读取y
fig = plt.figure(figsize=(6, 6))

ax = fig.add_subplot()

# 按照二维的思路，生成新数据，画三维图

point, = ax.plot([], [], 'b.', markersize=5)
point2, = ax.plot([], [], 'b.', markersize=5)
ax.set_xlim([-120, 120])
ax.set_ylim([-120, 120])


# 画gif动图
def update_point(n, x, y, point):
    point2.set_data([x[0:n], y[0:n]])
    point.set_data([x[n], y[n]])
    # point.set_array([255,0,0])
    ax.set_title('DLA')

    return point


ani = animation.FuncAnimation(fig, update_point, 10000, fargs=(x, y, point), interval=20)
# ax.set_xlable("x")
ani.save('DLA.gif', writer='pillow')
plt.show()
