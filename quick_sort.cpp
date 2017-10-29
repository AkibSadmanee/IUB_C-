#include<bits/stdc++.h>

using namespace std;


void make_array(int* &A,int s);
void populate_array(int *A,int s, int h, int l);
int get_max(int *arr,int Size);
void display_array(int* arr, int Size);
int num_digit(int);

int pivot(int *A, int l, int r);
void swap (int &x, int &y);
void quick_sort_core(int *A, int l, int r);
void quick_sort(int* A, int s);

int main()
{
    int* arr;
    int Size = 1000;
    int high = 12345;
    int low = 10;

    make_array(arr,Size);
    populate_array(arr,Size,high,low);

    cout<<"Sample: "<<endl;
    display_array(arr,Size);
    quick_sort(arr,Size);
    cout<<endl<<endl<<"Sorted: "<<endl;
    display_array(arr,Size);
    return 0;
}

void make_array(int* &A,int s){
	A=new int[s];
}

void populate_array(int *A,int s, int h, int l){
	for(int i=0;i<s;++i){
		A[i]=l+rand()%(h-l+1);
	}
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
	cout<<endl;
}

int num_digit(int n){
	if(n<10)return 1;
	return 1+num_digit(n/10);
}

int pivot(int *arr, int left, int right){
    int piv = left;
    int pivot = arr[left];
    for(int i = left +1; i <= right; i++){
        if(arr[i] <= pivot){
            piv++;
            swap(arr[i], arr[piv]);
        }
    }
    swap(arr[left], arr[piv]);
    return piv;
}

void swap (int &x, int &y){
	int temp=x;
	x=y;
	y=temp;
}


void quick_sort_core(int *A, int l, int r){
    if(l<r){
        int p = pivot(A,l,r);
        quick_sort_core(A,l,p-1);
        quick_sort_core(A,p+1,r);
    }
}

void quick_sort(int* A, int s)
{
    // wrapper function for easier call
    quick_sort_core(A,0,s-1);
}


