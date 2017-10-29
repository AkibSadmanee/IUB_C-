#include<bits/stdc++.h>

using namespace std;

void make_array(int* &arr, int s);
void populate_array_rand(int* arr, int s, int h, int l);
void populate_array_user(int* arr, int s);
int get_max(int *arr,int Size);
void display_array(int* arr, int s);
int num_digit(int number);

void insertion_sort(int* arr, int Size);


int main()
{
    int *arr;   //dynamically declare array
    int Size = 0;
    int high = 0;
    int low = 0;

    cout<<"Enter Size of the Array: ";
    cin>> Size;

    make_array(arr,Size);

    bool choice;
    cout<<"How Would you like to populate the array:"<<endl;
    cout<<"0. Manually"<<endl;
    cout<<"1. Randomly"<<endl;
    cout<<endl<<"Enter choice: ";
    cin>> choice;

    if(choice){

        cout<<"Enter Highest Limit of range: ";    //higher range of random number
        cin>> high;

        cout<<"Enter Lowest Limit of range: ";   //lower range of random number
        cin>> low;

        populate_array_rand(arr, Size,high,low);
    }

    else
        populate_array_user(arr, Size);

    //Displays sample array
    cout<<"Array: "<<endl;
    display_array(arr,Size);

    //Executes sorting algorithm
    insertion_sort(arr,Size);
    cout<<endl<<endl<<endl<<endl;


    //prints sorted array
    cout<<"Sorted: "<<endl;
    display_array(arr,Size);
    cout<<endl;

    return 0;
}

void make_array(int* &arr, int Size)
{
        arr = new int[Size];    //dynamic memory allocation
}

void populate_array_rand(int* arr, int Size, int high, int low)
{
    srand(time(0));
    for(int i = 0; i < Size; i++)
    {
        arr[i] = low + rand() % (high - low +1);    //generatres random numbers in range of low & high; high & low included
    }
}


void populate_array_user(int* arr, int Size)
{
    srand(time(0));
    for(int i = 0; i < Size; i++)
    {
        int temp;
        cout<<"Enter value: ";
        cin>>temp;
        arr[i] = temp;
    }
}

int num_digit(int number)
{
    //this function counts the digits of a number
    //this number of digits is used to display result in a better format
    if(number <10) return 1;
    return 1+ num_digit(number/10);
}

int get_max(int *arr,int Size){
    int mx = arr[0];
    for(int i = 1 ; i < Size; i++){
        if(arr[i] > mx) mx = arr[i];
    }
    return mx;
}

void display_array(int* arr, int Size)
{
    int high = get_max(arr,Size);
    for(int i = 0 ; i < Size; i++)
    {
        if(i % 5 == 0 && i != 0) cout<<endl;
        cout<<setw(num_digit(high) + 3)<<arr[i];
    }
}

void insertion_sort(int* arr, int Size)
{
    for(int i = 1; i < Size; i++) //i is the card-dealer
                                //i will go through the array and give us the next number that has to be compared
    {
        int key = arr[i];   //key is the value that will be compared with the already sorted array
        int j = i - 1;      //compare key with all values from 0 to i of array with the help of j

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;   //places key to its rightful place
    }
}

