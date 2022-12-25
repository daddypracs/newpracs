#include <iostream>
#include <string>
using namespace std ;
// template class stack
template <typename t>
class stack
{
    public: 
    int capacity ;
    int top_ptr = -1;  
    int top ;
    t arr[100];
    public : 
    stack(int capacity)
    {
        this-> capacity = capacity ;
    }

    void push(t elm)
    {
        if (top_ptr == capacity - 1)
        {
            cout<<"Stack overflow"<<endl;

        }
        else 
        {
            top_ptr++;
            arr[top_ptr] = elm ; 
            top = elm ;
        }
        
    }   

    void display()
    {
        for (int i = 0 ; i <= top_ptr ; i++)
        {
            cout<<arr[i]<<endl; 
        }
    }

    void pop ()
    {
        top_ptr--; 
    }
};

int main()
{
    stack<char> s(100);
    string expression ; 
    cout<<"Enter mathematical expression : "<<endl;
    cin>>expression ; 
    
    for (int i = 0 ; i < expression.size(); i++)
    {
        if (expression[i]=='(' || expression[i] == '[' || expression[i] == '{')
        {
            s.push(expression[i]);
        }
        else if ( expression[i]==')' || expression[i] == ']' || expression[i] == '}')
        {
            if (expression[i] == ')' && s.top == '(')
            {
                s.pop();
            }
            else if (expression[i] == ']' && s.top == '[')
            {
                s.pop();
            }
            else if (expression[i] == '}' && s.top == '{')
            {
                s.pop();
            }
        }   
    }

    if (s.top_ptr == -1)
    {
        cout<<"correct expression"<<endl;
    }
    else 
    {
        cout<<"incorrect expression"<<endl;
    }
    return 0 ; 
}