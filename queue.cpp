/*
	Program to implement the queue data-structure

	110H14 -- Arjun Krishna Babu

	COMPILER	: G++
	OS			: Ubuntu 12.04 LTS
	Processor	: 4th gen Intel i5

*/

#include<iostream>
#define SIZE 5
using namespace std;

class Queue	{
private:
	int A[SIZE];
	int front;
	int rear;
public:
	Queue()	{
		front = -1;
		rear  = -1;
	}

	bool empty()	{	//returns true if queue is empty, false otherwise
		if(front == -1 && rear == -1)
			return true;
		else
			return false;
	}

	bool full()	{		//returns true if queue if full, false otherwise
		if(front == 0 && rear == SIZE-1)
			return true;
		else if(rear == front - 1)
			return true;
		else
			return false;
	}

	void enque(int a)	{	

		if( full() )	{	//if queue is full
			cout<<"\n ERROR! Overflow!";
			return;
		}

		else	{	//if there is space in queue
			if( empty() )	{	//if there is no elements
				front = 0;
				rear = 0;
				A[rear] = a;
				return;
			}

			else if(front > 0 && rear == SIZE-1)	{
				rear = 0;
				A[rear] = a;
			}
			else
				A[++rear] = a;
		}
	}
	
	int deque()	{
		int temp;
		if( empty() )	
			cout<<"\n ERROR! Underflow!";
		else	{
			
			if(front == rear)	{	//when deleting the only element of the queue
				temp = A[front];
				front = rear = -1;
				return temp;
			}
			else if(front == SIZE - 1)	{
				temp = A[front];
				front = 0;
				return temp;
			}
			else	{	// if(front < rear)
				return A[front++];
			}
		} //end of outer else
	}

	void dispall()	{
		int i;

		if( empty() )
			cout<<"\n ERROR! There are no elements in queue!";
		else	{
			if(front <= rear)	{
				if(front > 0)
					for(i=0; i < front; i++)
						cout<<" "<<"...";

				for(i=front; i <= rear; i++	)	
					cout<<" "<<A[i];
				
				if(rear < SIZE - 1)
					for(   ; i < SIZE; i++)
						cout<<" "<<"...";
			}
			if(rear < front)	{
/*
				for(i=front; i < SIZE; i++)
					cout<<" "<<A[i];

				cout<<"...wrap around...";
*/	
				for(i=0; i <= rear; i++)
					cout<<" "<<A[i];		
			
				for( ; i < front; i++)
					cout<<" "<<"...";

				for(i=front; i < SIZE; i++)
					cout<<" "<<A[i];


			} //end of second if	
		} //end of outer else
	}
	
};

int main()	{

	Queue Q;

	int choice = 4;
	int num = 0;

	do
	{	cout<<"\n\n\n [CIRCULAR QUEUE IMPLEMENTATION]\n";
		cout<<"\n 1: Enque";
		cout<<"\n 2: Deque";
		cout<<"\n 3: Display all elements";
		cout<<"\n 4: EXIT!";
		cout<<"\n\n Enter Your Choice: "; cin>>choice;

		switch(choice)	{
			case 1: cout<<"\n Enter an element to insert: "; cin>>num;
					Q.enque(num);
					break;
			case 2: cout<<"\n Dequed element: "<<Q.deque();
					break;
			case 3: cout<<"\n ELEMENTS IN THE QUEUE: ";
					Q.dispall();
					break;
			case 4: cout<<"\n THANK YOU FOR USING THIS PROGRAM!";
					cout<<"\n This program has been developed by Arjun Krishna Babu (https://github.com/arjunkbabu)";
					break;
//					return;
		   default: cout<<"\n INVALID CHOICE!";
		 }
	}while(choice != 4);

   cout<<"\n\n";
   return 0;	
}
