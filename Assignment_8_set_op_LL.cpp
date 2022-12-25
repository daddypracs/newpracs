#include <iostream>
using namespace std ; 

class linked_list
{
private : 
    struct node 
    {
        int data ; 
        node * next ; 
    };

public : 
    node * head ; 


    linked_list()
    {
        head = NULL ; 
    }

    void append_node(int data)
    {
        node * new_node_ptr = new node ; 
        new_node_ptr->data = data ; 
        new_node_ptr->next = NULL ; 

        if (head == NULL)
        {
            head = new_node_ptr ; 
        }
        else 
        {
            node * node_ptr = head ; 
            while (node_ptr->next != NULL)
            {
                node_ptr = node_ptr -> next ; 
            }

            node_ptr -> next = new_node_ptr ; 
        }
    }

    void display_LL()
    {
        node * nptr  = head ; 
        while (nptr!=NULL)
        {
            cout<<nptr->data<<endl;
            nptr = nptr -> next ; 
        }
    }

    friend class SE_comp ; 
};

class SE_comp 
{
private : 
    linked_list SE_comp ; 
    linked_list Venilla ; 
    linked_list ButterScotch ; 
    int class_count ; 
    int Venilla_count ; 
    int ButterScotch_count ; 

public :
    void get_data()
    {
        cout<<"Enter no of students in class :"<<endl;
        cin>>class_count;
        for (int i = 1 ; i <= class_count ; i++)
        {
            SE_comp.append_node(i);
        }

        cout<<"Enter no of students who like Venilla : "<<endl ; 
        cin>>Venilla_count;
        cout<<"Enter roll nos of students who like venilla : "<<endl;
        int roll ;
        for (int i = 0 ; i < Venilla_count ; i++)
        {            
            cin>>roll;
            Venilla.append_node(roll);
        }

        cout<<"Enter no of students who like butterscotch : "<<endl;
        cin>>ButterScotch_count; 
        cout<<"Enter roll nos of students who like butterscotch : "<<endl;
        for (int i = 0 ; i < ButterScotch_count ; i++)
        {
            cin>>roll;
            ButterScotch.append_node(roll);
        }
    }

    linked_list Venilla_and_Butterscotch()
    {
        linked_list::node * V_ptr = Venilla.head; 
        linked_list::node * B_ptr = ButterScotch.head; 
        linked_list V_and_B ; 

        while (V_ptr != NULL)
        {
            linked_list::node * B_ptr = ButterScotch.head; 
            while (B_ptr != NULL)
            {
                if (V_ptr->data == B_ptr -> data)
                {
                    V_and_B.append_node(V_ptr->data);
                }
                B_ptr = B_ptr -> next ; 
            }

            V_ptr = V_ptr->next; 
            
        }
        return V_and_B;         
    }

    linked_list either_V_or_B_not_both()
    {
        linked_list either_V_or_B_not_both_lst ; 
        linked_list V_and_B = Venilla_and_Butterscotch();

        linked_list::node * V_ptr = Venilla.head; 
        linked_list::node * B_ptr = ButterScotch.head ; 
        

        while (V_ptr != NULL)
        {
            linked_list::node * both_ptr = V_and_B.head ; 
            bool flag = true ; 
            while (both_ptr != NULL)
            {
                if (V_ptr ->data == both_ptr->data)
                {
                    flag = false ; 
                    break ; 
                }
                both_ptr = both_ptr -> next;
            }

            if (flag == true)
            {
                either_V_or_B_not_both_lst.append_node(V_ptr->data);
            }
            V_ptr = V_ptr -> next ; 
        }

        while (B_ptr != NULL)
        {
            linked_list::node * both_ptr = V_and_B.head ; 
            bool flag = true ; 
            while (both_ptr != NULL)
            {
                if (B_ptr ->data == both_ptr->data)
                {
                    flag = false ; 
                    break ; 
                }
                both_ptr = both_ptr -> next;
            }

            if (flag == true)
            {
                either_V_or_B_not_both_lst.append_node(B_ptr->data);
            }
            B_ptr = B_ptr -> next ; 
        }

        return either_V_or_B_not_both_lst ; 
    }

};

int main ()
{
    SE_comp SE02 ; 
    SE02.get_data();
    linked_list both = SE02.either_V_or_B_not_both();
    both.display_LL();
    return 0 ; 
}