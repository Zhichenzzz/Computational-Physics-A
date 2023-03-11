import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
import pandas as pd
from matplotlib import rcParams
from matplotlib.animation import FuncAnimation

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False
input_txt = "results_gamma_error_accuracy_2.txt"
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
    z.append(float(line[2]))  # 读取z

plt.figure(figsize=(6, 6))
# plt.grid()  # 生成网格
plt.plot(x, y, c='blue',label="γ-Error")
plt.plot(x, z, c='red',label="γ-Efficiency")

# plt.ylim(0,1.0)
# plt.ylim(20,140)
plt.xlabel("γ")
plt.ylabel("Error/Efficiency")
plt.legend()
plt.title("γ—Error/Efficiency")
plt.savefig("results_gamma_ErrorEfficiency_try.png")
plt.show()

# for line in f:
#     line = line.strip('\n')
#     # line = line.split('\t')
#     line = line.split(',')
#     x.append(math.log(float(line[0])))  # 读取x
#     y.append(math.log(float(line[1])))  # 读取y
# fit = np.polyfit(x, y, 1)  ##拟合函数的次方，这里的数字是次方1，代表一次方即，ax+b，2代表二次方
# print(fit)
# p1 = np.poly1d(fit)  # 进行曲线的拟合，拟合曲线
# yvals = p1(x)
# plot2 = plt.plot(x, yvals, 'r', label='linear fitting')  # 画图，直线图
# plt.scatter(x, y, c='blue', label="Experimentally")
# # plt.xlim(20,140)
# # plt.ylim(20,140)
# plt.text(9, -1.5, f'y = {fit[0]}x+{fit[1]}')
# plt.xlabel("log(N)")
# plt.ylabel("log(Error)")
# plt.legend()
# plt.title("log(N)-log(Error)")
# plt.savefig("results_N_error_try.png")
# plt.show()
