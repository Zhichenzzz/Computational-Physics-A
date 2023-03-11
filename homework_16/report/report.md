# 计算物理第十五次实验报告

​															**曾郅琛 PB20071431**

[TOC]

**摘要**：本次实验完成chaos中的系统状态确定和分析，探究横轴方向倍周期分岔中的标度行为，并试图探究在纵轴方向上的标度行为，实验通过c++和python完成。

## 实验要求

**以$x_n=\lambda sin(\pi x_{n-1})$为迭代方程进行迭代：**

**(1)画出系统状态随参数$\lambda$的变化图，要求在图中体现出定值状态、倍周期分叉和混沌状态；**
**(2)列出各个倍周期分叉处的$\lambda$值，求相应的 Feigenbaum 常数**  

### 理论分析

​	在某一迭代函数下，系统状态会随参数的变化， 经历了灭绝， 定态， 倍周期分岔（周期数为2，4，8……）以及混沌及周期窗口四种状态。下图为课程中老师演示的系统状态随参数的变化曲线：

<img src="C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20221212103709952.png" alt="image-20221212103709952" style="zoom:50%;" />

​	可以看到从周期数为2，4，8，16……的变化且变化得愈来愈快。接着再放大，可看到混沌之后的周期数为3或7……的窗口，然后倍周期很快经过3，6，12，……或 7，14，28……，然后再次中断进入新的混沌。

​	在本次实验中我们考虑倍周期分岔，且主要探究横轴方向倍周期分岔中的标度行为。

​	$\lambda_m$按以下的几何级数（幂函数）收敛到$\lambda_∞$：
$$
\lambda_∞-\lambda_m=A\delta^{-m}  \\(when\,\,\,\,m>>1)
$$
​	$A$是依赖于迭代函数的常数，而$\delta$是不依赖于迭代函数的普适常数.

​	故而我们可以推导出计算$\delta$的极限公式：
$$
\delta=\lim_{m->∞}{\frac{\lambda_m-\lambda_{m-1}}{\lambda_{m+1}-\lambda_{m}}}
$$

## 算法描述

### 系统状态的计算迭代

​	在实验中，我们完成对以下迭代格式系统的计算：
$$
x_n=\lambda sin(\pi x_{n-1})
$$
​	对于某个区间的$\lambda$，通过固定步长改变参数值，且在每个$\lambda$取值下，我们设置了初始的去热化过程，将前1000次迭代舍去不作为最终系统的状态，再选取$10^4$量级的迭代得到最终点；

​	同时我们为了找到分岔点对应的$\lambda$取值，我们在最初的图像下进行进一步缩小区间减小步长，在每个分岔找到对应的$\lambda$近似取值。

### 初值敏感性

​	根据老师课上所说，我们知道，初值敏感性是混沌的一个重要的特征;  初值敏感性不是由任何外界随机因素引起的， 而是由系统本身确定的;  初值敏感性是混沌中类似随机现象的根源;  初值敏感性导致过程的不可预测性，初值敏感性又被通俗地称为“蝴蝶效应”。

​	在实验中同样遇到该问题，这将在后续实验结果中说明并提出一种解决方案。

### 确定倍周期分岔点

​	在实验中，我们通过不断的对$\lambda$取值区间和$\lambda$更新步长进行更新，从而探索具有更高精度的倍周期分岔点，其中选择倍周期分岔根据python对数据处理后确定。

### 算法代码解释

- `double function(double lambda, double x)`
  - 描述迭代函数；
- 更新不同范围$\lambda$，步长，在上述描述算法下进行迭代输出；



## 系统状态随参数$\lambda$的变化图区间[ -2, 2]

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_C_2.png" alt="Period Doubling Bifurcation_C_2" style="zoom: 67%;" />

​	这张图是在我们选定初值时的结果，可以很明显地看到系统状态随$\lambda$的变化， 经历了定态， 倍周期分岔以及混沌及周期窗口四种状态。

​	同时我们注意到图形存在一定的破缺，在$\lambda>0$的一段区间内，周期数为2的状态缺失了一半，经过分析，此原因的产生是由于我们每次设定的初值都是固定的，所以由于混沌模型的初值敏感性，在该初值下可能会出现一定的偶然情况，初值敏感性导致过程的不可预测性。

​	故而，我们在实验代码中设置了多个随机数进行初值的迭代过程，从而在一定程度上消减初值敏感性的问题，这对之后我们计算Feigenbaum 常数也起到了很大的作用。

​	更改后的结果如下：

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_C_2_rdm.png" alt="Period Doubling Bifurcation_C_2_rdm" style="zoom:67%;" />

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_C_0.3_0.9.png" alt="Period Doubling Bifurcation_C_0.3_0.9" style="zoom:67%;" />

​	**定态， 倍周期分岔以及混沌及周期窗口**，一目了然

## 横轴方向倍周期分叉点与Feigenbaum常数计算

​	按照上面的思路，我们从周期为2开始，依次寻找到周期更大：

### 周期为2

​	我们选择0.3到0.4的区间，步长为0.00001，迭代后画出图像如下：

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_0.31755.png" alt="Period Doubling Bifurcation_0.31755" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.31752$，作为$1→2$周期的分岔点；**

### 周期为4

​	同样的我们选择0.718到0.721的区间范围，步长不变，迭代后画图如下：

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_0.719.png" alt="Period Doubling Bifurcation_0.719" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.71975$，作为$2→4$周期的分岔点；**

### 周期为8

<img src="C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20221212162427845.png" alt="image-20221212162427845" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.83301$，作为$4→8$周期的分岔点；**

### 周期为16

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_0.858.png" alt="Period Doubling Bifurcation_0.858" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.85861$，作为$8→16$周期的分岔点；**

### 周期为32

<img src="D:\Courses\ComputerPhysics\homework_16\report\Period Doubling Bifurcation_0.864.png" alt="Period Doubling Bifurcation_0.864" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.86408$，作为$16→32$周期的分岔点；**

### 周期为64

<img src="C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20221212162856233.png" alt="image-20221212162856233" style="zoom: 50%;" />

​	**最终通过*python*处理数据我们选择$\lambda=0.86525$，作为$32→64$周期的分岔点；**

​	再继续往后我们很难分辨出来分岔点了，所以程序到此为止.



### 列表计算倍周期分岔点的Feigenbaum常数



| **$m$** |      | **分岔情况** |      | **$\lambda$** |      | **$\frac{\lambda_m-\lambda_{m-1}}{\lambda_{m+1}-\lambda_{m}}$** |      | **理论值**   |
| ------- | ---- | ------------ | ---- | ------------- | ---- | ------------------------------------------------------------ | ---- | ------------ |
| **1**   |      | **$1→2$**    |      | **0.31752**   |      | NULL                                                         |      |              |
| **2**   |      | **$2→4$**    |      | **0.71975**   |      | **3.551386**                                                 |      | **4.669201** |
| **3**   |      | **$4→8$**    |      | **0.83301**   |      | **4.424218**                                                 |      | **4.669201** |
| **4**   |      | **$8→16$**   |      | **0.85861**   |      | **4.680073**                                                 |      | **4.669201** |
| **5**   |      | **$16→32$**  |      | **0.86408**   |      | **4.675213**                                                 |      | **4.669201** |
| **6**   |      | **$32→64$**  |      | **0.86525**   |      | **NULL**                                                     |      |              |



​	可以看到随着$m$的增大，我们的最终比值逐渐趋近于理论值4.669201，证明实验方法和结果较好。

## 纵方向倍周期分岔点的Feigenbaum常数$\alpha$

​	我试图去按照老师上课所讲去探究纵轴方向上的另一Feigenbaum常数$\alpha$：

<img src="C:\Users\HUAWEI\AppData\Roaming\Typora\typora-user-images\image-20221212170339148.png" alt="image-20221212170339148" style="zoom:67%;" />

​	此过程利用txt文件搜索进行，搜索在此过程中在$x_n=0.5\,or\,-0.5$附近的值，计算$d_n$：

​	在python中画出d的形状如下：

<img src="D:\Courses\ComputerPhysics\homework_16\Period Doubling Bifurcation_try.png" alt="Period Doubling Bifurcation_try" style="zoom: 50%;" />

搜索到的点坐标计算间距有：



| **$m$** |      |      | **$d$**    |      | **$\frac{d_m}{d_{m+1}}$** |      | **理论值** |
| ------- | ---- | ---- | ---------- | ---- | ------------------------- | ---- | ---------- |
| **1**   |      |      | **1**      |      | **NULL**                  |      |            |
| **2**   |      |      | **0.2330** |      | **4.2918**                |      | **2.5029** |
| **3**   |      |      | **0.0944** |      | **2.4682**                |      | **2.5029** |
| **4**   |      |      | **0.0378** |      | **2.4974**                |      | **2.5029** |

最终结果与理论值非常接近！

## **总结**

​	在本次实验中， 我们对系统状态随参数$\lambda$的变化图进行计算分析，体现出定值状态、倍周期分叉和混沌状态；同时完成了在横坐标和纵坐标两个方向上的Feigenbaum常数计算，最终结果和理论值非常接近！
