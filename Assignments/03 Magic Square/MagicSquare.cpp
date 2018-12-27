#include <iostream>
using namespace std;


int input();
void makeMagic(int nums[15][15],int size);
void printMagic(int nums[15][15],int size);

int main()
{
    int nums[15][15]={0};
    int size=input();
    makeMagic(nums,size);
    printMagic(nums,size);
}

int input()
{
    
    int size=0;
    bool go=false;
    while (go==false)
    {
       
        cout<<"How many units wide do you want your magic square?: ";
        cin>>size;
        cin.ignore(9999, '\n');
        if(cin.good())
        {
            if (size%2==1) //makes sure the number is odd
            {
                go=true;
            }
            if ((size>15)||(size<1)) //makes sure the box will fit inside the command prompt, and is greater than 0
            {
                go=false;
            }
            if (go==false)
            {	
                cout<<"Try again, pick an odd number under 16 \n";
            }
        }
    }
    return size;
}

void makeMagic(int nums[15][15],int size)
{
    int row, column;
    for (row=0;row<size;row++)
    {
        for(column=0;row<size;row++)
        {
            nums[row][column]=0;
        }
    }
    row=(size-1);
    column=((size/2));
    nums[row][column]=1;
    for (int i=2; i<=size*size; i++) 
    {
        if (nums[(row+1)%size][(column+1)%size]==0) //checks to see if next space is occupied, even if wrapping is needed
        {
            row=((row + 1) % size); //aligns the row for the next number, wrapping as needed
            column=((column + 1) % size); //aligns the column for the next number, wrapping as needed
        }
        else //if occupied places number below original number, wrapping as needed
        {
            row=((row - 1 + size) % size); //shifts down 1 unit, wrapping as needed
        }
        nums[row][column]=i;//Places number
    }
}
void printMagic(int nums[15][15],int size)
{
    for(int i=size;i!=0;i--)
    {
        cout<<"\n";// 1 to put next row on next line the "\n" is to give space for cosmetic reasons
        for (int x=1; x<=size;x++) //control column
        {
            if ((nums[i-1][x-1])<10) 
            {
                cout<<" "<<nums[i-1][x-1]<<"   ";//lines up the numbers, giving space between them
            }
            else if ((nums[i-1][x-1])<100) //lines up numbers
            {
                cout<<" "<<nums[i-1][x-1]<<"  ";
            }
            else cout<<" "<<nums[i-1][x-1]<<" ";;
        }        
    }	
}
