#include<iostream>
using namespace std ;

void InsertionSort(int Data[],int size)
{
    int i , j , key ;
    for(int i = 1 ; i < size ; i ++)
    {
        key = Data[i] ;
        j = i - 1 ;
        while (j>=0 && Data[j] > key)
        {
            Data[j + 1] = Data[j] ;
            j = j - 1 ;
        }  
        Data[j+1] = key ;
    }
}

void display(int Data[],int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << Data[i] << "   " ;
    }
}

void getdata(int Data[],int size)
{
    cout << "\nEnter The Numbers: " ;
    for(int i = 0 ; i < size ; i++)
    {
        cin >> Data[i] ;    
    }
}

int main()
{   
    int size = 0 ;
    cout << "\nEnter The Size of Array: " ;
    cin >> size ;

    int Data[size] ;
    getdata(Data,size) ;

    cout << "\nUnsorted Array: " ;
    display(Data,size) ;

    InsertionSort(Data,size) ;

    cout << "\nSorted Array: " ;
    display(Data,size) ;


    return 0 ;
}