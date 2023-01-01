#include<iostream>
using namespace std ;

class Node
{
    public:
        int Data;
        Node* Next;

    public:
        Node(int val)
        {
            Data = val ;
            Next = NULL ;
        }
};

class Stack
{
    public:
        int pop(Node* &Top);
        void push(Node* &Top,int val);
        bool isempty(Node* Top);
        bool isfull(Node* Top);
};

bool Stack::isfull(Node* top)
{
    Node* n = (Node*)malloc(sizeof(Node)) ;
    if(n==NULL)
    {
        return true ;
    }
    return false ;
}

bool Stack::isempty(Node* Top)
{
    if(Top == NULL)
    {
        return true ; 
    }
    return false;
}

int Stack::pop(Node* &Top)
{
    Node* n = Top ;

    if(isempty(Top) == true)
    {
        return INT32_MIN;
    }

    Top = Top->Next ;
    int Temp = n->Data ;
    delete n ;
    return Temp ;
}

void Stack::push(Node* &Top,int val)
{
    if(isfull(Top) == true)
    {
        cout<<"Stack Overflow"<<endl ;
    }
    else
    {
        Node* n = new Node(val);
        if(isempty(Top) == true)
        {
            Top = n ;
            return ;
        }
        n->Next = Top ;
        Top = n ;
    }
    
}

void display(Node* Top)
{
    Node* Temp = Top ;
    while (Temp != NULL)
    {
        cout<<Temp->Data<<"->";
        Temp = Temp->Next ;
    }
    cout<<"NULL" ;
}

int main()
{
    int choice = -1 ;
    int Data = -1 ;
    Node* Top = NULL ;
    Stack s;

    do
    {
        cout<< "1.Push" <<endl ;
        cout<< "2.Pop"  <<endl ;
        cout<< "3.isempty"<<endl ;
        cout<< "4.isfull" <<endl ;
        cout<< "5.display"<<endl ;
        cout<< "Enter the Choice: " ;
        cin >> choice ;
        cout<<"\n" ;
        switch (choice)
        {
        case 1:
            cout<< "Enter The Value: " ;
            cin >> Data ;
            s.push(Top,Data);
            cout<<"\n" ;
            break;
        
        case 2:
            cout<< s.pop(Top) << " Element has been popped" <<endl ;
            cout<<"\n" ;
            break;

        case 3:
            if(s.isempty(Top) == true)
            {
                cout<<"Stack is Empty"<<endl ;
                break;
            }
            cout<<"Stack is not empty"<<endl ;
            cout<<"\n" ;
            break;

        case 4:
            if(s.isempty(Top) == true)
            {
                cout<<"Stack is full"<<endl ;
            }
            else
            {
                cout<<"Stack is not full"<<endl  ;
            }
            break;

        case 5:
            display(Top) ;
            cout<<"\n" ;
            break;

        case 0:
            cout<<"End Of Program"<<endl ;
            break;

        default:
            cout<<"Enter A valid Choice" ;
            cout<<"\n" ;
            break;
        }
    } while (choice != 0);
    
    return 0 ;
}