#include <iostream>
#include <math.h>

using namespace std;

bool isAlphaNumeric(string str);
bool isAlpha(string str);
bool isLower(string str);
bool isUpper(string str);
bool isNumeric(string str);

int toInt(string str);


int main()
{
    string test="15";    
}
int toInt(string str)
{
    if(isNumeric(str))
    {
        return -1;
    }
    else return -1;
}
bool isAlphaNumeric(string str)
{
        if (isAlpha(str)||isNumeric(str)) return true;
        return false;
}
bool isAlpha(string str)
{
    return(isUpper(str)||isLower(str));
}
bool isUpper(string str)
{
    for(int i=0; (unsigned)i<str.size();i++)
    {
       if((str[i]>=65)&&(str[i]<=90));
       else return false;//0
    }
    if(str.size()>=1) return true;//1
    return false;//0
}
bool isLower(string str)
{
    for(int i=0; (unsigned)i<str.size();i++)
    {
       if((str[i]>=97)&&(str[i]<=122));
       else return false;//0
    }
    if(str.size()>=1) return true;//1
    return false;//0
}
bool isNumeric(string str)
{
    int i=0;
    if (str[0]=='-')i++;
    for(;(unsigned)i<str.size();i++)
    {
       if((str[i]>=48)&&(str[i]<=57));
       else return false;//0
    }
    if(str.size()>=1) return true;//1
    return false;//0
}

