#include<iostream>
#include<string>
#include<fstream>
#include"student.h"
using namespace std;
student::student(string a1,string b1,int c1,string d1,string e1,int f1,int g1,string h1,int i1):name(a1),sex(b1),num(c1),xueyuan(d1),xi(e1),cla(f1),dor(g1),jiguan(h1),phone(i1),next(0){} 
student::student(student &a){
    name=a.getname();
    sex=a.getsex();
    num=a.getnum();
    xueyuan=a.getxueyuan();
    xi=a.getxi();
    cla=a.getcla();
    dor=a.getdor();
    jiguan=a.getjiguan();
    phone=a.getphone();
}
student::~student(){};//析构函数
string student::getname()const{return name;}
void student::setname(string &a){name=a;}
string student::getsex()const{return sex;}
void student::setsex(string &a){sex=a;}
int student::getnum()const{return num;}
void student::setnum(int &a){num=a;}
string student::getxueyuan()const{return xueyuan;}
void student::setxueyuan(string &a){xueyuan=a;}
string student::getxi()const{return xi;}
void student::setxi(string &a){xi=a;}
int student::getcla()const{return cla;}
void student::setcla(int &a){cla=a;}
int student::getdor()const{return dor;}
void student::setdor(int &a){dor=a;}
string student::getjiguan()const{return jiguan;}
void student::setjiguan(string &a){jiguan=a;}
int student::getphone()const{return phone;}
void student::setphone(int &a){phone=a;}//对于一些在学生类中主函数的实现
void student::display(){
    cout<<name<<" "<<sex<<" "<<num<<" "<<xueyuan<<" "<<xi<<" "<<cla<<" "<<dor<<" "<<jiguan<<" "<<phone<<endl;
}
void student::displaytofile1()
{
    ofstream outfile;
    outfile.open("学生信息.txt");
    outfile<<name<<" "<<sex<<" "<<num<<" "<<xueyuan<<" "<<xi<<" "<<cla<<" "<<dor<<" "<<jiguan<<" "<<phone<<endl;
    outfile.close();
}
void student::displaytofile2()
{
    ofstream outfile;
    outfile.open("学生信息.txt",ios::app);
    outfile<<name<<" "<<sex<<" "<<num<<" "<<xueyuan<<" "<<xi<<" "<<cla<<" "<<dor<<" "<<jiguan<<" "<<phone<<endl;
    outfile.close();
}
