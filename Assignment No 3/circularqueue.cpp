#include<iostream>
using namespace std;

struct CircularQueue
{
    public:
        int size;
        int front;
        int rear;
        int* arr;
};

bool isempty(struct CircularQueue *q)
{
    if(q->front == q->rear)
    {
        return true ;
    }
    return false ;      
}

bool isfull(struct CircularQueue* q) 
{
    if((q->rear+1)%q->size == q->front)
    {
        return true ;
    }
    return false ; 
}

void enqueue(struct CircularQueue* &q,int val)
{
    if(isfull(q) == true)
    {
        cout << "Queue Overflow" <<endl ;
    }
    else
    {
        q->arr[q->rear] = val ;
        q->rear = (q->rear+1)%q->size ;  
    }
}

int dequeue(struct CircularQueue* &q)
{
    int val ;
    if(isempty(q) == true)
    {
        cout << "Queue Empty" <<endl ;
        return 0 ;
    }
    else
    {
        q->front = (q->front+1)%q->size ;
        val = q->arr[q->front] ;
    }
    return val ;
}

void display(struct CircularQueue* q)
{
    int temp = q->front ;
    while (temp != q->rear)
    {
        cout << q->arr[temp] ;
        temp = (temp+1)%q->size ;
    }
    
}

int main()
{
    int size = 0 , val , choice = -1;
    struct CircularQueue *q = new CircularQueue ;
    q->front = q->rear = 0 ;
    cout<<"Provide Size of Queue: " ;
    cin >> size ;
    q->size = size+1;
    q->arr = new int[q->size] ;

    do
    {
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"Enter The choice: " ;
        cin >> choice ;
        cout<<"\n" ;

        switch (choice)
        {
        case 1:
            cout << "Enter The Value: " ;
            cin >> val ;
            enqueue(q,val) ;
            cout <<"\n" ;
            break;
        
        case 2:
            cout << dequeue(q) << " Value has been Dequeued" ;
            cout <<"\n" ;
            break;
        
        case 3:
            cout << "Elements in CircularQueue: " ;
            display(q) ;
            cout <<"\n" ;
            break ;

        case 0:
            cout << "End of Program" << endl ;
            cout <<"\n" ;
            break;

        default:
            cout << "Enter From Available options" ;
            cout <<"\n" ;
            break;
        }
    } while (choice != 0);
    
    return 0 ;
}