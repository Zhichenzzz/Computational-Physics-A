# 计算物理——Homework5

​											   	 		**曾郅琛 PB20071431**

**摘要：**利用C++语言以及Python中plt画图解决以下问题：对两个函数线型(Gauss 分布和类Lorentz 型分布)，设其一为 p(x)，另一为F(x)，其中常数 a,b不为1 , 用舍选法对 p(x) 抽样。将计算得到的归一化频数分布直方图与理论曲线 p(x) 进行比较，讨论差异，讨论抽样效率。在本次实验中，选取Gauss分布为p(x), Lorentz分布为F(x), 通过在F(x)分布情况下生成点阵，再用舍选法对 p(x) 抽样，最终与理论曲线对比，结果分析。

## 理论推导

###  p(x)与F(x)的选取与预处理

在本实验中，选取Lorentz分布和Gauss分布为：
$$
Lorentz:F(x)=\frac{1.25}{1+x^4}\\
Gauss:p(x)=e^{-0.5x^2}
$$
<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Lorentz.png" alt="Gauss_Lorentz" style="zoom:70%;" />

实验中，目的为了抽样[-1, 1]范围内p(x)，因而选取如上图两个函数。

### 抽样效率

​	根据舍选法理论抽样效率公式可得：
$$
\eta=\frac{\int_{-1}^{1}{F(x)dx}}{\int_{-1}^{1}{p(x)dx}}=\frac{1.71125}{2.1674}≈0.78954
$$

## 算法及实现

### F(x)分布函数以及归一化

​	在舍选法实施之前需要对F(x)预先求出其分布函数以及归一化操作：

​	由定积分公式求得，F(x)分布函数归一化后记为Q(x)，其中C为归一化系数:
$$
Q(x)=\frac{1.25}{4\sqrt2C}(ln(x^2+\sqrt2x+1)-ln(x^2-\sqrt2x+1)\\+2arctan(\sqrt2x+1)+2arctan(\sqrt2x-1))+0.5，C≈2.16743
$$
​	可以验证：
$$
Inf(Q(x))=0\\
Sup(Q(x))=1
$$
​	从而说明在所给函数分布为归一的、服从Lorentz分布的函数。

​	在程序中对应`double Lf(double x)`函数，作为主函数的库函数被后续代码引用。

### 舍选法抽样过程

​	简单描述舍选法抽样过程：

- 首先对归一化后的Q(x)按F(x)进行抽样，如下公式描述，而对于如此复杂的Q(x)，利用公式求反函数，显然不太现实，于是我们想到了用二分法近似逼近求解x的渐近值；
  $$
  \xi_x=Q(x)\\
  =>x=Q^{-1}(\xi_x)
  $$

- 于是，先利用此前实验中随机数生成器产生[0, 1]随机数，作为Q(x)的抽样值，之后在代码函数`double F_f(double y)`中利用二分法实现求解反函数x的值大小，作为依照F(x)分布抽取的x坐标

- 最后还需产生一个y方向上的随机数作为“舍选”的随机数，得到y坐标：
  $$
  y=\xi_yF(x)
  $$
  
- 根据得到y坐标与比大小，若y>p(x)，舍去；若y≤p(x)，保留。于是我们就得到了(x, p(x))=(x, y)的坐标点，随着随机数进一步生成，选择不同生成点数规模，得到最终的抽样得到p(x)的若干点。

  <img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\均匀性.png" alt="均匀性" style="zoom:70%;" />

  

### 代码组织与结构

- [ ] ​	`F_function.cpp/.h`中包含Lorentz函数归一化后的分布函数`double Lf(double x)`，以及利用二分法求解反函数值的`double F_f(double y)`函数代码；

- [ ] ​    `main.cpp`主函数中主要目的在舍选法的实现以及文件流存取的实现，最终得到N=10000, 50000, 100000, 150000, 200000, 500000, 1000000, 10000000的不同规模的抽样函数点

- [ ] ​    同时也调用了`Sch.cpp/.h`自写库函数，作为生成随机数的库

  

## 实验结果分析和讨论

### 不同规模数据的柱状图结果



- ​	在python中利用绘制归一化频数分布直方图，对每一数据集进行频数分布统计；

- ​	其中T代表Theoretically（理论上），E代表Experimentally（实验上），统一选取40根柱作为频数统计；
- ​	另外，注意到纵坐标为每个柱子内数据个数Random Number，在画图中需要对理论Gauss函数进行同样的处理，首先对该函数在[ -1, 1]内积分数值进行归一化，再对柱状图围成的面积和Gauss函数围成面积进行统一化处理，最终利用plt函数包画出图：

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_10000_40.png" alt="Gauss_Sampling_10000_40" style="zoom:50%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_50000_40.png" alt="Gauss_Sampling_50000_40" style="zoom:50%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_100000_40.png" alt="Gauss_Sampling_100000_40" style="zoom:50%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_150000_40.png" alt="Gauss_Sampling_150000_40" style="zoom:50%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_200000_40.png" alt="Gauss_Sampling_200000_40" style="zoom:50%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_500000_40.png" alt="Gauss_Sampling_500000_40" style="zoom:50%;" />

​	可以看到，随着数据量的增大，最终抽样结果与理论结果吻合度越大。

### 不同柱数反映出的抽样效果

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_1000000_100.png" alt="Gauss_Sampling_1000000_100" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_1000000_200.png" alt="Gauss_Sampling_1000000_200" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_1000000_500.png" alt="Gauss_Sampling_1000000_500" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_10000000_100.png" alt="Gauss_Sampling_10000000_100" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_10000000_200.png" alt="Gauss_Sampling_10000000_200" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_6\PB20071431_曾郅琛_06\Gauss_Sampling_10000000_500.png" alt="Gauss_Sampling_10000000_500" style="zoom:67%;" />

​	可以看到随着柱数选择增多，抽样的细节看的更清楚，而于此同时也能进一步证明抽样结果非常好

### 抽样效率的讨论

​	实验结果如下三线表：

| Number       | Efficiency   |
| ------------ | ------------ |
| **10000**    | **0.78765**  |
| **50000**    | **0.789864** |
| **100000**   | **0.788911** |
| **150000**   | **0.789058** |
| **200000**   | **0.789646** |
| **500000**   | **0.789478** |
| **1000000**  | **0.789123** |
| **10000000** | **0.789516** |

$$
\eta=\frac{\int_{-1}^{1}{F(x)dx}}{\int_{-1}^{1}{p(x)dx}}=\frac{1.71125}{2.1674}≈0.78954
$$

​	可以明显观察到，在所给数据范围内，实验抽样效率与理论值都十分接近；而且随着Number的增大，抽样效率越来越趋近于理论值0.78954。证明抽样效果很好。

## 深入探讨抽样效率

​	除了丁老师在课上讲解的此种舍选法抽样，自己在网上调研到基于此方法的另一改进措施，可以提高舍选效率：
$$
C_{p}=max(p(x)/F(x))
\\F^{'}(x)=C_m*F(x)，C_m≤C_{p}
$$
​	具体思想是通过对F(x)进行缩放处理，得到一个更加接近p(x)的新函数，由此抽样率更高，节省时间的同时也能提高抽样效率；

​	我自己尝试了此过程，并选取Cm=0.87，得到在N=500000的抽样结果：

<img src="D:\Courses\ComputerPhysics\homework_6\Gauss_Sampling_500000_40_new.png" alt="Gauss_Sampling_500000_40_new" style="zoom:67%;" />

![image-20221012205712115](C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20221012205712115.png)

​	出现的结果也是惊人的好！把抽样效率提高到了90%的水平。

## 总结与收获

​	在此次实验中，通过之前的积累代码与新的思路，进一步利用控制函数的方法进行舍选法抽样，增强了对抽样的理解。同时在探讨抽样效率的过程中，在哈工大《计算物理》课程网课中了解到可以基于上课内容进一步改善抽样效率，给自己带来更多的思维全面性和理解力。

​	总的来说，不管是代码能力还是抽样思维，都收获颇多。