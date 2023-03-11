import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import math

x = np.arange(-10,10,0.001)
y0 = np.exp(-0.5*x*x)
y1 = np.abs(1.25/(1+x**4))


ax=plt.gca()
plt.plot(x, y0, color='orange',label="Gauss")
plt.plot(x, y1, color='green',label="Lorentz")
plt.xlim(-5, 5)
plt.ylim(0,1.5)
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.title('Gauss_Lorentz',fontsize=14,color='blue')
plt.savefig("Gauss_Lorentz.png")
plt.show()