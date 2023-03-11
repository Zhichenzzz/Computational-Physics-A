import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math

plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False


# 正态分布的概率密度函数
def normpdf(x, mu, sigma):
    pdf = np.exp(-(x - mu) ** 2 / (2 * sigma ** 2)) / (sigma * np.sqrt(2 * np.pi))
    return pdf


# a=0.53452248382
b= 0.59102673
mu, sigma = ((0.5-2.0/math.exp(1))/(1+math.exp(1)-math.exp(-1)), b/math.sqrt(2))  # mu:期望;sigma:标准差
x = np.arange(mu - 4 * sigma, mu + 4 * sigma, 0.001)  # 生成数据，步长越小，曲线越平滑
y = normpdf(x, mu, sigma)

# 概率分布曲线
plt.plot(x, y, 'r--', linewidth=2, label='Normal Distribution')

input_txt = "func_hw4_2.txt"
x1 = []
f = open(input_txt)

for line in f:
    line = line.strip('\n')
    x1.append(float(line))  # 读取x
plt.hist(x1, bins=50, density=True, color='blue', edgecolor="black", label='M-C Data', alpha=0.8)
ax = plt.gca()
plt.xlabel('x')
plt.ylabel('y')
# plt.xlim(1.5,2.5)
plt.legend()
ax.set_title('M-C func_hw4 Normalization_2', fontsize=14, color='black')
plt.savefig("func_hw4_2.png")
plt.show()
