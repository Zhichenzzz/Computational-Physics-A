import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math

input_txt = ".\\cmake-build-debug\\px_dot_5000.txt"
x = []
y = []
z = []

f = open(input_txt)
plt.figure(figsize=(7, 7))
for line in f:
    line = line.strip('\n')
    line = line.split(',')
    # print(line)
    x.append(float(line[0]))                    # 读取x
    y.append(float(line[1]))                    # 读取y

x1 = np.arange(-1, 0, 0.01)
y1 = []
for t in x1:
    y_1 = math.exp(-t)
    y1.append(y_1)
plt.plot(x1, y1, label="Theoretically",c="red",linestyle="dashed")
plt.legend()

x2 = np.arange(0, 1, 0.01)
y2 = []
for t in x2:
    y_2 = math.exp(-t)+1
    y2.append(y_2)
plt.plot(x2, y2,c="red",linestyle="dashed")
plt.legend()

plt.scatter(x,y,marker="*", label="Experimentally",c='blue',s=0.5)
plt.legend()
plt.xlabel("x")
plt.ylabel("y")
plt.title("Scatter_px_Experimentally")          # 数字与cpp文件对应
plt.savefig("Scatter_px_Experimentally.png")    # 数字与cpp文件对应
plt.show()
