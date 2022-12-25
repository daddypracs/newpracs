#include <iostream>
#include <string>
using namespace std;

template <typename t>
class item
{
    public:
    t data ;
    int priority ;

    public:
    item()
    {
        data = 0 ;
        priority = 0;
    }
    item(t data, int priority)
    {
        this->data = data ;
        this->priority = priority;
    }
    bool operator<= ( item &i2)
    {
        return (priority <= i2.priority);
    }

    friend class priority_queue;
};
 

class priority_queue
{
    private:
    int front ;
    int rear ; 
    item<int> arr[10] ;
    int MAX = 10;

    public:

    priority_queue()
    {
        front = -1 ;
        rear = -1 ;
    }

    void enqueue(item<int> elm)
    {
        if(rear == -1 && front == -1)
        {
            rear++;
            front++;
            arr[rear] = elm;
        }

        else if (rear == MAX - 1)
        {
            cout<<"Queue is full"<<endl;
        }

        else
        {
            int j = rear;
            while (arr[j]<=elm && j>=0)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = elm;
            rear++;

        }
    }

    void dequeue()
    {
        if(front == -1)
        {
            cout<<"No item to dequeue"<<endl;
        }
        else if (front == rear)
        {
            front = -1 ;
            rear = -1 ;
        }
        else
        {
            front++;
        }
    }

    void display ()
    {
        for(int i = front ; i<=rear ; i++)
        {
            cout<<arr[i].data<<"   "<<arr[i].priority<<endl;
            
        }
    }
};

int main()
{

    item<int> i1(3,5);
    item<int>i2(4,2);
    item <int> i3(3,1) ;

    priority_queue q;
    q.enqueue(i1);
    q.enqueue(i2);
    q.enqueue(i3);
    // q.dequeue();
    q.display();
    
    
    


    return 0;
}