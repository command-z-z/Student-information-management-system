#ifndef STUDENT
#define STUDENT
#include<iostream>
#include<string>
using namespace std;
class student{
private:
    string name;
    string sex;
    int num;
    string xueyuan;
    string xi;
    int cla;
    int dor;
    string jiguan;
    int phone;
public:
    student *next;
    student(string a1,string b1,int c1,string d1,string e1,int f1,int g1,string h1,int i1);
    student(student &a);//复制构造函数
    ~student();  //析构函数
    string getname()const;
    void setname(string &a);//姓名的得到和修改
    string getsex()const;
    void setsex(string &a);//性别的得到和修改
    int getnum()const;
    void setnum(int &a);//学号的得到和修改
    string getxueyuan()const;
    void setxueyuan(string &a);//学院的得到和修改
    string getxi()const;
    void setxi(string &a);//系的得到和修改
    int getcla()const;
    void setcla(int &a);//班级的得到和修改
    int getdor()const;
    void setdor(int &a);//寝室的得到和修改
    string getjiguan()const;
    void setjiguan(string &a);//籍贯的得到和修改
    int getphone()const;
    void setphone(int &a);//联系电话的得到和修改
    void display();
    void displaytofile1();
    void displaytofile2();
};
#endif