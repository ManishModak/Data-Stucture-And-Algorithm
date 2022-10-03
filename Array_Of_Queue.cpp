#include<iostream>
using namespace std ;
#define max 6

class queue
{
	int Arr[max] ;
	int front , rear , x ;
	//static int count = 0 ;
	public :
		queue()
		{
			front = -1 ;
			rear = -1 ;
			//count ++ ;
		}
		int empty() ;
		int full() ;
		void Enqueue(int) ;
		int Dequeue() ;
		void Display() ;
		//static int Count() ;
};

int queue :: empty ()
{
	if (rear == -1)
		return 1 ;
	else
		return 0 ;
}

int queue :: full ()
{
	if (rear == max-1)
		return 1 ;
	else
		return 0 ;
}

void queue :: Enqueue (int x)
{
	if (empty())
	{
		front = rear = 0 ;
		Arr [rear] = x ;
	}
	else
	{
		rear ++ ;
		Arr [rear] = x ;
	}
		
}

int queue :: Dequeue ()
{	
	 int X = Arr [front] ;
	 if (rear == front)
 	{
		 front = rear = -1 ;
	}
	
	 else
 	{
		 front++ ;
 	}

	return x ;

}

void queue :: Display ()
{
	for ( int i = front ; i <= rear  ; i++ )
	{
		cout << Arr [i] << "\t" ;
	}

}

/*int queue :: Count()
{
	return count ;
}*/

int main()
{
	int x , choice  ;
	queue Q;

	do
	{
		cout << "Enter 1. Enqueue " << endl;
		cout << "Enter 2. Dequeue " << endl;
		cout << "Enter your choice : " ;
		cin >> choice ;
		switch(choice)
		{
			case 1 :
				cout << "Enter The No." ;
                                cin >> x ;
                                Q.Enqueue(x) ;
				/*int count = 0 ;
				if ( count == max)
				{
					cout << "Cannot Insert Data Queue Is Full" ;
				}
				else
				{
					cout << "Enter The No." ;
          cin >> x ;
          Q.Enqueue(x) ;
					count ++ ;
				}*/
				cout << "\nEnter 3. Display" << endl ;
			  cout << "Enter 4. EXIT" << end l ;
				cout << "OR" << endl ;	
				break ;
			case 2 :
				Q.Dequeue() ;	
				cout << "\nEnter 3. Display" << endl ;
        cout << "Enter 4. EXIT" << endl ;
				cout << "OR" << endl ;
				break ;	
			case 3 :
				Q.Display() ;
				cout << "\nEnter 4. EXIT" << end l ;
				cout << "OR"<< end l ;
				break ;
			case 4 :
				cout << "Operation Has Ended"<< endl ;
		}
	}while(choice != 4 );

	return 0 ;

}
