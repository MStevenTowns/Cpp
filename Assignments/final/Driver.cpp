#include "Tree.cpp"
#include <cstdio>
#include <iostream>
using namespace std;

//-std=c++11
int main()
{
    
    //double num;
    int choice;
    std::string str;
    //bool isInt=false;
    bool go=true;
    
    printf("Insert a starting value: ");
    cin >> str;
    
    tree<std::string> * t=new tree<std::string>(str);
    node<std::string> * n;
    while(go)
    {
        printf("\n1: Insert\n");
        printf("2: Remove\n");
        printf("3: Search\n");
        printf("4: Ordered Print\n");
        printf("5: Pretty Print\n");
        printf("6: Restart\n");
        printf("7: Exit\n");
        printf("Your choice: ");
        cin>>str;
        choice=stoi(str);
        switch(choice)
        {
            case 1:
                printf("What would you like to insert?: ");
                cin>>str;
                t->insert(str);
             -std=c++11   break;
            case 2:
                printf("What would you like to remove?: ");
                cin>>str;
                t->remove(str);
                break;
            case 3:
                printf("What would you like to search for?: ");
                cin>>str;
                n=t->search(str);
                if(n!=0) printf("I found it");
                n=0;
                break;
            case 4:
                printf("\n");
                t->toString();
                printf("\n");
                break;
            case 5:
                printf("\n");
                t->prettyPrint();
                break;
            case 6:
                t->destroy();
                printf("What would you like to insert?: ");
                cin>>str;
                t=new tree<std::string>(str);
                break;
            case 7:
                t->destroy();
                go=false;
                break;
        }
    }    
    return 0;
}
