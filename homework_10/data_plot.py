import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation

# plt.rcParams['font.sans-serif'] = ['SimHei']
# plt.rcParams['axes.unicode_minus'] = False
# input_txt = "./RW_xy_try.txt"
# x = [0]
# y = [0]
# t = [0]
# f = open(input_txt)
# for line in f:
#     line = line.strip('\n')
#     line = line.split(',')
#     x.append(float(line[0]))                    # 读取x
#     y.append(float(line[1]))                    # 读取y
#     t.append(float(line[2]))                    # 读取t
#
# ax = plt.figure().add_subplot(111, projection = '3d')
# ax.set_xlabel('x')
# ax.set_ylabel('y')
# ax.set_zlabel('Number of Times')
# ax.plot(x, y, t, c = 'b', marker = '+')
# plt.title("x,y关于t的随机游走三维图(walk=0.5)")
# # plt.savefig("x,y关于t的随机游走三维图walk=0.5.png")
# plt.show()
#
# plt.figure(figsize=(6, 6))
# plt.plot(t,x, c='blue',label="x-t")
# plt.plot(t,y, c='red',label="y-t")
# plt.xlabel("Number of Times")
# plt.ylabel("Coordinate")
# plt.legend()
# plt.title("x、y方向上的随机游走随t变化图(walk=0.5)")
# # plt.savefig("x、y方向上的随机游走随t变化图walk=0.5.png")
# plt.show()
#
# plt.figure(figsize=(6, 6))
# plt.grid()  # 生成网格
# plt.scatter(0,0,marker="o", c='red',s=30,label="出发点")
# plt.plot(x,y,marker='+',c='blue')
#
# plt.xlabel("x")
# plt.ylabel("y")
# plt.legend()
# plt.title("带电粒子随机游走轨迹图(walk=0.5)")
# # plt.savefig("带电粒子随机游走轨迹图walk=0.5.png")
# plt.show()


# input_txt = "./RW_Cv_try.txt"
# x = []
# t = []
# f = open(input_txt)
# for line in f:
#     line = line.strip('\n')
#     line = line.split(',')
#     t.append(float(line[0]))  # 读取x
#     x.append(float(line[1]))  # 读取y
#
# plt.figure(figsize=(6, 6))
# # plt.grid()  # 生成网格
# plt.scatter(t, x, marker="o", s=2, c='red', label="Experimentally")
# x1 = np.arange(0, 1000, 1)
# y1 = []
# for t in x1:
#     y_1 = 2 / 3 * math.exp(-0.25 * t)
#     y1.append(y_1)
# plt.plot(x1, y1, label="Theoretically", c="blue")
# plt.xlabel("time")
# plt.ylabel("C(t)")
# plt.xlim(0, 200)
# # plt.yticks([0.0,0.2,0.4,0.6,0.67,0.8,1.0])
# plt.legend()
# plt.title("速度自相关函数C(t)关于时间t的理论和模拟图")
# plt.savefig("C(t)_粘滞0.25.png")
# plt.show()
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
input_txt = "C:\\Users\\HUAWEI\\Desktop\\sb.txt"
x = []
y = []
t = [0]
f = open(input_txt)
for line in f:
    line = line.strip('\n')
    line = line.split(',')
    x.append(float(line[0]))                    # 读取x
    y.append(float(line[1]))                    # 读取y
    # t.append(float(line[2]))                    # 读取t



plt.figure(figsize=(6, 6))
plt.grid()  # 生成网格
plt.scatter(x,y,marker="o", c='blue',s=20,label="散点")


plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Diffusion Limited Aggregation Result (2000)")
# plt.savefig("Diffusion Limited Aggregation Result (2000).png")
plt.show()