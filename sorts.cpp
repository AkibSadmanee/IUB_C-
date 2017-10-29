/*
This file contains 4 sorting procedures.
1. Insertion Sort
2. Merge Sort
3. Bubble Sort
4. Quick Sort

All are programed to sort in "Ascending order".
This code contains a lot of console prints to ensure user sophistication.
So the program run time may be slower than your expectations.
However, if you use the sort functions without these I/O interference,
you can run the code with more speed.
*/
#include<bits/stdc++.h>     //includes all necessary librabies for c++ standard
using namespace std;

void make_array(int* &arr, int Size);
void populate_array(int* arr, int Size, int high, int low);
int num_digit(int number);
int get_max(int *arr,int Size);
void display_array(int* arr, int Size);


void bubble_sort(int* arr, int Size);
void insertion_sort(int* arr, int Size);

void merge(int* arr, int left, int mid, int right);
void merge_sort_core(int* arr,int left,int right);
void merge_sort(int* A, int s);

int pivot(int *A, int l, int r);
void swap (int &x, int &y);
void quick_sort_core(int *A, int l, int r);
void quick_sort(int* A, int s);

int main()
{
    int* arr;
    int Size = 10000;   //number of elements of the array
    int high = 1234;    //highest value that the array can hold
    int low = 10;       //lowest value that the array can hold

    //Creates an sample array that has to be sorted
    make_array(arr,Size);
    populate_array(arr,Size,high,low);
    cout<<endl<<"Sample Array:"<<endl;
    display_array(arr,Size);

    char choice;
    cout<<endl<<"Choose Sorting Algorithm: "<<endl;
    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Merge Sort"<<endl;
    cout<<"3. Bubble Sort"<<endl;
    cout<<"4. Quick Sort"<<endl;

    cout<<endl<<"Enter your choice: ";
    cin>>choice;

    if(choice == '1')   //Insertion Sort call
        insertion_sort(arr,Size);

    else if(choice == '2')  //Merge Sort call
        merge_sort(arr,Size);

    else if(choice == '3')  //Bubble Sort call
        bubble_sort(arr,Size);

    else if(choice == '4')  //Quick Sort call
        quick_sort(arr,Size);

    else
    {
        cout<<"Input is not Valid";
        return 0;

    }

    cout<<endl<<"Sorted Array:"<<endl;
    display_array(arr,Size);


    return 0;
}


void make_array(int* &arr, int Size)
{
    //allocates memory for array dynamically
        arr = new int[Size];
}

void populate_array(int* arr, int Size, int high, int low)
{
    //populates the array
    srand(time(0));
    for(int i = 0; i < Size; i++)
    {
        arr[i] = low + rand() % (high - low +1);
    }
}

int num_digit(int number)
{
    //counts digits of a number to set padding recursively
    //for organized display
    if(number <10) return 1;
    return 1 + num_digit(number/10);
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
        if(i % 9 == 0 && i != 0) cout<<endl;
        cout<<setw(num_digit(high) + 3)<<arr[i];
    }
    cout<<endl;
}


void insertion_sort(int* arr, int Size)
{
    for(int i = 1; i < Size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge_sort_core(int* arr,int left,int right)
{
    //this function depends on merge(int* ,int, int, int)
    if(right > left)
    {
        int mid = (left+right)/2;
        merge_sort_core(arr,left,mid);
        merge_sort_core(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void merge(int* arr,int left,int mid,int right)
{
    //allocates memory for left array dynamically
    int* left_arr;
    int left_size = mid - left + 1;
    make_array(left_arr, left_size);

    //allocates memory for right array dynamically
    int* right_arr;
    int right_size  = right - mid;
    make_array(right_arr, right_size);

    //copy data from main array to new container arrays
    //copy first half to left array
    for(int i = 0; i < left_size; i++)
        left_arr[i] = arr[left + i];


    //copy second half to right array
    for(int i = 0; i < right_size; i++)
        right_arr[i] = arr[mid + 1 + i];


    //merge left & right arrays
    int left_ind = 0;
    int right_ind = 0;

    for(int i = left; i <= right; i++)
    {
        //if left array reaches boundary
        if(left_ind == left_size)
        {
            arr[i] = right_arr[right_ind];
            right_ind++;
        }

        //if right array reaches boundary
        else if(right_ind == right_size)
        {
            arr[i] = left_arr[left_ind];
            left_ind++;
        }

        else
        {
            //when element of left array < element of right array
            //arr[i] will copy data from left array
            if(left_arr[left_ind] < right_arr[right_ind])
            {
                arr[i] = left_arr[left_ind];
                left_ind++;
            }
            //when element of left array >= element of right array
            //Which also means element of right array < element of left array
            //arr[i] will copy data from right array
            else
            {
                arr[i] = right_arr[right_ind];
                right_ind++;
            }
        }

    }


}


void bubble_sort(int* arr, int Size)
{
    for (int i = 0; i < Size-1; i++)
    {
        //decrease j each time as the right side is being sorted
        //from max on the right to min on the left in every step
        //in each loop we need to compare i times of elements less
        //after the first iteration of i, the maximum number is on the right-most position
        //so we don't need to compare that right-most position with any numbers of the array
        //as we already know that the rightmost number is the largest.
        //so we need to compare (Size-1)-1 items for the coming iteration
        //after the 2nd iteration the 2nd largest number will be in the 2nd rightmost place
        //so we need to compare (Size-1)-2 items for the coming iteration
        //thus we can generalize the number of items to be
        //compared to (Size-1)-i for the coming iterations
        for (int j = 0; j < Size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
                swap(arr[ j ], arr[ j+1 ]);
        }

    }

}


int pivot(int *arr, int left, int right){
    int piv = left;     //sets a pointer to the starting point
    int pivot = arr[left];  //the pivot value

    for(int i = left +1; i <= right; i++){
        if(arr[i] <= pivot){
            piv++;
            swap(arr[i], arr[piv]);
        }
    }
    swap(arr[left], arr[piv]);      //the last swap to place the pivot value to its rightful place
    return piv;     //returns the position where the pivot value is saved
}

void swap (int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}


void quick_sort_core(int *A, int left, int right){
    if(left<right){    //base case is when l >= r
        int p = pivot(A,left,right);
        quick_sort_core(A,left,p-1);
        quick_sort_core(A,p+1,right);
    }
}

void quick_sort(int* A, int s)
{
    // wrapper function for easier call
    quick_sort_core(A,0,s-1);
}


void merge_sort(int* A, int s)
{
    // wrapper function for easier call
    merge_sort_core(A,0,s-1);
}
