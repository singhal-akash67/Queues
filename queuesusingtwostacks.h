#include<climits>
#ifndef queuesusingtwostacks
#define queuesusingtwostacks
template <typename T>
class node
{
    public:
    T data;
    node<T>* next;
    node(T data)
    {
        this->data=data;
        next=NULL;
    }

};
template <typename S>
class stack
{
    public:
    node<S>* top;
    int total;
    stack()
    {
        total=0;
        top=NULL;
    }
    void push(S data)
    {
        node<S>* newnode=new node<S>(data);
        if(top==NULL)
        {
            top=newnode;
        }
        else
        {
            newnode->next=top;
            top=newnode;

        }
        total++;
    }
    S pop()
    {
        if(isempty()==true)
        {
            return INT_MAX;
        }
        node<S> *k=top;
        top=top->next;
        S tobereturned=k->data;
        delete k;
        total--;
        return tobereturned;
    }
    bool isempty()
    {
        if(total==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
template <typename Q>
class queue
{
public:
    stack<Q> a;
    stack<Q> b;
    void enqueue(Q data)
    {
        a.push(data);
    }
    Q dequeue()
    {

           while(a.total>1)
            {
                b.push(a.pop());
            }
            int tobereturned=a.pop();
            while(b.total>1)
            {
                a.push(b.pop());
            }
            return tobereturned;



    }
    bool isempty()
    {
        if(a.isempty()==true&&b.isempty()==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
#endif // queuesusingtwostacks
