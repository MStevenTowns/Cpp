#include <iostream>

using namespace std;

int big(int num);
void instruct();
int get();
void print(int num,int num2);

int main()
{
    instruct();
    int num=get();
    print(num,big(num));
    return 0;
}

void instruct()//Procedure to display the introduction to the program
{
    cout<<"This program will take a number then it will cube the number and print both.\n";
}

int get()//Function to get user input and return it to main.
{
    cout<<"Give me a number: ";
	int num;
    cin>>num;
    return num;
}

int big(int num)//Function to cube the number (raise by a factor of 3).
{
    return num*num*num;
}

void print(int num,int bignum)//Procedure to print out the original number and the cubed number.
{
    cout<<"\nThe origninal number: "<<num;
    cout<<"\nThe bigger number: "<<bignum;
}
