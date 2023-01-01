#include<iostream>
using namespace std ;

struct Student
{
    int roll_no ;
    string name ;
    double SGPA ;
};

/*
*In Bubble Sort we compare two adjacent numbers and swap them if initial no. > no. next to initial
*First Loop
*   - 0 to size-1 
*Second Loop
*   - 0 to size-i-1 bcoz when i = 1 last position will be fixed and so on..
* Time Complexity: O(N2)
* Auxiliary Space: O(1) 
*/
void BubbleSort(Student Sd[],int size)
{
    for(int i = 0 ; i < size - 1 ; i++)
    {
        for(int j = 0 ; j < size - i - 1 ; j++)
        {
            if (Sd[j].roll_no > Sd[j+1].roll_no)
            {
                swap(Sd[j],Sd[j+1]) ;
            }            
        }
    }
}

/*
*In quicksort we use recursive method
*we divide array into sub arrays
*Left sub array will get lower values than key
*Right Sub array will get higher values than key this goes on 
*until array is sorted
*/
int partition(Student Sd[],int low,int high)
{   
    Student pivot = Sd[high] ;

    int i = low - 1 ;

    for(int j = low ; j < high ; j++)
    {
        if(Sd[j].SGPA <= pivot.SGPA)
        {
            i++ ;
            swap(Sd[i],Sd[j]) ;
        }
    }

    swap(Sd[i+1],Sd[high]) ;
    return i+1 ;
}

void quicksort(Student Sd[],int low , int high)
{
    if(low < high)
    {
        int pi = partition(Sd,low,high) ;

        quicksort(Sd , low , pi-1) ;

        quicksort(Sd , pi+1 , high) ;
    } 
}

/*
*In Insertion Sort we get greater value than key we swap them until lower value pair is found
*for e.g in ARRAY {1,2,6,7,3,9}
*      - When we will compare 1 and 2 they are in right order so nothing will happen same for 
*        2 and 6 , 6 and 7
*      - But when 7 and 3 will come it is not ion right order so they will swap 
*      - then agian same thing for 6 and 3 after swapping
*      - when in right order it will move to next pair i.e 7 and 9
*      Time Complexity: O(N^2) 
*      Auxiliary Space: O(1)
*/
void InsertionSort(Student Sd[],int size)
{
    int i , j ;
    Student key ;
    for(int i = 1 ; i < size ; i++)
    {
        key = Sd[i] ;
        j = i - 1 ;
        while (j>=0 && Sd[j].name > key.name)
        {
            Sd[j+1] = Sd[j] ;
            j = j - 1 ;
        }
        Sd[j+1] = key ;  
    }
}

/*
*In binarySearch 
*Begin with the mid element of the whole array as a search key.
*If the value of the search key is equal to the item then return an index of the search key.
*Or if the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
*Otherwise, narrow it to the upper half.
*Repeatedly check from the second point until the value is found or the interval is empty.
*
* Time Complexity: O (log n)
* Auxiliary Space: O (1)
*/
void BinarySearch(Student Sd[],int size,string key)
{
    cout<<"Roll_No"<<"  "<<"SGPA"<<"  "<<"Name"<<endl;

    int low = 0 , high = size - 1 ;    
    
    while(low <= high)
    {
        int mid = (low + high) / 2;

        if (Sd[mid].name == key)
        {
            cout<<Sd[mid].roll_no<<"  "<<Sd[mid].SGPA<<"  "<<Sd[mid].name<<endl ;
            low = mid + 1 ;
        }
        else if(Sd[mid].name < key)
        {
            low = mid + 1 ;
        }
        else
        {
            high = mid - 1 ;
        }  
    }
}

/*
*In Linear Search we search through whole array and print when value is equal to key
*
*Time complexity: O(N)
*Auxiliary Space: O(1)
*/
void LinearSearch(Student Sd[],int size,double key)
{
    cout<<"Roll_No"<<"  "<<"SGPA"<<"  "<<"Name"<<endl;
    for(int i = 0 ; i < size ; i++)
    {
        if(Sd[i].SGPA == key)
        {
            cout<<Sd[i].roll_no<<"  "<<Sd[i].SGPA<<"  "<<Sd[i].name<<endl ;
        }
    }
}


/*
* display method to display All students data.
*/
void display(Student Sd[],int size)
{
    cout<<"Roll_No"<<"  "<<"SGPA"<<"  "<<"Name"<<endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout<<Sd[i].roll_no<<"  "<<Sd[i].SGPA<<"  "<<Sd[i].name<<endl ;
    }
}

int main()
{
    int choice = -1 ;
    int size = 0;
    double SGPA;
    string name ;
    struct Student * Sd = NULL;
    do
    {
        cout<<"1.Enter Student Data"<<endl ;
        cout<<"2.List Acc To Roll_No (Bubble Sort)"<<endl;
        cout<<"3.List Acc To Name (Insertion Sort)"<<endl;
        cout<<"4.List Acc To SGPA (Quick Sort)"<<endl;
        cout<<"5.Search Student Acc To SGPA (Linear Search)"<<endl;
        cout<<"6.Search Student Acc To Name (Binary Search)"<<endl;
        cout<<"0.End The Program"<<endl;
        cout<<"Enter choice: ";
        cin >>choice ; 
        cout<<"\n";

        switch(choice)
        {
        case 1 :
            cout<<"Enter Total No. of Students: " ;
            cin >>size ;
            Sd = new struct Student [size] ;

            for(int i = 0 ; i < size ; i++)
            {
                cout<<"Enter Name: " ;
                cin >> Sd[i].name ;
                cout<<"Enter Roll_no: ";
                cin >> Sd[i].roll_no ;
                cout<<"Enter SGPA: ";
                cin >> Sd[i].SGPA ;
            }

            cout<<"\n";
            break;

        case 2:
            BubbleSort(Sd,size);
            display(Sd,size);
            cout<<"\n";
            break;

        case 3 :
            InsertionSort(Sd,size);
            display(Sd,size);
            cout<<"\n";
            break ;

        case 4:
            quicksort(Sd,0,size-1);
            display(Sd,size);
            cout<<"\n";
            break ;

        case 5:
            cout<<"Enter the SGPA to be searched: ";
            cin >> SGPA ;    
            LinearSearch(Sd,size,SGPA);
            cout<<"\n";
            break ;

        case 6:           
            cout<<"Enter the Name to be searched: ";
            cin >> name ; 
            BinarySearch(Sd,size,name);
            cout<<"\n";
            break;

        case 0:
            cout<<"End of Program";
            cout<<"\n" ;
            cout<<"\n";
            break ;

        default:
            cout<<"Please Enter From Available Choices" ;
            cout<<"\n";     
        }
    }while(choice != 0);
}