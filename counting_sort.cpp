/*
This program works fine for 1 digit numbers.
As counting sort is used just as a tool to complete "radix-sort"
we dont need to sort more than 1 digit number with counting sort.

The procedure is simple.. We build a frequency array out of our sample array.
then we add (i)th  and (i-1)th values of the frequency array and store them in (i)th position
then we empty the frequency array by putting each number in its correct belonging position in B array
that creates a sorted B array,
then we copy the sorted elements of B array in Array A 
*/

#include<bits/stdc++.h>
using namespace std;

void counting_sort(int*,int);
void make_array(int* &A, int s);
void populate_array(int*, int, int, int);
int num_digit(int number);
void display_array(int* arr, int Size, int high);

int main(){
	int *arr;
	int Size;
	int low = 0;
	int high = 9;
	srand(time(0));

	cout<<"Enter Size of Array: ";
	cin>>Size;
	cout<<endl;
	make_array(arr,Size);
	populate_array(arr,Size,low,high);
	display_array(arr,Size,high);
	counting_sort(arr, Size);
	cout<<endl<<"sorted: "<<endl;
	display_array(arr,Size,high);

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


void counting_sort(int *A, int n){
	int *F = new int[10];		//make a frequency array
	int *B = new int[n];		//make a container array
	
	for(int i = 0;i < 10;i++) F[i] = 0;		//populate frequency array with all 0		
	for(int i = 0;i < n;i++) F[A[i]]++;		//update frequency array according to the occurrence
											//of a number in given array 
	for(int i = 1;i < 10;i++) F[i] += F[i-1];		//how many times a number equal or less than that
													//has occured in total is stored in that index
    for(int i = n-1;i >= 0;i--) B[--F[A[i]]] = A[i];  //populate container array B in a sorted manner
	for(int i = 0;i < n;i++) A[i] = B[i];		//copy the container array into the main array
	
}
