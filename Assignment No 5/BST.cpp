#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
    int data;
    Node *Left,*Right;

    Node(int val)
    {
        data = val;
        Left = NULL ;
        Right = NULL ;
    }
};

Node* InsertBST(Node* &root,int val)
{
    if(root == NULL)
    {
        return new Node(val);
    }

    if(val<root->data)
    {
        root->Left = InsertBST(root->Left,val);
    }
    else
    {
        root->Right = InsertBST(root->Right,val);
    }

    return root;
}

Node* SearchBST(Node* root,int key)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == key)
    {
        return root;
    }

    if(root->data > key)
    {
        return SearchBST(root->Left,key);
    }
    else
    {
        return SearchBST(root->Right,key);
    }
}

Node* inordersucess(Node* root)
{
    Node* curr = root ;
    while(curr && curr->Left != NULL)
    {
        curr = curr->Left ;
    }
    return curr ;
}

Node* DeleteBST(Node* root,int key)
{
    if(root->data > key)
    {
        root->Left = DeleteBST(root->Left,key);
    }
    else if(root->data < key)
    {
        root->Right = DeleteBST(root->Right,key);
    }
    else
    {
        if(root->Left == NULL)
        {
            Node* temp = root->Right;
            free(root);
            return temp;
        }
        else if(root->Right == NULL)
        {
            Node* temp = root->Left;
            free(root);
            return temp;
        }
        else
        {
            Node* temp = inordersucess(root->Right);
            root->data = temp->data; 
            root->Right = DeleteBST(root->Right,temp->data);
        }
    }
    return root ;
}

int depth(Node* root)
{
    if(root ==  NULL)
    {
        return 0 ;
    }
    else
    {
        return max(depth(root->Left),depth(root->Right))+1 ;
    }
}

void display(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    
    cout<<"Parent Node: " << root->data << endl;

    if(root->Left != NULL)
    {
        cout<<"Left Child Node: " << root->Left->data<<endl;
    }
    else
    {
        cout<<"Left Child Node: " << "NULL" <<endl ;
    }

    if(root->Right != NULL)
    {
        cout<<"Right Child Node: " << root->Right->data << endl ;
    }
    else
    {
        cout<<"Right Child Node: " << "NULL" << endl ;
    }
    cout<<"\n" ;
    display(root->Left);
    display(root->Right);
}

void display_leaf_node(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    if(root->Left == NULL && root->Right == NULL)
    {
        cout<<"Leaf Node Data: "<<root->data<<endl ;
    }

    display_leaf_node(root->Left);
    display_leaf_node(root->Right);
}

void Inorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    Inorder(root->Left);
    cout<<" "<<root->data;
    Inorder(root->Right);
}

void Preorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    cout<<" "<<root->data;
    Preorder(root->Left);
    Preorder(root->Right);
}

void Postorder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }
    Postorder(root->Left);
    Postorder(root->Right);
    cout<<" "<<root->data;
}

int main() 
{
    int choice,value ;
    Node *root = NULL ;
    do
    {
        cout<<"1.Insert"<<endl;
        cout<<"2.Traversals"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Depth Of BST"<<endl;
        cout<<"6.Display Parent & Child Node"<<endl ;
        cout<<"7.Display Leaf Nodes"<<endl;
        cout<<"0.End The Program"<<endl;
        cout<<"Enter The Choice: ";
        cin >>choice ;
        cout<<"\n" ;
        
        switch (choice)
        {
        case 1:

            cout<<"Enter The value: " ;
            cin >>value ;
            root = InsertBST(root,value);
            cout<<"\n" ;
            break;
        
        case 2:
        
            cout<<"\nInorder Traversal: ";
            Inorder(root);
            cout<<"\nPreorder Traversal: ";
            Preorder(root);
            cout<<"\nPostorder Traversal: ";
            Postorder(root);
            cout<<"\n\n" ;
            break;

        case 3:
            cout<<"Enter THe Value To Be Searched: ";
            cin >>value ;
            if(SearchBST(root,value)==NULL)
            {
                cout<<"Key Doesn't Exists"<<endl ;
            }
            else
            {
                cout<<"Key Exists";
            }
            cout<<"\n\n";
            break;

        case 4:
            cout<<"Enter THe Value To Be Deleted: ";
            cin >>value ;
            root = DeleteBST(root,value);
            break ;

        case 5:
            cout<<"Depth Of BST is: "<< depth(root) << endl ;
            cout<<"\n";
            break;
        
        case 6:
            display(root);
            cout<<"\n\n";
            break;

        case 7:
            display_leaf_node(root);
            cout<<"\n\n";
            break;

        case 0:
            cout<<"End Of Program"<<endl;
            cout<<"\n" ;
            break;

        default:
            cout<<"Please Enter From Available Choices!!"<<endl ;
            cout<<"\n" ;
            break;
        }
    } while (choice != 0);
    
    return 0;
}