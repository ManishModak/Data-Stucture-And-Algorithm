#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
    char Data;
    Node *Left , *Right;
};

class Stack
{
    Node *Data[30] = {NULL};
    int top ;

    public:
        Stack()
        {
            top = -1 ;
        }

        bool empty()
        {
            if(top == -1)
            {
                return true;
            }
            return false;
        }

        void push(Node*Top)
        {
            top++;
            Data[top] = Top ;
        }

       Node* pop()
        {
            Node *Temp = Data[top];
            top--;
            return Temp;     
        }

};

class Expression
{
    public:
        Node* createfrompostfix(char postfix[]);
        Node* createfromprefix(char prefix[]);
        void inorder(Node* root);
        void postorder(Node* root);
        void preorder(Node* root);
        void non_recInorder(Node* root);
        void non_recPostorder(Node* root);
        void non_recPreorder(Node* root);
};

Node* Expression::createfrompostfix(char postfix[])
{
    Stack s ;
    char c ;
    Node *Top,*t1,*t2,*root;
    for(int i = 0 ; postfix[i] != '\0' ; i++)
    {
        c = postfix[i] ;
        if(isalnum(c))
        {
            Top = new Node;         
            Top->Left = NULL ;
            Top->Right = NULL ;
            Top->Data = c ;
            s.push(Top) ;
        }
        else
        {
            t1 = s.pop();
            t2 = s.pop();
            Top = new Node;
            Top->Data = c;
            Top->Left = t1;
            Top->Right = t2;
            s.push(Top); 
        }
    }

    root = s.pop();
    return (root) ;
}

Node* Expression::createfromprefix(char prefix[])
{
    Stack s ;
    char c;
    Node *Top,*t1,*t2,*root;
    int len = strlen(prefix)-1;

    while(len > -1)
    {
        c = prefix[len] ;
        if(isalnum(c))
        {
            Top = new Node;
            Top->Data = c;
            Top->Left = NULL;
            Top->Right = NULL ;
            s.push(Top);
        }
        else
        {
            t1 = s.pop();
            t2 = s.pop();
            Top = new Node;
            Top->Data = c;
            Top->Left = t1 ;
            Top->Right = t2 ;
            s.push(Top) ;
        }
        len--;
    }

    root = s.pop();
    return root;
}

void Expression::inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->Left);
        cout<<" "<<root->Data;
        inorder(root->Right);
    }
}

void Expression::postorder(Node* root)
{
    if(root != NULL)
    {
        postorder(root->Left);
        postorder(root->Right);
        cout<<" "<<root->Data;
    }
}

void Expression::preorder(Node* root)
{
    if(root != NULL)
    {
        cout<<" "<<root->Data;
        preorder(root->Left);
        preorder(root->Right);
    }
}

void Expression::non_recInorder(Node* root)
{
    Stack s;
    while(!s.empty() || root!= NULL)
    {
        while(root != NULL)
        {
            s.push(root) ;
            root = root->Left;       
        }
        root = s.pop() ;
        cout<<" "<<root->Data;
        root = root->Right;
    }
}

void Expression::non_recPostorder(Node* root)
{
    Stack s;
    char Data[30];
    int i = 0 ;
    while(!s.empty() || root!= NULL)
    {
        while(root!=NULL)
        {
            Data[i] = root->Data;
            i++;
            s.push(root);
            root = root->Right; 
        }
        root = s.pop() ;
        root = root->Left ;
    }

    while(i != 0)
    {
        i--;
        cout<<" "<<Data[i];  
    }
}

void Expression::non_recPreorder(Node* root)
{
    Stack s;
    while(!s.empty() || root!=NULL)
    {
        while(root != NULL)
        {
            cout<<" "<<root->Data;
            s.push(root);
            root = root->Left;
        }
        root = s.pop();
        root = root->Right;
    }
}

int main()
{
    int choice=-1;
    int i ;
    string s ;
    char* postfix = NULL ;
    char* prefix = NULL ;
    Node* root = NULL ;
    Expression e ;
    
    do
    {
        cout<<"1.Create Expression Tree(Postfix)"<<endl ;
        cout<<"2.Create Expression Tree(Prefix)"<<endl ;
        cout<<"3.Recursive Traversals"<<endl ;
        cout<<"4.Non-Recursive Traversals"<<endl ;
        cout<<"0.End The Program"<<endl ;
        cout<<"Enter The Choice: " ;
        cin >> choice ;
        cout<<"\n";

        switch (choice)
        {
        case 1:
           
            cout<<"Enter the Expression: " ;
            cin >> s ;
            postfix = new char[s.length()+1];
            for(i=0 ; i < s.length() ; i++)
            {
                postfix[i] = s[i] ;
            }
            postfix[s.length()] = '\0' ;
     
            root = e.createfrompostfix(postfix);
            cout<<"\n";
            break;
        
        case 2:
           
            cout<<"Enter the Expression: " ;
            cin >> s ;
            prefix = new char[s.length()+1];
            for(i=0 ; i < s.length() ; i++)
            {
                prefix[i] = s[i] ;
            }
            prefix[s.length()] = '\0' ;

            root = e.createfromprefix(prefix);
            cout<<"\n";
            break ;

        case 3:
            cout<<"\nPreorder Traversal";
            e.preorder(root);
            cout<<"\nInorder Traversal";
            e.inorder(root);
            cout<<"\nPostorder Traversal";
            e.postorder(root);
            cout<<"\n\n";
            break ;

        case 4:
            cout<<"\ninorder Traversal";
            e.non_recInorder(root);
            cout<<"\npreorder Traversal";
            e.non_recPreorder(root);
            cout<<"\nPostorder Traversal";
            e.non_recPostorder(root);
            cout<<"\n\n";
            break ;

        case 0:
            cout<<"End of Program";
            cout<<"\n";
            break ;

        default:
            cout<<"Please Enter From Available Choices!!";
            cout<<"\n";
            break;
        }
    } while (choice != 0);
    
    return 0 ;
}