#include <cstdio>
#include <iostream>
#include <string>

bool operator<  (const std::string& lhs, const std::string& rhs);

bool operator>  (const std::string& lhs, const std::string& rhs);

int main()
{
    bool lessThan(std::string a,std::string b)
    {
        try
        {
            return a.stoi()<b.stoi();
        }
        catch(...)
        {
            int min;
            if(a.length()<b.length()) min=a.length();
            else min=b.length();
            for(int i=0;i<min;i++)
            {
                if(a.at(i)<b.at(i)) return true
                if(a.at(i)>b.at(i)) return false
            }
            if(a.length()<b.length()) return a;
            return b;
        }
    }
    
    
}
