//
// Created by HUAWEI on 2022/11/2.
//
#ifndef HOMEWORK_11_PARTICLE_H
#define HOMEWORK_11_PARTICLE_H
#include <cmath>
#include <random>
#include "Sch.h"
//定义粒子class
class Particle {
public:
    int x, y;                       //元素
    Particle(){                 //析构函数
        x = 0;
        y = 0;
    };
    Particle(int x,int y){
        this->x = x;
        this->y = y;
    }
    Particle(Particle& obj){
        this->x = obj.x;
        this->y = obj.y;
    }
    // 重载向量的四则运算
    Particle& operator=(const Particle& obj){
        this->x = obj.x;
        this->y = obj.y;
        return *this;
    }


    Particle operator-(const Particle& obj){
        Particle vec;
        vec.x = this->x - obj.x;
        vec.y = this->y - obj.y;
        return vec;
    }
    // friend Particle operator-(const Particle& a, const Particle& a){ //另一种写法
    //     Particle vec;
    //     vec.x = a.x - obj.x;
    //     vec.y = b.y - obj.y;
    //     return vec;
    // }
    Particle operator+(const Particle& obj){
        Particle vec;
        vec.x = this->x + obj.x;
        vec.y = this->y + obj.y;
        return vec;
    }
    float operator*(const Particle& obj){
        int rst;
        rst = this->x * obj.x + this->y * obj.y;
        return rst;
    }
    float length(){
        return pow(this->x*this->x + this->y*this->y , 0.5);
    }
    // 定义向量的模长
    static float length(Particle& obj){
        return obj.length();
    }

};
extern void Set_initial();
extern void Rdm_walk(Particle *part);
//static void Set_initial(Particle part);
extern void Circle_particle(Particle *P);
extern void Square_particle(Particle *P);
extern void Change_Circle();
extern bool if_collision(Particle P1, Particle P2);
extern bool if_collision_int(Particle P1, Particle P2);
extern void if_Diffusion();
extern void Border(Particle *P);
extern void free_part_Walking();
extern void Continuous_Walking();
extern void Print_unfree_particle();
extern void Set_kernal();
#endif //HOMEWORK_11_PARTICLE_H
