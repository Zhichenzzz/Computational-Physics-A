import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
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
input_txt = ".\\cmake-build-debug\\R_Generate.txt"
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
    z.append(float(line[2]))                    # 读取z
ax = plt.figure().add_subplot(111, projection = '3d')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

ax.scatter(x, y, z, c = 'b',s=1, marker = '^')

plt.title("Random number On Sphere_1000")          # 数字与cpp文件对应
plt.savefig("Random number On Sphere_1000.png")    # 数字与cpp文件对应
plt.show()
