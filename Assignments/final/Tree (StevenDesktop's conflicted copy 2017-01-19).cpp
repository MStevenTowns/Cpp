#include "Node.cpp"
#include <cstdio>
#include <iostream>
#include <queue>

template <class generic> class tree
{
	private:
		node<generic> * root;
		
	public:
        tree();
        tree(generic v);
        tree(node<generic> * in);
        
        ~tree();
        void destroy();
        void destroy(node<generic> * current);
        
        node<generic> * getRoot();
        
		void insert(generic v);
		void insert(node<generic> * rem);
		void insert(node<generic> * current,node<generic> * newNode);
        
        void remove(generic v);
        void remove(node<generic> * v);
        void remove(node<generic> * current,generic v);
        
        node<generic> * search(generic v);
        node<generic> * search(node<generic> * current, generic v);
        int getWeight();        
        
        void merge(tree<generic> * current);
        void merge(node<generic> * current);
        
        /**
         *Balancing Functions
         */
        node<generic> * rotateLeft(node<generic> * current);
        node<generic> * rotateRight(node<generic> * current);
        node<generic> * rotateLeftThenRight (node<generic> * current );
        node<generic> * rotateRightThenLeft (node<generic> * current );
        void rebalance(node<generic> * current );
        int height(node<generic> * current );
        void setBalance(node<generic> * current );
        void printBalance(node<generic> * current );
        
        /**
         *Printing functions 
         */
        void toString();
        void toString(node<generic> * current);
        
        void prettyPrint();
        void prettyPrint(node<generic> * current, int level);
        
        bool lessThan(std::string a,std::string b);
};

template <class generic> 
tree<generic>::tree()
{
	root = new node<generic>();
}

template <class generic> 
tree<generic>::tree(generic v)
{
	root = new node<generic>(v);
}

template <class generic> 
tree<generic>::tree(node<generic> * in)
{
	root = in;
}

template <class generic>
tree<generic>::~tree()
{
    destroy(root);
}

template <class generic>
void tree<generic>::destroy()
{
    destroy(root);
}

template <class generic>
void tree<generic>::destroy(node<generic> * current)
{
    if(current->getLeft()!=0)
    {
        destroy(current->getLeft());
    }
    if(current->getRight()!=0)
    {
        destroy(current->getRight());
    }
    delete current;
}

template <class generic> 
void tree<generic>::insert(generic v)//go down
{
    node<generic> * newNode=new node<generic>(v);
    insert(root,newNode);
}

template <class generic> 
void tree<generic>::insert(node<generic> * newNode)//keep going
{
    insert(root,newNode);
}

template <class generic> 
void tree<generic>::insert(node<generic> * current, node<generic> * newNode)//this is the insert function that does stuff
{
    if(lessThan(newNode->getValue(),current->getValue()))//newNode is smaller
    {
        if(current->getLeft()) 
        {
            insert(current->getLeft(),newNode);//if something is left make right new current and repeat
        }
        else 
        {
            current->setLeft(newNode);//otherwise set the newNode on the left
            current->getLeft()->setParent(current);
        }
    }
    else// newNode is greater or equal
    {
        if(current->getRight())
        {
            insert(current->getRight(),newNode);//if something is right make right new current and repeat
        }
        else 
        {
            current->setRight(newNode);//otherwise set newNode on the right
            current->getRight()->setParent(current);
        }
    }
    try
    {
        rebalance(newNode->getParent());
    }
    catch(...)
    {
        printf("no order");
    }
}

template <class generic> 
void tree<generic>::remove(generic v)//go down
{
    node<generic> * rem=search(v);
    rem->getParent()->setLeft(rem->getLeft());
    merge(rem->getRight());
    rebalance(rem->getParent());
    delete rem;
}

template <class generic> 
node<generic> * tree<generic>::search(generic v)
{
    return search(root,v);
}

template <class generic> 
node<generic> * tree<generic>::search(node<generic> * current, generic v)
{
    if(current->getValue()==v) 
    {
        return current;
    }
    else
    {
        if(current->getLeft()==0 && current->getRight()==0)
        {
            return 0;
        }
        if(lessThan(v, current->getValue()))
        {
            return search(current->getLeft(),v);
        }
        else
        {
            return search(current->getRight(),v);
        }
    }
}

template <class generic> 
int tree<generic>::getWeight()
{
    return root->getWeight();
}

template <class generic> 
void tree<generic>::merge(tree<generic> * current)
{
    merge(current->getRoot());
}

template <class generic> 
void tree<generic>::merge(node<generic> * current)
{
    if(current->getLeft())
    {
        merge(current->getLeft());
    }
    if(current->getRight())
    {
        merge(current->getRight());
    }
    insert(current->getValue());
    delete current;
}

template <class generic>
void tree<generic>::rebalance(node<generic> * current)
{
    setBalance(current);
    //printf("check1");
    if (current->balance == -2) 
    {
        if (height(current->left->left) >= height(current->left->right))
            current = rotateRight(current);
        else
            current = rotateLeftThenRight(current);
    }
    else if (current->balance == 2) 
    {
        if (height(current->right->right) >= height(current->right->left))
            current = rotateLeft(current);
        else
            current = rotateRightThenLeft(current);
    }
    //printf("check2");
 
    if (current->parent != 0) 
    {
        rebalance(current->parent);
    }
    else 
    {
        root = current;
    }
    //printf("check3");
}

template <class generic>
node<generic> * tree<generic>::rotateLeft(node<generic> * current) 
{
    node<generic> *b = current->right;
    b->parent = current->parent;
    current->right = b->left;
 
    if (current->right != NULL)
        current->right->parent = current;
 
    b->left = current;
    current->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == current) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(current);
    setBalance(b);
    return b;
}
 
template <class generic>
node<generic>* tree<generic>::rotateRight(node<generic> * current) 
{
    node<generic> *b = current->left;
    b->parent = current->parent;
    current->left = b->right;
 
    if (current->left != NULL)
        current->left->parent = current;
 
    b->right = current;
    current->parent = b;
 
    if (b->parent != NULL) {
        if (b->parent->right == current) {
            b->parent->right = b;
        }
        else {
            b->parent->left = b;
        }
    }
 
    setBalance(current);
    setBalance(b);
    return b;
}

template <class generic>
node<generic> *  tree<generic>::rotateLeftThenRight(node<generic> * current)
{
    current->left = rotateLeft(current->left);
    return rotateRight(current);
}

template <class generic>
node<generic> *  tree<generic>::rotateRightThenLeft(node<generic> * current)
{
    current->right = rotateRight(current->right);
    return rotateLeft(current);
}

template <class generic>
int tree<generic>::height(node<generic> * current)
{
    if (current == NULL)
        return -1;
    return 1 + std::max(height(current->left), height(current->right));
}

template <class generic>
void tree<generic>::setBalance(node<generic> * current)
{    
    if(current!=0) current->balance = height(current->right) - height(current->left);
}

template <class generic> 
node<generic> * tree<generic>::getRoot()
{
    return root;
}

template <class generic> 
void tree<generic>::toString()
{
    toString(root);
}

template <class generic> 
void tree<generic>::toString(node<generic> * current)
{
    if(!current) return;
    toString(current-> getLeft());
	current->toString();
	toString(current-> getRight());
}
template<class generic>
bool tree<generic>::lessThan(std::string a,std::string b)
{
    try
    {
        return std::stoi(a)<std::stoi(b);
    }
    catch(...)
    {
        int min;
        if(a.length()<b.length()) min=a.length();
        else min=b.length();
        for(int i=0;i<min;i++)
        {
            if(a.at(i)<b.at(i)) return true;
            if(a.at(i)>b.at(i)) return false;
        }
        if(a.length()<b.length()) return true;
        return false;
    }
    return false;
}

template <class generic>
void tree<generic>::prettyPrint() 
{
    std::queue< node<generic>* > nodesQueue;
    int nodesInCurrentLevel = 1;
    int nodesInNextLevel = 0;
    nodesQueue.push(root);
    while (!nodesQueue.empty()) 
    {
        node<generic> * currNode = nodesQueue.front();
        nodesQueue.pop();
        nodesInCurrentLevel--;
        if (currNode) 
        {
            std::cout << currNode->getValue() << " ";
            nodesQueue.push(currNode->getLeft());
            nodesQueue.push(currNode->getRight());
            nodesInNextLevel += 2;
        }
        if (nodesInCurrentLevel == 0) 
        {
            std::cout << std::endl;
            nodesInCurrentLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
        }
    }
}
