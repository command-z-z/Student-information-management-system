#include<iostream>
#include<algorithm>
#include<vector>
#include"list.h"
#include"student.h"
using namespace std;
void list::add(student &a)
{
    student* p=new student(a);
    if(last)last->next=p;
    else first=p;
    last=p;
    listsize++;
}
void list::sortbynum()//排序
{
    int a[1000];
    student *stu=first;
    for(int i=0;i<listsize;i++)
    {
        a[i]=stu->getnum();
        stu=stu->next;
    }
    sort(a,a+listsize);
    for(int i=0;i<listsize;i++)
    {
        findbynum2(a[i],i);
    }
}
void list::sortbyxueyuan()
{
    string a[1000];
    student *stu=first;
    for(int i=0;i<listsize;i++)
    {
        a[i]=stu->getxueyuan();
        stu=stu->next;
    }
    sort(a,a+listsize);
    for(int i=0;i<listsize;i++)
    {
        findbyxueyuan2(a[i],i);
    }
}
void list::sortbydor()
{
    int a[1000];
    student *stu=first;
    for(int i=0;i<listsize;i++)
    {
        a[i]=stu->getdor();
        stu=stu->next;
    }
    sort(a,a+listsize);
    for(int i=0;i<listsize;i++)
    {
        findbysushe2(a[i],i);
    }
}
void list::changebynum1(int num,int choose,int change){
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getnum()==num && choose==3){stu->setnum(change);k++;}
        if(stu->getnum()==num && choose==6){stu->setcla(change);k++;}
        if(stu->getnum()==num && choose==7){stu->setdor(change);k++;}
        if(stu->getnum()==num && choose==9){stu->setphone(change);k++;}
    }
    if(k!=0)cout<<"修改成功"<<endl;
    if(k==0)cout<<"未找到相关信息,请重新操作"<<endl;
}
void list::changebynum2(int num,int choose,string change){
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getnum()==num && choose==1){stu->setname(change);k++;}
        if(stu->getnum()==num && choose==2){stu->setsex(change);k++;}
        if(stu->getnum()==num && choose==4){stu->setxueyuan(change);k++;}
        if(stu->getnum()==num && choose==5){stu->setxi(change);k++;}
        if(stu->getnum()==num && choose==8){stu->setjiguan(change);k++;}
    }
    if(k!=0)cout<<"修改成功"<<endl;
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::deletebynum(int num){
    student *stu=first;
    int k=0;
    if(stu->getnum()==num){first=stu->next;listsize--;k++;}
    else{
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->next->getnum()==num){stu->next=stu->next->next;listsize--;k++;break;}//删除学生信息
    }
    }
    cout<<"删除成功"<<endl;
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbynum1(int num)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getnum()==num){stu->display();k++;}//发现人数
    }
    if(k==0)cout<<"未找到相关信息，请重新操作"<<endl;
}
void list::findbynum2(int num,int k)
{
    student *stu=first;
    if(k==0){
        for(stu=first;stu;stu=stu->next)
        {
            if(stu->getnum()==num)stu->displaytofile1();
        }
    }
    else{
        for(stu=first;stu;stu=stu->next)
        {
             if(stu->getnum()==num)stu->displaytofile2();
        }
    }
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getnum()==num){stu->display();}//发现人数
    }

}
void list::findbyxueyuan(string xueyuan)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getxueyuan()==xueyuan){stu->display();k++;}//发现学院
    }
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbyxueyuan2(string xueyuan,int k)
{
    student *stu=first;
    if(k==0){
        for(stu=first;stu;stu=stu->next)
        {
            if(stu->getxueyuan()==xueyuan)stu->displaytofile1();
        }
    }
    else{
        for(stu=first;stu;stu=stu->next)
        {
             if(stu->getxueyuan()==xueyuan)stu->displaytofile2();
        }
    }
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getxueyuan()==xueyuan){stu->display();}//发现人数
    }
}
void list::findbyname(string xingming)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getname()==xingming){stu->display();k++;}//发现名字
    }
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbyxi(string xi)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getxi()==xi){stu->display();k++;}//发现系
    }
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbybanji(int banji)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getcla()==banji){stu->display();k++;}//发现班级
    }
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbysushe(int sushe)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getdor()==sushe){stu->display();k++;}//发现宿舍
    }
    if(k==0)cout<<"未找到相关信息"<<endl;
}
void list::findbysushe2(int sushe,int k){
    student *stu=first;
    if(k==0){
        for(stu=first;stu;stu=stu->next)
        {
            if(stu->getdor()==sushe)stu->displaytofile1();
        }
    }
    else{
        for(stu=first;stu;stu=stu->next)
        {
             if(stu->getdor()==sushe)stu->displaytofile2();
        }
    }
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getdor()==sushe){stu->display();}//发现人数
    }
}
void list::statisticbyxueyuan(string xueyuan1)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getxueyuan()==xueyuan1){k++;}//统计人数
    }
    cout<<"人数为"<<k<<endl;
}
void list::statisticbyxi(string xi1)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getxi()==xi1){k++;}//统计人数
    }
    cout<<"人数为"<<k<<endl;
}
void list::statisticbybanji(int cla1)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getcla()==cla1){k++;}//统计人数
    }
    cout<<"人数为"<<k<<endl;
}
void list::statisticbyjiguan(string jiguan1)
{
    student *stu=first;
    int k=0;
    for(stu=first;stu;stu=stu->next)
    {
        if(stu->getjiguan()==jiguan1){k++;}//统计人数
    }
    cout<<"人数为"<<k<<endl;
}
void list::listdisplay()
{
    student *stu=first;
    for(stu=first;stu;stu=stu->next)
    {
        stu->display();
    }
}
void list::listtofile(){
   student *stu=first;
   stu->displaytofile1();
   for(stu=first->next;stu;stu=stu->next)
    {
        stu->displaytofile2();
    }
}