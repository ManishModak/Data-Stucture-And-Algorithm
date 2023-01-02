#include<iostream>
using namespace std ;

void heapify(int Data[],int size,int root)
{
    int largest = root ;

    int l = 2*root + 1 ;

    int r = 2*root + 2 ;

    if(l < size && Data[l] > Data[largest])
    {
        largest = l ;
    }

    if(r < size && Data[r] > Data[largest])
    {
        largest = r ;
    }

    if(largest != root)
    {
        swap(Data[root],Data[largest]) ;

        heapify(Data,size,largest) ;
    }
}

void heapsort(int Data[],int size)
{
    for(int i =(size/2) - 1 ; i >= 0 ; i--)
    {
        heapify(Data,size,i) ;
    }

    for(int i = size-1 ; i > 0 ; i--)
    {
        swap(Data[0] , Data[i]) ;

        heapify(Data,i,0) ;
    }
}

void display(int data[],int size)
{   
    for(int i = 0 ; i < size ; i++)
    {
        cout<< data[i] << "  " ;
    }
}

int main()
{
    int Data[] = {8,3,5,2,9} ;
    int size = sizeof(Data)/sizeof(Data[0]) ;

    heapsort(Data,size) ;
    display(Data,size) ;

    return 0 ;
}