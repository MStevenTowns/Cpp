#include <iostream>

using namespace std;

void proc1(int &a,int &b);
void proc2(int b,int a);
int main()
{
    int a,b;
    b=5;a=10;
    proc1(b,a);
    cout<<a<<" "<<b;//5 10
    return 0;
}
void proc1(int &a,int &b)
{
    int temp; 
    proc2(a,b);
    temp=a;
    a=b;
    b=temp;
    cout<<a<<" "<<b<<endl;//10 5
}
void proc2(int b, int a)
{
    b=b*2;
    a=a+3;
    cout<<a<<" "<<b<<endl;//13 10
}
