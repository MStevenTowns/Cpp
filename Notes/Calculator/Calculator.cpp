#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string str;
    int x;
    double num1,num2;
    bool go=true;
    do
    {
        x=0;num1=0;num2=0;
        cout<<"Give me a math problem: ";
        getline(cin,str);
        str.erase(std::remove(str.begin(),str.end(),' '),str.end());
        if (!str.empty())
        {
            do
            {
                if (not(isdigit(str.at(x))))
                {
                    if (str.at(x)=='.'){}
                    else
                    {
                        num1=atof(str.substr(0,x).c_str());
                        num2=atof(str.substr(x+1,std::string::npos).c_str());
                        str=str.substr(x,1);
                        go=false;
                    }
                }
                x++;
            }
            while(go);
            go=true;
            if (str=="+")
            {
                cout<<"\nThe answer is: "<< num1+num2;
            }
            else if (str=="-")
            {
                cout<<"\nThe answer is: "<< num1-num2;
            }
            else if (str=="*")
            {
                cout<<"\nThe answer is: "<< num1*num2;
            }
            else if (str=="/")
            {
                cout<<"\nThe answer is: "<< num1/num2;
            }
            cout<<"\n\nAgain? (Yes): ";
            getline(cin,str);
            str=tolower(str[0]);
            if (str=="n")
            {
                go=false;
            }
        }
    }
    while(go);
}
