#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
private:
    string name;
    int id;
    double score;
public:
    Student(string,int);
    ~Student();
    void addScore(double);
    double getScore();
    string getName();
    int getId();
    friend void operator<<(ostream &,const Student &);
};

Student::Student(string _name,int _id)
{
    name = _name;
    id = _id;
    score = 0.0;
}

Student::~Student()
{

}
void Student::addScore(double _score)
{
    score = _score;
}

double Student::getScore()
{
    return score;
}

string Student::getName()
{
    return name;
}

int Student::getId()
{
    return id;
}

void operator<<(ostream &os,const Student &stu)
{
    os<<stu.name<<"\t"<<stu.id<<"\t"<<stu.score<<endl;
}

vector<Student> stu;

void options()
{
    cout<<"请选择操作:\n";
    cout<<"1.查看学生信息"<<endl;
    cout<<"2.添加学生"<<endl;
    cout<<"3.删除学生"<<endl;
    cout<<"4.录入成绩"<<endl;
    cout<<"5.退出"<<endl;
}

void information()
{
    vector<Student>::iterator ptr;
    for(ptr = stu.begin();ptr != stu.end();ptr++)
        cout<<*ptr;
}

void addStudents()
{
    string name;
    int id;
    cout<<"姓名："<<endl;
    cin>>name;
    cout<<"学号："<<endl;
    cin>>id;
    Student *student = new Student(name,id);
    stu.push_back(*student);
}

void delStudents()
{
    string name;
    cout<<"请输入要删除学生的姓名："<<endl;
    cin>>name;
    vector<Student>::iterator ptr;
    for(ptr = stu.begin();ptr != stu.end();ptr++)
    {
        if(ptr->getName() == name)
        {
            stu.erase(ptr);
            break;
        }
    }
    if(ptr == stu.end())
        cout<<"操作有误，该学生不存在！"<<endl;
}

void addScore()
{
    double score;
    vector<Student>::iterator ptr;
    for(ptr = stu.begin();ptr != stu.end();ptr++)
    {
        cout<<ptr->getName()<<":";
        cin>>score;
        ptr->addScore(score);
    }
}

int main()
{
    int op;
    while(true)
    {
        options();
        cin>>op;
        switch(op)
        {
            case 1: information();
                    break;
            case 2: addStudents();
                    break;
            case 3: delStudents();
                    break;
            case 4: addScore();
                    break;
            case 5:
                    return 0;
            default:
                    cout<<"输入错误，请重新输入！\n";
        }
    }

    return 0;
}
