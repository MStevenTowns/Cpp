#include <iostream>
#include <stdlib.h> 
using namespace std;

void print(const int nums[3][3]);
bool isWin(const int nums[3][3],int s);
int getChoice(const int nums[3][3]);
bool isValidChoice(const int nums[3][3],int choice);
int player(const int nums[3][3]);
int computer(const int nums[3][3]);

int main()
{
    int nums[3][3]={{7,8,9},{4,5,6},{1,2,3}};
    
    int choice=0;
    int x,y;
    while(!isWin(nums,10)&& !isWin(nums,11))//10=O  11=X
    {
        choice=player(nums);
        if (choice==1)
        {
            x=2;
            y=0;
        }
        if (choice==2)
        {
            x=2;
            y=1;
        }
        if (choice==3)
        {
            x=2;
            y=2;
        }
        if (choice==4)
        {
            x=1;
            y=0;
        }
        if (choice==5)
        {
            x=1;
            y=1;
        }
        if (choice==6)
        {
            x=1;
            y=2;
        }
        if (choice==7)
        {
            x=0;
            y=0;
        }
        if (choice==8)
        {
            x=0;
            y=1;
        }
        if (choice==9)
        {
            x=0;
            y=2;
        }
        nums[x][y]=11;
        choice=computer(nums);
        if (choice==1)
        {
            x=2;
            y=0;
        }
        if (choice==2)
        {
            x=2;
            y=1;
        }
        if (choice==3)
        {
            x=2;
            y=2;
        }
        if (choice==4)
        {
            x=1;
            y=0;
        }
        if (choice==5)
        {
            x=1;
            y=1;
        }
        if (choice==6)
        {
            x=1;
            y=2;
        }
        if (choice==7)
        {
            x=0;
            y=0;
        }
        if (choice==8)
        {
            x=0;
            y=1;
        }
        if (choice==9)
        {
            x=0;
            y=2;
        }
        nums[x][y]=10;
    }
    
    cout<<"\n";
    print(nums);
    return 0;
}
//need to add smart picking
int computer(const int nums[3][3])
{
    int choice=0;
    while(choice==0)
    {
        choice=rand()%9+1;
        if(isValidChoice(nums,choice))
        {
            return choice; 
        }
        else
        {
            choice=0;
        }
    }
    return 0;
}
int player(const int nums[3][3])
{
    int choice=0;
    while(choice==0)
    {
        print(nums);
        cout<<"\nwhere do you want to play?: ";
        try {cin>>choice;}
        catch(...){choice=0;}
        if(choice<1||choice>9)
        {
            choice=0;
        }
        if(!isValidChoice(nums,choice)) choice=0;
    }
    return choice;
}

bool isValidChoice(const int nums[3][3],int choice)
{
    if(choice<1||choice>9) return false;
    int x,y;
    if (choice==1)
    {
        x=2;
        y=0;
    }
    if (choice==2)
    {
        x=2;
        y=1;
    }
    if (choice==3)
    {
        x=2;
        y=2;
    }
    if (choice==4)
    {
        x=1;
        y=0;
    }
    if (choice==5)
    {
        x=1;
        y=1;
    }
    if (choice==6)
    {
        x=1;
        y=2;
    }
    if (choice==7)
    {
        x=0;
        y=0;
    }
    if (choice==8)
    {
        x=0;
        y=1;
    }
    if (choice==9)
    {
        x=0;
        y=2;
    }
    if(nums[x][y]<10) return true;
    return false;
    
}

bool isWin(const int nums[3][3],int s)
{
    for(int x=0;x<3;x++)
    {
        if(nums[x][0]==s && nums[x][1]==s && nums[x][2]==s) 
            {	
                cout<<"winner";
                return true;
            }
    }
    
    for(int y = 0; y < 3; y++)
    {
        if(nums[0][y]==s && nums[1][y]==s && nums[2][y]==s) 
            {
                cout<<"winner";
                return true;
            }
    }
    
    if(nums[0][0]==s && nums[1][1]==s && nums[2][2]==s) 
        {
            cout<<"winner";
            return true;
        }
    if(nums[0][2]==s && nums[1][1]==s && nums[2][0]==s) 
        {
            cout<<"winner";
            return true;
        }
    return false;
}

void print(const int nums[3][3])
{
    cout<<endl<<endl<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(nums[i][j]==10) cout<<"O";
            else if(nums[i][j]==11) cout<<"X";
            else cout<<nums[i][j];
            cout<<"  ";
        }
        cout<<"\n\n";
    }
}
