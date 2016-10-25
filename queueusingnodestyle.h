#include<iostream>
using namespace std;
#include<climits>
#ifndef queue_h/*This is a kind of library of queues data structure and its basic functions like enqueue,dequeue.*/
#define queue_h/*This is implemented using linked list*/
template <typename T>
class node/*This is node class which forms basic building block of whole queue or in simple terms "it is single node of linked list where whole linked list represents queue"*/
{
    public:
    T data;
    node<T> *next;
    node(T data)
    {
        this->data=data;
        next=NULL;
    }
};
template <typename J>
class queue{
    node<J>* front;/*We maintain address of front node and end node*/
    node<J>* end;
    int total;/*This represents total number of elements present in queue at any time*/
public:
    queue()/*Initially both front and end points to NULL*/
    {
        front=NULL;
        end=NULL;
        total=0;/*Initially total number of elements are 0 which means queue is empty*/
    }
    void enqueue(J data)
    {
        total++;
        node<J> *newnode=new node<J>(data);
        if(front==NULL)/*Suppose we enqueue the first element in our queue.*/
        {/*At that point both front and end will point at same node*/
            front=newnode;
            end=newnode;
        }
        else
        {
            end->next=newnode;/*Since in queues, elements are added at end, therefore we just simply append one node at end and end points to new node now*/
            end=newnode;
        }
    }
    J dequeue()
    {
        if(isempty()==true)
        {
            cout<<"Already empty"<<endl;
            return INT_MAX;
        }

        total--;
        node<J> *temp=front;/*Since in queues, elements are deleted from front, we simply delete the first node and now front pointer points to next of front*/
        front=front->next;
        J tobereturned=temp->data;
        delete temp;
        if(front==NULL)
            end=NULL;
        return tobereturned;
    }
    bool isempty()/*This function returns the boolean value based on whether queue is empty or not.*/
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
    int returntotal()/*This returns the total number of elements present in the queue at any moment*/
    {
        return total;
    }
    ~queue()
    {
        while(front!=NULL)
        {
            node<J> *temp=front;
            front=front->next;
            delete temp;

        }
    }

};
#endif // queue_h
