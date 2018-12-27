#include <iostream>

using namespace std;

int main()
{
    string sent,input,output;
    cout<<"Give me a sentence: ";
    getline(cin,sent);
    for(int x=0;x<sent.length();x++)
    {
      sent[x]=tolower(sent[x]);
    }
    cout<<sent<<"\n";
    if (sent[sent.length()-1]=='.') sent[sent.length()-1]='!';
    for(int x=0;x<sent.length();x++)
    {
      sent[x]=toupper(sent[x]);
      sent[x]=toupper(sent[x]);
    }
    cout<<sent<<"\nWhat do you want to search for?: ";
    cin>>input;
    for(int x=0;x<sent.length();x++)
    {
      sent[x]=tolower(sent[x]);
    }
    for (int x=0;x<sent.length()-input.length();x++)
    {
        if (sent.substr(x,input.length())==input) cout<<"I found it!\n";
    }
    cout<<"What do you want to replace it with?: ";
    cin.ignore(10000,'\n');//clears up to 1000 chars from cin, until it finds enter
    getline(cin,output);
    for (int x=0;x<sent.length()-input.length()+1;x++)
    {
        if (sent.substr(x,input.length())==input)
        {
            sent=sent.substr(0,x)+output+sent.substr(x+input.length(),std::string::npos);
        }
    }
    cout<<sent;
}
