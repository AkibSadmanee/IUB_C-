#include<bits/stdc++.h>
using namespace std;

void make_array(int* &arr, int s);
void populate_array(int* arr, int s, int h, int l);
void display_array(int* arr, int s, int h);
int num_digit(int number);

void merge(int* A, int i, int j, int k);
void merge_sort(int* A, int left, int right);

int main()
{
    int* arr;
    int Size = 10000;
    int high = 1234;
    int low = 100;

    make_array(arr,Size);
    populate_array(arr,Size,high,low);

    cout<<"Sample: "<<endl;
    display_array(arr,Size,high);
    merge_sort(arr,0,Size-1);
    cout<<endl<<endl<<"Sorted: "<<endl;
    display_array(arr,Size,high);
    return 0;
}

void make_array(int* &arr, int Size)
{
        arr = new int[Size];
}

void populate_array(int* arr, int Size, int high, int low)
{
    srand(time(0));
    for(int i = 0; i < Size; i++)
    {
        arr[i] = low + rand() % (high - low +1);
    }
}

int num_digit(int number)
{
    if(number <10) return 1;
    return 1+ num_digit(number/10);
}

void display_array(int* arr, int Size, int high)
{
    for(int i = 0 ; i < Size; i++)
    {
        if(i % 5 == 0) cout<<endl;
        cout<<setw(num_digit(high) + 3)<<arr[i];
    }
    cout<<endl;
}

void merge(int* Arr, int left, int mid, int right)
{

    int* left_array;
    int* right_array;

    int size_left = mid - left +1;
    int size_right = right - mid;

    make_array(left_array, size_left);
    make_array(right_array, size_right);

    for(int i = 0 ; i < size_left; i++)
        left_array[i] = Arr[left + i];

    for(int i = 0 ; i < size_right; i++)
        right_array[i] = Arr[mid + 1 + i];

    int left_index = 0;
    int right_index = 0;

    for(int i = left; i <= right; i++)
    {
        if(left_index == size_left)
        {
            Arr[i] = right_array[right_index];
            right_index++;
        }

        else if(right_index == size_right)
        {
            Arr[i] = left_array[left_index];
            left_index++;
        }
        else
        {
            if(left_array[left_index] < right_array[right_index])
            {
                Arr[i] = left_array[left_index];
                left_index++;
            }
            else
            {
                Arr[i] = right_array[right_index];
                right_index++;
            }
        }

    }


}

void merge_sort(int* arr, int left, int right)
{
    if(right > left)
    {
        int mid = (left + right)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);

    }
}
