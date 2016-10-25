#ifndef queue_h
#define queue_h
template <typename T>
class queue
{
    T *array;
    int front;
    int rear;
    int totalelements;/*This member represents the total number of elements at any situation*/
    int size;/*This member represents the size of queue*/
public:
    queue()/*This is parameterless constructor which does not take size from user and initializes size to 10*/
    {
        size=10;
        front=-1;
        rear=-1;
        totalelements=0;
        array=new T[size];/*allocating array according to the size*/
    }
    queue(int size)/*This constructor helps user to allocate size of queue according to his/her own will*/
    {
        this->size=size;
        front=-1;
        rear=-1;
        totalelements=0;
        array=new T[size];/*allocating array according to the size*/
    }
    void enqueue(T data)
    {

        if(isfull()==false)/*This statement checks whether the queue is empty or not*/
        {
            rear=(rear+1)%(size);
            if(front==-1)
            {
                front=0;
            }
            array[rear]=data;
            totalelements++;
        }
        else
        {
            cout<<"sorry queue is full"<<endl;/*if queue is full, operation will not be executes*/
            return;
        }
    }
    T dequeue()
    {
        if(isempty()==true)
        {
            return -1;
        }
        else
        {
            totalelements--;
            T tobereturned;
            if(front==rear)
            {
                 tobereturned=array[front];
                front=-1;
                rear=-1;
            }
            else
            {
                 tobereturned=array[front];
                front=(front+1)%size;
            }

            return tobereturned;
        }
    }
    bool isempty()
    {
        if(front==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isfull()
    {
        if((front==0&&rear==size-1)||rear==front-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int returntotal()
    {
        return totalelements;
    }
    ~queue()
    {
        delete array;
    }
};
#endif // queue_h
