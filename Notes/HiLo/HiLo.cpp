#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand (time(NULL));
    int choice,num=rand()%1000+1;
    do
    {
        cout<<"Pick a number between 1 and 1000: ";
        cin>>choice;
        if (choice<num) cout<<"Too low\n";
        if (choice>num) cout<<"Too high\n";
    }
    while(choice!=num);
    cout<<"You WIN!!!";
    cin.ignore();
}
