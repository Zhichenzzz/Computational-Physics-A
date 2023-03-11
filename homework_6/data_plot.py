import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math
#
# f=open(".\\cmake-build-debug\\R_Generate.txt")
# a = f.read()
# p = list(float(i) for i in a.split())
# plt.scatter(p[0::3],p[1::3],p[2::3],marker="*", c='blue')
# plt.xlabel("x random")
# plt.ylabel("y random")
# plt.zlabel("z random")
# plt.title("Random")
# plt.savefig("Scatter_plot.png")
# plt.show()
input_txt = ".\\cmake-build-debug\\Gauss_dot_500000_new.txt"
x = []
y = []
z = []

f = open(input_txt)

for line in f:
    line = line.strip('\n')
    line = line.split(',')
    # print(line)
    x.append(float(line[0]))                    # 读取x
    y.append(float(line[1]))                    # 读取y
#    z.append(float(line[2]))                    # 读取z
# ax = plt.figure().add_subplot(111, projection = '3d')
# ax.set_xlabel('X Label')
# ax.set_ylabel('Y Label')
# ax.set_zlabel('Z Label')
#
# ax.scatter(x, y, z, c = 'b',s=1, marker = '^')
plt.hist(x, bins=40,range=(-1,1))
x0 = np.arange(-1,1,0.001)
y0 = 25000/1.71125*np.exp(-0.5*x0*x0)


# plt.scatter(x,y,marker="*", c='blue')
# plt.xlabel("x random")
# plt.ylabel("y random")
# plt.title("1")          # 数字与cpp文件对应
# plt.savefig("1.png")    # 数字与cpp文件对应
# plt.show()
ax=plt.gca()
plt.plot(x0, y0, color='red')
plt.xlim(-1, 1)
#plt.ylim(0,1)
plt.xlabel('x')
plt.ylabel('Random Number')
plt.legend("TE")
ax.set_title('Gauss_Sampling_500000_40_new',fontsize=14,color='blue')
plt.savefig("Gauss_Sampling_500000_40_wan.png")
plt.show()