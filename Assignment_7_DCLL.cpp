#include <iostream>
using namespace std ; 

class Ticket_booking_System
{
    private : 
    struct seat
    {
        int status ; 
        seat * prev ; 
        seat * next ; 
    };

    seat * first_seats = new seat[10] ;

    public :
    Ticket_booking_System()
    {
        for( int i = 0 ; i < 10 ; i++ )
        {
            seat * head = (first_seats+i) ; 
            seat * seat_ptr = head ; 
            for( int j = 0 ; j < 7; j++ )
            {
                seat_ptr -> status = 0 ; 
                seat_ptr -> next = new seat ; 
                seat_ptr -> next ->prev = seat_ptr ; 
                seat_ptr = seat_ptr -> next ;    
                
            }

            seat_ptr -> status = 0 ; 
            seat_ptr -> next = head ; 
            head -> prev = seat_ptr ; 
        }
    }

    void show_booking_status(void)
    {
       for ( int i = 0 ; i < 10 ; i++)
       {
           seat * head = first_seats+i;
           seat * seat_ptr = head;

           while (seat_ptr->next != head)
           {
               cout<<seat_ptr->status<<"  ";
               seat_ptr = seat_ptr->next;
           }
           cout<<endl;
       }
    }

    void book_seat(void)
    {
        int no_of_seats ; 
        cout<<"How many seats you want to book ?"<<endl;
        cin>>no_of_seats;

        for (int i = 0 ; i < no_of_seats ; i++)
        {
            int row, column; 
            cout<<"Enter row and column of seat you want to book :"<<endl;
            cin>>row>>column;

            seat * seat_ptr = (first_seats+row-1);
            int count = 1 ; 
            while (count != column)
            {
                seat_ptr = seat_ptr -> next;
                count++;
            }

            if (seat_ptr->status == 1)
            {
                cout<<"Seat is already booked"<<endl;
            }
            else 
            {
                seat_ptr->status = 1;
                cout<<"Seat booked successfully"<<endl;
            }
        }
    }

    void cancel_booking(void)
    {
        int seats_to_be_cancelled; 
        cout<<"How many seats do you want to cancel ?"<<endl;
        cin>>seats_to_be_cancelled;
        for (int i = 0 ; i < seats_to_be_cancelled ; i++)
        {
            int row, column ;
            cout<<"Enter row and column of seat you want to cancel :"<<endl;
            cin>>row>>column;

            seat * seat_ptr = first_seats + row -1 ;
            int count = 1 ; 
            while (count != column)
            {
                seat_ptr = seat_ptr -> next ;
                count ++ ; 
            }

            if (seat_ptr->status == 0)
            {
                cout<<"Already cancelled"<<endl;
            }

            else 
            {
                seat_ptr->status = 0 ;
                cout<<"Cancelled successfully"<<endl;
            }
        }
    }

};

int main ()
{
    Ticket_booking_System sys ;

    cout<<"---------------Menu---------------- "<<endl;
    cout<<"1.Display current Booking Status"<<endl;
    cout<<"2.Book seats"<<endl;
    cout<<"3.Cancel seats"<<endl;

    char choice = 'y';

    while (choice == 'y')
    {
        int code ; 
        cout<<"Enter operation code : "<<endl;
        cin>>code ; 

        switch (code)
        {
            case 1 : 
            sys.show_booking_status();
            break; 

            case 2 : 
            sys.book_seat();
            break;

            case 3 : 
            sys.cancel_booking();
            break;

            default : 
            cout<<"Invalid code entered"<<endl;
        }

        cout<<"Do you want to continue?[y/n]"<<endl;
        cin>>choice;
    }

    return 0 ; 
}