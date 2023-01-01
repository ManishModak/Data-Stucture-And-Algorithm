#include<iostream>
using namespace std;

void display(int Data[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << Data[i] << "   " ;
    }
}

void getdata(int Data[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cin >> Data[i] ;
    }
}

int partition(int Data[],int low,int high)
{
    int pivot = Data[high] ;

    int i = (low - 1) ;

    for(int j = low ; j < high ; j++)
    {
        if(Data[j] <= pivot)
        {
            i++ ;
            swap(Data[i],Data[j]) ;
        }
    }

    swap(Data[i+1],Data[high]) ;
    return i+1 ;
}

void quicksort(int Data[],int low,int high)
{
    if(low < high)
    {
        int pi = partition(Data,low,high) ;

        quicksort(Data , low , pi-1) ;

        quicksort(Data , pi+1 , high) ;
    }  
}

int main()
{
    int size = 0 ;
    cout << "\nEnter The Size of Array: " ;
    cin >> size ;

    int Data[size] ;

    cout << "\nEnter the Numbers: " ;
    getdata(Data,size) ;

    cout << "\nUnsorted Array: " ;
    display(Data,size) ;

    quicksort(Data , 0 , size-1);

    cout << "\nSorted Array: " ;
    display(Data,size);

    return 0 ;
}