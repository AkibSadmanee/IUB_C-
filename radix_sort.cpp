//implementing radix sort with c++
#include<bits/stdc++.h>
using namespace std;

void make_array(int* &arr, int S);
void populate_array(int *A, int s, int low, int high);
int num_digit(int number);
void display_array(int* arr, int Size, int high);

void counting_sort(int *arr, int Size, int);
int power(int x, int n);
int get_max(int *arr,int Size);
int get_ith_digit(int number, int pos);
void radix_sort(int *arr, int Size);

int main()
{
    int *arr;
	int Size = 100;
	int low = 0;
	int high = 1230;
	srand(time(0));
    
    make_array(arr,Size);
    populate_array(arr,Size,low,high);
    display_array(arr, Size, high);
    radix_sort(arr,Size);
    cout<<endl<<"Sorted array: "<<endl;
    display_array(arr, Size, high);
    
    return 0;
}

void make_array(int* &A, int S){
	A = new int[S];
}

void populate_array(int *A, int s, int low, int high){
	for(int i = 0; i < s; i++){
		A[i] = low + rand() % (high - low +1);
	}
}

int num_digit(int number)
{
    //number of digits in a number
    if(number <10) return 1;
    return 1+ num_digit(number/10);
}

void display_array(int* arr, int Size, int high)
{
    for(int i = 0 ; i < Size; i++)
    {
        if(i % 5 == 0 && i != 0) cout<<endl;
        cout<<setw(num_digit(high) + 3)<<arr[i];
	}
	cout<<endl;
}

int power(int x, int n){
    //calculates power in O(lgn)

    if(n == 1) return x;    //base case
    int temp =  power(x, n/2);
    if(n % 2 == 0)return temp * temp; //for even powers
    else return x*temp*temp;    //for odd powers
}

int get_ith_digit(int number, int pos){
    //takes 2 parameters : 1st- number  2nd-position
    //this function finds the digit in the given number
    //that is in the position of 2nd parameter
    
    int x = power(10,pos);
    return (number/x) % 10; 
}


void counting_sort(int *A, int Size, int pos){
int *F = new int[10];
int *B = new int[Size];

for(int i = 0; i < 10; ++i) F[i]=0;
for(int i = 0; i < Size ; i++) F[get_ith_digit(A[i], pos)]++;
for(int i = 1; i < 10 ; i++) F[i] += F[i-1];
for(int i = Size -1; i >= 0 ; i--) 
    B[--F[get_ith_digit(A[i], pos)]] = A[i];
for(int i = 0; i < Size ; i++) A[i] = B[i];
}

int get_max(int *arr,int Size){
    int mx = arr[0];
    for(int i = 1 ; i < Size; i++){
        if(arr[i] > mx) mx = arr[i];
    }
    return mx;
}



void radix_sort(int *arr, int Size){
    int mx_dig = num_digit(get_max(arr, Size));
    for(int i =1; i <= mx_dig; i++){
        counting_sort(arr,Size,i);
    }
}
