//
// Created by HUAWEI on 2022/10/16.
//

#ifndef HOMEWORK_8_INTEGRATION_H
#define HOMEWORK_8_INTEGRATION_H
#define result1 15.43901073557  //单变量积分理论结果
#define result2 5.67712         //多变量积分理论结果
double single_integration(int N, double (*func)(double x),double a,double b);
double multiple_integration(int N, double (*func)(double x,double y,double z,double u,double v),\
                            double x1,double x2,double y1,double y2,double z1,double z2,\
                            double u1,double u2,double v1,double v2);


#endif //HOMEWORK_8_INTEGRATION_H
