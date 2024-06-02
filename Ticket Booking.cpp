/*Q5.The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Singly linked list has to be
maintained to keep track of free seats at rows. Assume some random booking to start
with. Use array to store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.
*/

#include<iostream>
using namespace std;
class Seat
{
	public:
	int status;
	int stno;
	
	Seat * next;
	Seat()
	{
		status = 0;
		next = NULL;
	}
	Seat(int x, int s)
	{
		stno = s;
		status = x;
		next = NULL;
	}	
};
class Theatre
{
	Seat * head[10];
	public:
		Theatre()
		{
			for(int i = 0; i<= 9; i++)
			{
				head[i] = NULL;
			}
			
		}	
		void create()
		{
			Seat *p;
			int i = 0;
			int j = 2;
			while(i<11)
			{
				head[i] = new Seat(0,1);
				p = head[i];
				
				while(j < 8)
				{
					p -> next = new Seat(0, j);
					p = p -> next;
					j++;
				}
				
				p = p -> next;
				i++;
				
			}
			//	cout<<"\n		Created ";
			}
		
		int displayav(int row)
		{
			Seat * p = head[row-1];
			cout<<"\nAvailable seats = ";
			int count =0;
			while( p!= NULL)
			{
				if(p -> status == 0)
				{
					cout<<p -> stno<<" ";
					count++;
				}
				p = p -> next;
			}
			cout<<endl;
			
			return count;	
		}
		void booktkt(int row, int s)
		{
			Seat * p = head[row-1];
			
			while(p != NULL)
			{
				if(p -> stno == s)
				{
					p -> status = 1;
					
				}
				
				p = p -> next;
				
			}
			
			cout<<"\nBOOKED ";	
		}
		void canceltkt(int row, int s)
		{
			Seat * p = head[row-1];
			while( p!= NULL)
			{
				if(p ->stno == s)
				{
					p -> status = 0;
					
				}
				p = p -> next;	
			}	
		}	
};
int main()
{
	 Theatre obj;
	 obj.create();
	 
	 
	 int choice, row, s;	
	/*obj.booktkt(1,3);
	obj.booktkt(1,4);
	cout<<obj.displayav(1);
	obj.canceltkt(1,3);	
	cout<<obj.displayav(1);     
	*/while(1)
	{
		cout<<"\n		WELCOME  \n\nEnter operations you want to perform: \nPress \n1. Book ticket\n2. Display available seats\n3. To cancel the booking \n4. To stop ";
         cin>>choice;	 
	 	switch(choice)
	 	{
	 		
	 	case 1: cout<<"\nEnter row and seat number = ";
	 			cin>>row>>s;
	 			obj.booktkt(row, s);
				break;
					
		case 2: cout<<"\nEnter row number = ";
				cin>>row;
				cout<<obj.displayav(row);
				break;
					
		case 3: cout<<"\nEnter row and seat number = ";
				cin>>row>>s;
				obj.canceltkt(row, s);  
				break;
					
		case 4: exit(0);
				break;
		
		default: cout<<"\nInvalid choice ";
					break;
						  
		}
	}  
	cout<<"\n			THANK YOU ";
		 	
}
