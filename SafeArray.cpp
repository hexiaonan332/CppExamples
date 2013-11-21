#include<iostream>
#include<string>
#include<stack>

using namespace std;

class SafeArray{
public:
    int valAt(int index);
    void showi();
    SafeArray(int cap)
    {
        data = new int [cap];
        for(int i=0;i<cap;i++)
            data[i]=i+1;
        count=cap;
    }
    ~SafeArray()
    {
        delete [] data;
    }
private:
    int *data;
    int count;
};

int SafeArray::valAt(int index)
{
    if(index<0||index>=count)
    {
        cout<<"数组下标越界！"<<endl;
        return -1;
    }
    else
        return data[index];
}

void SafeArray::showi()
{
    for(int i=0;i<count;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}

int main()
{
    SafeArray *sa = new SafeArray(10);
    sa->showi();
    cout<<sa->valAt(-1)<<endl;
    cout<<sa->valAt(3)<<endl;

    return 0;
}
