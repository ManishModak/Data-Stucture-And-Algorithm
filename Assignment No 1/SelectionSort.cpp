#include<iostream>
using namespace std ;

void SelectionSort(int Data[],int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        int mini_index = i ;
        for(int j = i+1 ; j < size ; j++)
        {
            if(Data[j]<Data[mini_index])
            {
                mini_index = j ;
            }
        }

        if(mini_index != i)
        {
            swap(Data[mini_index],Data[i]) ;
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

    SelectionSort(Data,size) ;

    cout << "\nSorted Array: " ;
    display(Data,size) ;
    return 0 ;
}