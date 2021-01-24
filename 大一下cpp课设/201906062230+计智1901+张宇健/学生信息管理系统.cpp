#include<iostream>
#include<string>
#include<fstream>
#include"student.h" 
#include"student.cpp"
//#include"list.h"
#include"list.cpp"
using namespace std;
int main()
{
    string a,b,d,e,h;
    int c,f,g,i,time=0;
    int option;
    list m;
    ifstream infile("学生信息.txt",ios::in);//从文件读取信息
    if(!infile){
        cerr<<"open error!"<<endl;
        exit(1);
    }//判断能否成功打开文件
    while(infile>>a>>b>>c>>d>>e>>f>>g>>h>>i)
    {
        student stu(a,b,c,d,e,f,g,h,i);
        m.add(stu);//文件里的信息加入链表
    }
    bool pan=true;
    while(pan)
    {
    cout<<"**********欢迎来到学生信息管理系统**********"<<endl;
    cout<<endl;
    cout<<"*****************功能选择*****************"<<endl;
    cout<<endl;
    cout<<"1、输入功能"<<endl;
    cout<<"2、排序功能"<<endl;
    cout<<"3、修改功能"<<endl;
    cout<<"4、删除功能"<<endl;
    cout<<"5、查询功能"<<endl;
    cout<<"0、结束程序"<<endl;
    cout<<endl;
    cout<<"**********欢迎来到学生信息管理系统**********"<<endl;
    cout<<endl;
    cout<<"请选择功能：";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int x;
            cout<<"请输入要输入信息的学生个数:";
            cin>>x;
            for(int y=1;y<=x;y++)
            {
            cout<<"请输入第"<<y<<"个学生的姓名、性别、学号、学院、系、班级、宿舍、籍贯、联系电话"<<endl;
            cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
            student stu(a,b,c,d,e,f,g,h,i);
            m.add(stu);
            ofstream outfile;
            outfile.open("学生信息.txt",ios::app);
            outfile<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<endl;
            outfile.close();
            }
            cout<<"输入成功"<<endl;
            break;
        }
        case 2:
        {
            bool duan1=true;
            while(duan1)
            {
                cout<<"1、按学号排序"<<endl;
                cout<<"2、按学院排序"<<endl;
                cout<<"3、按宿舍排序"<<endl;
                cout<<"输入0返回主菜单"<<endl;
                cout<<"---------------------------"<<endl;
                cout<<"请输入排序方式:";
                int k;
                cin>>k;
                switch(k)
                {
                    case 1:
                    {
                        cout<<"学生姓名  性别  学号  学院  系  班级  宿舍  籍贯  联系电话"<<endl;
                        m.sortbynum();
                        break;
                    }
                    case 2:
                    {
                        cout<<"学生姓名  性别  学号  学院  系  班级  宿舍  籍贯  联系电话"<<endl;
                        m.sortbyxueyuan();
                        break;
                    }
                    case 3:
                    {
                        cout<<"学生姓名  性别  学号  学院  系  班级  宿舍  籍贯  联系电话"<<endl;
                        m.sortbydor();
                        break;
                    }
                    case 0:
                    {
                        duan1=false;
                        break;
                    }
                }
                cout<<"---------------------------"<<endl;
            }
            break;
        }
        case 3:
        {
            int num1,choose;
            int xiugai1;
            string xiugai2;
            cout<<"请输入学号:";
            cin>>num1;
            cout<<"请输入要修改的信息的选项：1、姓名 2、性别 3、学号 4、学院 5、系 6、班级 7、宿舍 8、籍贯 9、联系电话"<<endl;
            cin>>choose;
            switch(choose)
            {
                case 1:{cout<<"请输入更改后的名字"<<endl;cin>>xiugai2;m.changebynum2(num1,choose,xiugai2);break;}
                case 2:{cout<<"请输入更改后的性别"<<endl;cin>>xiugai2;m.changebynum2(num1,choose,xiugai2);break;}
                case 3:{cout<<"请输入更改后的学号"<<endl;cin>>xiugai1;m.changebynum1(num1,choose,xiugai1);break;}
                case 4:{cout<<"请输入更改后的学院"<<endl;cin>>xiugai2;m.changebynum2(num1,choose,xiugai2);break;}
                case 5:{cout<<"请输入更改后的系"<<endl;cin>>xiugai2;m.changebynum2(num1,choose,xiugai2);break;}
                case 6:{cout<<"请输入更改后的班级"<<endl;cin>>xiugai1;m.changebynum1(num1,choose,xiugai1);break;}
                case 7:{cout<<"请输入更改后的宿舍"<<endl;cin>>xiugai1;m.changebynum1(num1,choose,xiugai1);break;}
                case 8:{cout<<"请输入更改后的籍贯"<<endl;cin>>xiugai2;m.changebynum2(num1,choose,xiugai2);break;}
                case 9:{cout<<"请输入更改后的联系电话"<<endl;cin>>xiugai1;m.changebynum1(num1,choose,xiugai1);break;}
            }
            m.listtofile();
            break;
        }
        case 4:
        {
            int num2;
            cout<<"请输入学号:";
            cin>>num2;
            m.deletebynum(num2);
            m.listtofile();
            break;
        }
        case 5:
        {
            bool duan2=true;
            while(duan2)
                {
                int j;
                cout<<"1、根据学号查询学生信息"<<endl;
                cout<<"2、根据姓名，学院，系，班级，宿舍查询学学生信息"<<endl;
                cout<<"3、按照学院，系，班级，籍贯统计人数"<<endl;
                cout<<"输入0返回主菜单"<<endl;
                cout<<"请输入要选择的功能:";
                cin>>j;
                switch(j)
                {
                    case 1:
                    {
                        int num3;
                        cout<<"请输入学号:";
                        cin>>num3;
                        cout<<"学生姓名  性别  学号  学院  系  班级  宿舍  籍贯  联系电话"<<endl;
                        m.findbynum1(num3);
                        cout<<"---------------------------"<<endl;
                        break;
                    }
                    case 2:
                    {
                        int n;
                        cout<<"1、根据姓名查询学生信息"<<endl;
                        cout<<"2、根据学院查询学生信息"<<endl;
                        cout<<"3、根据系查询学生信息"<<endl;
                        cout<<"4、根据班级查询学生信息"<<endl;
                        cout<<"5、根据宿舍查询学生信息"<<endl;
                        cout<<"请输入要选择的功能:";
                        cin>>n;
                        switch(n)
                        {
                            case 1:
                            {
                                string a4;
                                cout<<"请输入姓名:";
                                cin>>a4;
                                m.findbyname(a4);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 2:
                            {
                                string b4;
                                cout<<"请输入学院:";
                                cin>>b4;
                                m.findbyxueyuan(b4);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 3:
                            {
                                string a4;
                                cout<<"请输入系:";
                                cin>>a4;
                                m.findbyxi(a4);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 4:
                            {
                                int a4;
                                cout<<"请输入班级:";
                                cin>>a4;
                                m.findbybanji(a4);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 5:
                            {
                                int a4;
                                cout<<"请输入宿舍:";
                                cin>>a4;
                                m.findbysushe(a4);
                                cout<<"---------------------------"<<endl;
                                break;
                            }

                        }
                        break;
                    }
                    case 3:
                    {
                        int n;
                        cout<<"1、按照学院统计人数"<<endl;
                        cout<<"2、按照系统计人数"<<endl;
                        cout<<"3、按照班级统计人数"<<endl;
                        cout<<"4、按照籍贯统计人数"<<endl;
                        cout<<"请选择按什么统计:";
                        cin>>n;
                        switch(n)
                        {
                            case 1:
                            {
                                string xueyuan1;
                                cout<<"请输入学院"<<endl;
                                cin>>xueyuan1;
                                m.statisticbyxueyuan(xueyuan1);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 2:
                            {
                                string xi1;
                                cout<<"请输入系"<<endl;
                                cin>>xi1;
                                m.statisticbyxi(xi1);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 3:
                            {
                                int cla1;
                                cout<<"请输入班级"<<endl;
                                cin>>cla1;
                                m.statisticbybanji(cla1);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                            case 4:
                            {
                                string jiguan1;
                                cout<<"请输入系"<<endl;
                                cin>>jiguan1;
                                m.statisticbyxi(jiguan1);
                                cout<<"---------------------------"<<endl;
                                break;
                            }
                        }
                        break;
                    }
                    case 0:
                    {
                        duan2=false;
                        break;
                    }
                    break;
                }
            }
            break;
        }
        case 0:
        {
            cout<<"结束成功"<<endl;
            pan=false;
            break;
        }
    }
    }
    return 0;
}