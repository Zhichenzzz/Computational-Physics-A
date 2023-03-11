import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math


plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False
input_txt1 = "direct_sample_100000.txt"
x = []
f = open(input_txt1)

for line in f:
    line = line.strip('\n')
    line = line.split('\t')
    # print(line)
    x.append(float(line[0]))                    # 读取x

input_txt2 = "data_change.txt"
x0 = []
y0 = []
f0 = open(input_txt2)
for line in f0:
    line = line.strip('\n')
    line = line.split('\t')
    # print(line)
    x0.append(float(line[0]))                    # 读取x
    y0.append(float(line[1])/396002)
plt.plot(x0, y0, color='red',label='Original Curve')
plt.hist(x, bins=114, edgecolor="black",density=True,label='Direct Sampled Data',alpha=0.8)
ax = plt.gca()

plt.xlim(2898, 3015)
# plt.ylim(0,400)
plt.xlabel('Energy (ev)')
plt.ylabel('Relative Proportion')
plt.legend()
ax.set_title('实验能谱图与直接抽样比对图(N=100000)',fontsize=14,color='black')
plt.savefig("实验能谱图与直接抽样比对图(N=100000).png")
plt.show()