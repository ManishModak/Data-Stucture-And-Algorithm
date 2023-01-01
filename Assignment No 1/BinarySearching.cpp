#include<iostream>
using namespace std;

void display(int Data[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << Data[i] << "   " ;
    }
}

int main()
{
    int Data[] = {1,2,5,9} ;
    int n = sizeof(Data)/sizeof(Data[0]) ;
    int low=0 , high = n , mid ;
    while (true)
    {
        mid = (low + high)/2 ;
        if(Data[mid] == 5)
        {
            cout << "position of given element is: " << mid << "\n" ;
            break;
        }
        else if ( Data[mid] < 5)
        {
            low = mid + 1 ;
        }
        else if (Data[mid] > 5)
        {
            high = mid - 1 ;
        }
               
    }

    display(Data,n) ;
    
    
    return 0 ;
}