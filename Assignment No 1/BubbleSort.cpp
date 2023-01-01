#include<iostream>
using namespace std ;

void BubbleSort(int Data[],int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if(Data[j] > Data[j+1])
            {
                swap(Data[j] , Data[j+1]) ;
            }
        }
    }
}

void display(int Data[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << Data[i] << "  " ;
    }
}

void getdata(int Data[],int size)
{
    cout << "Enter the elements: " ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> Data[i] ;
    }
}

int main()
{
    int size ;
    cout << "Enter Size of Array: " ;
    cin >> size ;

    int Data[size] ;
    getdata(Data,size) ;

    cout << "\nUnsorted Array: " ;
    display(Data,size) ;

    BubbleSort(Data,size) ;

    cout << "\nSorted Array: " ;
    display(Data,size) ;

    return 0;
}