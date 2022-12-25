#include<iostream>
#define MAX 5
using namespace std;

class Double_Queue{
    int data[MAX];
    int rear,front;
    public:
    Double_Queue(){
        rear=-1;
        front=-1;
    }
    void insert_front(int x);
    void insert_rear(int x);
    void delete_front();
    void delete_rear();
    bool isEmpty();
    bool isFull();
    void display();
} ;
bool Double_Queue::isEmpty(){
    if(rear==-1 && front==-1){
        return true;
    }
    return false;
}

bool Double_Queue::isFull(){
    if((rear==MAX-1 && front==0)){
        return true;
    }
    return false;
}
void Double_Queue::insert_front(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }
    else if(front==0){
        cout<<"No space in front"<<endl;
    }
    else if(isEmpty()){
        front++;
        rear++;
        data[rear]=x;
    }
    else if(front!=0){
        front-=1;
        data[front]=x;
    }
}

void Double_Queue::insert_rear(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }
    else if(rear==MAX-1){
        cout<<"Queue Overflow"<<endl;
    }
    else if(isEmpty()){
        front++;
        rear++;
        data[rear]=x;
    }
    else if(rear!=MAX-1){
        rear++;
        data[rear]=x;
    }
} 

void Double_Queue::delete_front(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        front++;
    }

}

void Double_Queue::delete_rear(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        rear--;
    }
}
void Double_Queue::display(){
    int i;
    for(i=front;i<=rear;i++)
         cout<<data[i]<<" ";
    cout<<endl;
}
int main(){
    Double_Queue w;
    char ch='y';
    while (ch=='y')
    {
        cout<<"Enter your choice\n1) Add data from front\n2) Delete data from front\n3) Add data from rear\n4) Delete data from rear\n"<<endl;
        int n;
        cin>>n;
        switch (n)
        {
        case 1:
            cout<<"Enter Data"<<endl;
            int d;
            cin>>d;
            w.insert_front(d);
            break;
        case 2:
            w.delete_front();
            break;
        case 3:
            cout<<"Enter Data"<<endl;
            int p;
            cin>>p;
            w.insert_rear(p);
            break;
        case 4:
            w.delete_rear();
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
        w.display();
        cout<<endl;
        cout<<"Do you want to continue(y/n)"<<endl;
        cin>>ch;
    }
    cout<<"Exit Program Thank You!!"<<endl;
    

    return 0;
}