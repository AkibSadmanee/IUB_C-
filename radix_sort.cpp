#include<bits/stdc++.h>
using namespace std;

void make_array(int *&A, int S);
void populate_array(int *A, int S, int low, int high);
void display_array(int *A, int s, int h);
int num_dig(int n);
void counting_sort(int*,int, int);
void radix_sort(int*, int, int);

int main(){
	
	int *A;
	int Size = 100;
	int low = 0;
	int high = 1234;

	srand(time(0));	
	make_array(A,Size);
	populate_array(A,Size, low, high);	
	display_array(A,Size,high);
		
	cout<<endl;
	radix_sort(A,Size,high);
	display_array(A,Size,high);
		
	
	return 0;
}

void make_array(int *&A, int S){
	A = new int[S];
}

void populate_array(int *A, int S, int low, int high){
	for(int i =0; i< S; i++){
		A[i] = low +  rand() % (high - low + 1);		
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


void counting_sort(int *A, int n, int e){
	int F[10] = {0};	//create a frequency array and populate with all 0
	int B[n];			// create a container array
	for(int i = 0;i < n;i++) F[(A[i]/e)%10]++;	//here 'e' is the position holder. e = 1,10,100... 
												//with 'e' I'm visiting each position of a number
	for(int i = 1;i < 10;i++) F[i] += F[i-1];	//count how many times a digit or less than that digit
												//has occured in the array of numbers for that particualr position   
    for(int i = n-1;i >= 0;i--){
        B[ F [ (A[i] / e) % 10] - 1] = A[i];
        F[ (A[i]/e)%10 ]--;
    }
	for(int i = 0;i < n;i++) A[i] = B[i];	//copy container array values into main array
	
	
}
void radix_sort(int *A, int n, int h){
    for(int i =1; h/i>0; i*=10 )
        counting_sort(A,n,i);			//pass the exponent as 'i' into counting sort i = 1,10,100,.....
}
