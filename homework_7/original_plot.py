import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
plt.rcParams["font.sans-serif"] = ["SimHei"]
plt.rcParams["axes.unicode_minus"] = False
input_txt = "data_change.txt"
x = []
y = []

f = open(input_txt)

for line in f:
    line = line.strip('\n')
    line = line.split('\t')
    # print(line)
    x.append(float(line[0]))                    # 读取x
    y.append(float(line[1])/396002)                    # 读取y
#    z.append(float(line[2]))                    # 读取z
# ax = plt.figure().add_subplot(111, projection = '3d')
# ax.set_xlabel('X Label')
# ax.set_ylabel('Y Label')
# ax.set_zlabel('Z Label')
#
#
x1=x
y1=[]
for x in range(2900,2965):
    y1.append((69.446*x-200235.2)/396002)
for x in range(2965,2992):
    y1.append((-165.85*x+497418)/396002)
for x in range(2992,3001):
    y1.append((37630.0)/396002)
for x in range(3001,3014):
    y1.append((-3135.083*x+9446014.089)/396002)
# plt.plot(x1, y, color='red',label='Data Fitted Curve')
plt.plot(x1, y1, color='red',label='Distribution function G(x)')
# plt.hist(y,bins=114, edgecolor="black",label="zhu")
plt.bar(x1, y, width=0.95,label='Original Data', align='center', edgecolor="black",alpha=0.8)
ax = plt.gca()
plt.xlim(2898, 3015)
plt.ylim(0,0.10)
plt.xlabel('Energy (ev)')
plt.ylabel('Relative Proportion')
plt.legend()
ax.set_title('G(x)对于原始数据的舍选效果',fontsize=14,color='black')
# plt.savefig("实验能谱图.png")
plt.savefig("G(x)对于原始数据的舍选效果.png")
plt.show()