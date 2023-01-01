#include<iostream>
using namespace std;

/*
Class Node To create node and constructor to initialize 
*/
class Node
{
    public:
        char Data ;
        Node* Next ;

    public:
        Node(char val)
        {
            Data = val ;
            Next = NULL ;
        }
};

/*
Class Stack 

void push(Node* &Top,char val) -- Declaring Push Method in Stack Class.
char pop(Node* &Top) -- Declaring pop Method in Stack Class.
bool isempty(Node* Top) --  Declaring isempty Method in Stack Class.
char top(Node* &Top) -- Declaring top Method in Stack Class.
*/
class Stack
{
    public:
        void push(Node* &Top,char val);
        char pop(Node* &Top) ;
        bool isempty(Node* Top) ;
        char top(Node* &Top) ;
};



/*
Class Stack 
char Stack::pop(Node* &Top) --

I.In This Method we check if stack is empty if empty then return '0'.

II.Then we return top's data in the form of temp->data.
*/
char Stack::top(Node* &Top)
{
    if(isempty(Top) == true)
    {
        return '0';
    }
    Node* Temp = Top ;
    return Temp->Data ;
}

/*
Class Stack 
bool Stack::isempty(Node* Top) --

I.In This Method we check if stack is empty if empty then return true else false.
*/
bool Stack::isempty(Node* Top)
{
    if(Top == NULL)
    {
        return true ;
    }
    return false ;
}

/*
Class Stack 

void push(Node* &Top,char val) --

I.In This Method we first create a new node n and pass the value
  Note that n is not at all connected to stack's linked list at first.

II.Then we check if Stack is empty is empty we assign top to n and return.

III.If stack is not empty we point n node's Next pointer to Top then assign Top to n.
*/
void Stack::push(Node* &Top,char val)
{
    Node* n = new Node(val);

    if(isempty(Top) == true)
    {
        Top = n ;
        return ;
    }

    n->Next = Top ;
    Top = n ;
    return ;
}

/*
Class Stack 
char Stack::pop(Node* &Top) --

I.In This Method we check if stack is empty if empty then return ch '0'.

II.Else we create node pointer n that points top.

III.Then we let the top go to next node to n.

IV.we store char of n into temp.

V.Then delete n and return character in temp.
*/
char Stack::pop(Node* &Top)
{
    if(isempty(Top) == true)
    {
        cout<<"Stack is Empty"<<endl ;
        return '0';
    }

    Node* n = Top ;
    Top = Top->Next ;
    char Temp = n->Data ;
    delete n ;
    return Temp ;
}


/*
bool isoperator(char ch) --

I.in this we check if charcter is operator or not.

II.If operator then return true else false.

*/
bool isoperator(char ch)
{
    if(ch=='+' || ch=='*' || ch == '-' || ch == '/' || ch == '(' || ch == ')')
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

/*
*int Prec(char val) -- This method gives importance(precedence) of given operatror.
*/
int Prec(char val)
{
    if(val == '^')
    {
        return 2 ;
    }
    else if(val == '*' || val == '/')
    {
        return 1 ;
    }
    else if(val == '+' || val == '-')
    {
        return 0 ;
    }
    else
    {
        return -1;
    }
}


/*

char* InfixToPostfix(char Infix[],char Postfix[]) -- This method converts infix to postfix.

I.Create Top pointer to use it in stack and s reference variable to acess methods of stack.

II.First While loop until we get '\0' value in infix array.
    i.check if charcter at i index is operator or not.
    ii.if not operator then Assign that oprand to postfix array at j'th index.
    iii.else 
        a.If character is '(' then push.
        b.else if character is ')' then pop until '(' is found.
        c.else if precedance of character at i index in infix is greater than precedance of top then push.
        d.else pop charcter from stack until if triggers.
    iv.end while.

III.Second While to pop Remaining characters in stack after infix expression is completely scannned.
    i.popping characters in postfix array.

IV.after end add '\0' to mark end os array .

V.return postfix expression.
*/
char* InfixToPostfix(char Infix[],char Postfix[])
{
    Node* Top = NULL ;
    Stack s;
    int i = 0 , j = 0 ;

    while(Infix[i] != '\0')
    {
        if(!isoperator(Infix[i]))
        {
            Postfix[j] = Infix[i];
            i++ ;
            j++ ;
        }
        else
        {
            if (Prec(Infix[i]) > Prec(s.top(Top)))
            {
                s.push(Top,Infix[i]);
                i++ ; 
            }
            else
            {
                Postfix[j] = s.pop(Top) ;
                j++ ;
            }
        }
    }

    while(s.isempty(Top) == false)
    {
        Postfix[j] = s.pop(Top) ;
        j++ ;
    }

    Postfix[j] = '\0' ;
    return Postfix ; 
}

char* InfixToPrefix(char Infix[],char Prefix[],int size)
{
    Node *Top = NULL ;
    Stack s ;
    int i = 0 , j = 0 ;

    char Data[size];

    while(Infix[i] != '\0')
    {
        if(!isoperator(Infix[i]))
        {
            Data[j] = Infix[i];
            i++ ;
            j++ ;
        }
        else
        {
            if (Prec(Infix[i]) > Prec(s.top(Top)))
            {
                s.push(Top,Infix[i]);
                i++ ; 
            }
            else
            {
                Data[j] = s.pop(Top) ;
                j++ ;
            }
        }
    }

    while(s.isempty(Top) == false)
    {
        Data[j] = s.pop(Top) ;
        j++ ;
    }
    Data[j] = '\0' ;

    j = 0 ;
    for(i = size ; i >= 0 ; i--)
    {
        Prefix[j] = Data[i] ;
        j++ ;
    }

    Prefix[j] = '\0' ;
    return Prefix ;
}

int main()
{
    char* Postfix ;
    char* infix ;
    char* Prefix ;
    int choice = -1 ;
    int size ;
    int j = 0;
    string Data;
    
    do
    {
        cout<<"1.Infix TO Postfix"<<endl ;
        cin >>choice ;
        cout<<"\n" ; 
        switch (choice)
        {
        case 1:            
            cout<<"Enter Infix Expression: " ;
            cin >> Data ;
            infix = new char[Data.length() +  1];
            for(int i = 0; i < Data.length(); i++) 
            {
                infix[i] = Data[i];
            }
            infix[Data.length()] = '\0';

            size = sizeof(infix)/sizeof(infix[0]) ;
            Postfix = new char[size] ;
            cout << "Postfix Expression is: "<< InfixToPostfix(infix,Postfix) << endl;
            break;

        case 2:
            
            cout<<"Enter Infix Expression: " ;
            cin >> Data ;
            infix = new char[Data.length() +  1];
            for(int i = Data.length(); i > 0; i--) 
            {
                infix[j] = Data[i];
                j++ ;
            }
            infix[Data.length()] = '\0';

            size = sizeof(infix)/sizeof(infix[0]) ;
            Prefix = new char[size] ;
            cout << "Prefix Expression is: "<< InfixToPrefix(infix,Prefix,size) << endl;
            break ;

        case 3:

            break;

        case 4:

            break ;
        default:
            break;
        }
    } while (choice != 0);
    
    return 0 ;
}