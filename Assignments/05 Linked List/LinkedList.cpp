#include <iostream>

using namespace std;

struct node
{
    int value;
    node* next;
};


bool insert(node*& head,int value);
bool remove(node*& head,int value);
void destroy(node*& head);
node * search(node * head_node, int num);
void print(node* head);

int main()
{
    node* head=NULL;
    int choice;
    do{
        choice=0;
        cout<<"1) Insert"<<endl;
        cout<<"2) Remove"<<endl;
        cout<<"3) Search"<<endl;
        cout<<"4) Print"<<endl;
        cout<<"5) Restart"<<endl;
        cout<<"6) Quit"<<endl;
        cout<<"what do you want to do?"<<endl;
        
        cin>>choice;
        if(choice==1)
        {
            cout<<"what value do you want to insert?: ";
            cin>>choice;
            insert(head,choice);
        }
        else if(choice==2)
        {
            cout<<"what value do you want to remove?: ";
            cin>>choice;
            remove(head,choice);
        }
        else if(choice==3)
        {
            cout<<"what value do you want to find?: ";
            cin>>choice;
            search(head,choice);
        }
        else if(choice==4)
        {
            print(head);
        }
        else if(choice==5)
        {
            destroy(head);
        }
        else if(choice==6)
        {
            choice=-1;
        }
        else choice=0;
    }while(choice!=-1);
    
    destroy(head);
    return 0;
}

node* search(node * head, int num)
{
    node* current = head;
    
    while (current && current->value<num) 
    {
        current=current->next;
    }
    
    if (current && current->value==num) return current;
    return NULL;
}
bool insert(node*& head,int value)
{
    node* newNode=new node;
    newNode->value=value;
    newNode->next=NULL;
    
    if(head==NULL)
    {
        head=newNode;
    }
    
    else
    {
        node* current=head;
        while(current->next)
        {
            if(current->value==newNode->value) 
            {
                cout<<"bad input"<<endl;
                return 1;
            }
            else current=current->next;
        }
        if(current->value==newNode->value) 
        {
            cout<<"bad input"<<endl;
            return 1;
        }
        current->next=newNode;
    }
    
    return 0;
}
bool remove(node*& head,int value)
{
    node * dead = search(head, value);
    if(dead)//if node is in the list
    {
        node * current = head;
        node * prev = NULL;
        while(current != dead)
        {
            prev=current;
            current=current->next;
        }
        if(!prev && !current->next) head=NULL;//head is only node in list
        else if(!prev) head=current->next;//head is to be deleted
        else if (!current->next) prev->next=NULL;//end of list
        else prev->next=current->next;//in middle of list
        delete dead;
        return 0;
    }
    else return 1;
}

void print(node* head)
{
    node* current=head;
    cout<<"\n\n";
    while(current!=NULL)
    {
        cout<<(current->value)<<endl;
        current=current->next;
    }
    cout<<"\n\n";
}

void destroy(node*& head)
{
    cout<<"test"<<endl;
    node* previous;
    while(head!=NULL)
    {
        previous=head;
        head=head->next;
        delete previous;
    }
}
