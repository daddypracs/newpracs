#include <iostream>
using namespace std;

class Stack
{
public:
    char data[30];
    int top;

    Stack()
    {
        top = -1;
    }
    void push(char s);
    void pop();
    bool isEmpty();
    bool isFull();
    char return_top();
    string display();
};

string Stack::display()
{
    string s = "";
    for (int i = 0; i <= top; i++)
    {
        s = s + data[i];
    }
    return s;
}

bool Stack::isEmpty()
{
    if (top == -1)
    {
        return true;
    }
    return false;
}

bool Stack::isFull()
{
    if (top == 29)
    {
        return true;
    }
    return false;
}

void Stack::push(char ch)
{
    if (isFull())
    {
        cout << "Stack Ovreflow" << endl;
    }
    else
    {
        top++;
        data[top] = ch;
    }
}
void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }
    top--;
}
char Stack::return_top()
{
    return data[top];
}
int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}
int main()
{
    Stack k;
    string s, str;
    cout << "Enter Expression " << endl;
    cin >> s;

    for (int i = 0; i < s.length(); i++)
    {
        // opening bracket condition
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            k.push(s[i]);
        }

        // operand condition
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            str = str + s[i];
        }

        // operator condition
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            if (k.return_top() == '(' || k.top == -1)
            {
                k.push(s[i]);
            }
            else
            {
                while (precedence(s[i]) <= precedence(k.return_top()))
                {
                    str = str + k.return_top();
                    k.top--;
                }
                k.push(s[i]);
            }
        }

        else if (s[i] == ')')
        {
            while (k.return_top() != '(')
            {
                str = str + k.return_top();
                k.top--;
            }
            k.pop();
        }
        cout << s[i] << "   " << k.display() << "   " << str << endl;

    }

    while (k.isEmpty() != true)
    {
        str = str + k.return_top();
        k.top--;
    }


cout << str;

return 0;
}