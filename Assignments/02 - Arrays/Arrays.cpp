#include <iostream>

using namespace std;

typedef void (*VoidFunctionWithThreeParameters)(double nums[],int &size,int max);

bool menu(double nums[],int &size,int max);
int whereInList(double nums[],int value,int size);
int getNum();

void add(double nums[],int &size,int max);
void remove(double nums[],int &size,int max);
void find(double nums[],int &size,int max);
void sort(double nums[],int &size,int max);
void print(double nums[],int &size,int max);
void status(int code);

int main()//list is a pointer, doesn't need to be returned, don't need & symbol
{
    const int max=25;//use constant to set value for compile time
    int size=0;//next fillable space
    double nums[max]={0};
    bool go=true;
    while(go)go=menu(nums,size,max);
    return 0;
}

bool menu(double nums[],int &size,int max)
{
    bool out=true;
    string menu[]={"Add an Element","Remove an Element","Find an Element","Print the List","Exit"};
    VoidFunctionWithThreeParameters functions[]={add,remove,find,print};
    int len=4;
    for(int i=1;i<len+2;i++)
    {
        cout<<"\n"<<i<<")"<<menu[i-1];
    }
    cout<<"\nWhat do you want to do?: ";
    int choice=getNum();
    cout<<"\n";
    choice-=1;//changes from user display to array refrences
    if (choice<len){functions[choice](nums,size,max);}
    else if(choice==len) out=false; 
    return out;  
}

int getNum()
{
    double num;
    cin>>num;
    num=(num*num)/num;
    return num;
}

void find(double nums[],int &size,int max)
{
    cout<<"What number would you like to find?: ";
    double value=getNum();
    int place=whereInList(nums,value,size);
    if(place>=0)
    {
        cout<<value<<" is at index "<<place+1<<".\n";
    }
    else status(2);
}

void add(double nums[],int &size,int max)
{
    cout<<"What number would you like to add?: ";
    double value=getNum();
    if(whereInList(nums,value,size)==-1)
    {
        if(size+1<=max)
        {
            nums[size]=value;
            size++;
            sort(nums,size,max);//status code in the sort function
        }
        else status(3);//exceded max size
    }
    else status(1);//already in list
}

void remove(double nums[],int &size,int max)
{
    cout<<"What number would you like to remove?: ";
    double value=getNum();
    int location=whereInList(nums,value,size);
    if(location>=0)
    {
        for(int i=location;i<size+1;i++)
        {
            nums[i]=nums[i+1];
            
        }
        size--;
        status(0);//action successful
    }
    else status(2);//not in list
}

int whereInList(double nums[], int value,int size)//fix later
{
    for(int i=0;i<size;i++)
    {
		if (nums[i]==value) return i;
	}
	return -1;
}

void sort(double nums[],int &size,int max)
{
    double hold;
    for(int i=size-1;i>0;i--)
    {
        if(nums[i]<nums[i-1])
        {
            hold=nums[i-1];
            nums[i-1]=nums[i];
            nums[i]=hold;
        }
    }
    status(0);//Action successful
}

void print(double nums[],int &size,int max)
{
    if(size>0)
    {
        for(int i=1;i<size+1;i++)
        {
            cout<<nums[i-1]<<" ";
            if(i%5==0&&i!=0) cout<<"\n";
        }
        cout<<"\n";
    }
    else status(4);//nothing to print
}

void status(int code)
{
    if(code==0) cout<<"Action Successful.";
    else if(code==1) cout<<"That number is already in the list.";
    else if(code==2) cout<<"That number isn't in the list.";
    else if(code==3) cout<<"You have exceded the maximum size for this list.";
    else if(code==4) cout<<"There is nothing to print.";
    else cout<<"I don't know what to do with that code.";
    cout<<"\n";
}
