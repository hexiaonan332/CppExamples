#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

struct Student
{
        int ID;
        string name;
        double score;
}stu[101];

int num;
void AddStudents();
bool DelStudents();
void AddScore();
void Rank();
void Show(Student *stu,int n);
void Options();

int main()
{
    int op;
    while(true)
    {
        Options();
        cin>>op;
        switch(op)
        {
            case 1: AddStudents();
                    break;
            case 2: if(DelStudents())
                        cout<<"删除学生信息成功!"<<endl;
                    else
                        cout<<"删除学生信息失败，请重新选择操作!"<<endl;
                    break;
            case 3: AddScore();
                    break;
            case 4: Rank();
                    break;
            case 5: Show(stu,num);
                    break;
            case 6: return 0;
            default: cout<<"输入错误，请重新输入！\n";
        }
    }

    return 0;
}

void Options()
{
        cout<<"请选择操作:\n";
        cout<<"1.学生信息增加"<<endl;
        cout<<"2.删除学生信息"<<endl;
        cout<<"3.学生成绩录入"<<endl;
        cout<<"4.学生成绩排名"<<endl;
        cout<<"5.显示学生成绩"<<endl;
        cout<<"6.退出"<<endl;
}

void AddStudents()
{
        cout<<"请输入学生信息：\n";
        cout<<"姓名： ";
        cin>>stu[num].name;
        cout<<"学号： ";
        cin>>stu[num].ID;
        num++;
}

bool DelStudents()
{
    if(num==0)
        return false;
    else
    {
        stu[num].ID=0;
        stu[num].name="";
        stu[num].score=0;
        num--;
        return true;
    }
}

void AddScore()
{
    cout<<"请依次输入学生分数信息：\n";
    for(int i=0;i<num;i++)
    {
        cout<<stu[i].name<<": ";
        cin>>stu[i].score;
    }
}

int cmp(Student a,Student b)
{
    if(a.score==b.score)
        return a.ID<b.ID;
    return a.score>b.score;
}

void Rank()
{
    sort(stu,stu+num,cmp);
}

void Show(Student *stu,int n)
{
    cout<<endl;
    cout<<endl;
    cout<<"--------------学生信息---------------"<<endl;
    cout<<endl;
    cout<<"排名     姓名         学号        成绩"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"        "<<stu[i].name<<"        "<<stu[i].ID<<"        "<<stu[i].score<<endl;
    }
    cout<<endl;
}
