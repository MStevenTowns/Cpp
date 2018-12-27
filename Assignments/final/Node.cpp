#include <cstdio>
#include <iostream>

/**
 * Generic node, able to hold any value
 * */
template <class generic> 
class node
{
    private:
        
    public:
        /**
         * Data for each node
         */
        generic value;
        int balance;
        node<generic> * left;
        node<generic> * right;
        node<generic> * parent;
        /**
         * Constructors
         */
        node();
        node(generic v);
         
        /**
         * Setters:
         */
        void setLeft(node * l);
        void setRight(node * r);
        void setParent(node * p);
        void setLeft(generic v);
        void setRight(generic v);
        void setValue(generic v);
        
        /**
         * Getters:
         */
        node<generic> * getLeft();
        node<generic> * getRight();
        node<generic> * getParent();
        int getWeight();
        generic getValue();
        
        void toString();        
};

/**
 * Constructors
 */
template <class generic> 
node<generic>::node()
{
	value=0;
    left=0;
    right=0;
    parent=0;
}

template <class generic> 
node<generic>::node(generic v)
{
	value=v;
    left=0;
    right=0;
    parent=0;
}

/**
* Setters:
*/
template <class generic> 
void node<generic>::setLeft(node * l)
{
    left = l;
}

template <class generic> 
void node<generic>::setRight(node * r)
{
    right = r;
}

template <class generic> 
void node<generic>::setParent(node * p)
{
    parent = p;
}

template <class generic> 
void node<generic>::setLeft(generic v)
{
    left = new node<generic>(v);
}

template <class generic> 
void node<generic>::setRight(generic v)
{
    right = new node<generic>(v);
}

template <class generic> 
void node<generic>::setValue(generic v)
{
    value = v;
}

/**
* Getters:
*/
template <class generic> 
node<generic> * node<generic>::getLeft()
{
    return left;
}

template <class generic> 
node<generic> * node<generic>::getRight()
{
    return right;
}

template <class generic> 
node<generic> * node<generic>::getParent()
{
    return parent;
}

template <class generic> 
generic node<generic>::getValue()
{
    return value;
}

template <class generic> 
void node<generic>::toString()
{
    std::cout<<getValue()<<" ";
    
    /*int hold=0;
    hold=printf(std::to_string(getValue()).c_str());
    if(hold<=0)
    {
        printf("%i",hold);
        printf("cant print");
    }
    printf(" ");*/
}

template <class generic> 
int node<generic>::getWeight()
{
    return(left->getWeight()+right->getWeight()+1);
}
