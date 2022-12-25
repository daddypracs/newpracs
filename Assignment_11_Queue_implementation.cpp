#include <iostream>
#define MAX 10
using namespace std;

class Queue
{
    int data[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void enqueue(int x);
    void dequeue();
    void display();
};
bool Queue::isEmpty()
{
    if (rear == -1 && front == -1)
    {
        return true;
    }
    return false;
}
bool Queue::isFull()
{
    if ((rear == MAX - 1 && front == 0))
    {
        return true;
    }
    return false;
}

void Queue::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else if (rear == -1 && front == -1)
    {
        rear += 1;
        front += 1;
        data[rear] = x;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        data[rear] = x;
    }
    else
    {
        rear += 1;
        data[rear] = x;
    }
}
void Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue UnderFlow" << endl;
    }
    else
    {
        front += 1;
    }
}

void Queue::display()
{
    int i;
    for (i = front; i <= rear; i++)
        cout << data[i] << " ";
}
int main()
{
    Queue j;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Enter your choice\n1) Add Job\n2) Delete Job\n3) CheckFull\n"
             << endl;
        int n;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter Data" << endl;
            int d;
            cin >> d;
            j.enqueue(d);
            break;
        case 2:
            j.dequeue();
            break;
        case 3:
            j.isFull();
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
        j.display();
        cout << endl;
        cout << "Do you want to continue(y/n)" << endl;
        cin >> ch;
    }
    cout << "Exit Program Thank You!!" << endl;
    return 0;
}