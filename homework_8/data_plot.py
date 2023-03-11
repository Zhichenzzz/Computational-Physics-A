import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math

x2=[2,3,4,5,6,7,8]
# x2 = [100,1000,10000,100000,1000000,10000000,100000000]
y2 = [1/math.sqrt(100),1/math.sqrt(1000),1/math.sqrt(10000),1/math.sqrt(100000),1/math.sqrt(1000000),1/math.sqrt(10000000),1/math.sqrt(100000000)]

plt.plot(x2, y2,c="red",label='1/√N')


plt.scatter([2,3,4,5,6,7,8],[0.317553,0.0297087,0.0152726,0.0279878,
                        0.00223187,0.000817834,0.000867111],marker="*", label="Single int",c='blue',s=80)
plt.scatter([2,3,4,5,6,7,8],[0.122557,0.0729894,0.0358726,0.00190591,0.00256901,0.00057376,0.0000694229]
            ,marker="o", label="Muti int",c='green',s=30)

plt.legend()
plt.xlabel("x(The exponential of 10)")
plt.ylabel("y")
plt.title("Scatter_Theory")
plt.savefig("Scatter_Theory.png")
plt.show()
