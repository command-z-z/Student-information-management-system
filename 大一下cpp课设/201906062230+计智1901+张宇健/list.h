#ifndef LIST
#define LIST
#include<iostream>
#include"student.h"
#include<string>
using namespace std;
class list{
    student *first,*last;
    int listsize;
public:
    list():first(0),last(0),listsize(0){}
    void add(student &a);//将一个学生类加入链表
    void sortbynum();//根据学号排序
    void sortbyxueyuan();//根据学院排序
    void sortbydor();//根据寝室排序
    void changebynum1(int num,int choose,int change);//根据学号修改信息
    void changebynum2(int num,int choose,string change);//根据学号修改信息
    void deletebynum(int num);//根据学号删除信息
    void findbynum1(int num);//查询
    void findbynum2(int num,int k);//查询
    void findbyxueyuan(string xueyuan);
    void findbyxueyuan2(string xueyuan,int k);
    void findbyname(string xingming);
    void findbyxi(string xi);
    void findbybanji(int banji);
    void findbysushe(int sushe);
    void findbysushe2(int sushe,int k);
    void statisticbyxueyuan(string xueyuan1);//统计学院人数
    void statisticbyxi(string xi1);//统计系人数
    void statisticbybanji(int cla1);//统计班级人数
    void statisticbyjiguan(string jiguan1);//统计籍贯人数
    void listdisplay();//链表打印
    void listtofile();//链表打印到文件
};
#endif