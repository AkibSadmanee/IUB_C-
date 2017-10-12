#include<bits/stdc++.h>

using namespace std;


void make_array(int* &A,int s);
void populate_array(int *A,int s, int h, int l);
void display_array(int *A, int s, int h);
int num_dig(int);

int pivot(int *A, int l, int r);
void swap (int &x, int &y);
void quick_sort(int *A, int l, int r);

int main()
{
    int* arr;
    int Size = 1000;
    int high = 12345;
    int low = 10;

    make_array(arr,Size);
    populate_array(arr,Size,high,low);

    cout<<"Sample: "<<endl;
    display_array(arr,Size,high);
    quick_sort(arr,0,Size-1);
    cout<<endl<<endl<<"Sorted: "<<endl;
    display_array(arr,Size,high);
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

void display_array(int *A, int s, int h){
	for(int i=0;i<s;++i){
		if(i%5==0)cout<<endl;
		cout<<setw(num_dig(h)+1)<<A[i];
	}
	cout<<endl<<endl;
}

int num_dig(int n){
	if(n<10)return 1;
	return 1+num_dig(n/10);
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


void quick_sort(int *A, int l, int r){
    if(l<r){
        int p = pivot(A,l,r);
        quick_sort(A,l,p-1);
        quick_sort(A,p+1,r);
    }
}
