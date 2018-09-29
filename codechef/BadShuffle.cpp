#include<iostream>
using namespace std;

void printArr(int *A,int N) {
    for(int i=0;i<N;i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void swap(int arr[],int p1,int p2) {
    int temp = arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
}

void revSwapArray(int *A,int s,int e) {
    for(int i=e-1;i>s;i--) {
        swap(A,i,i-1);
    }
}

void swapArray(int *A,int s,int e) {
    for(int i=s;i<e-1;i++) {
        swap(A,i,i+1);
    }
}

int main() {
    int N;
    cin>>N;
    int A[N]={0};
    for(int i=0; i<N; i++) {
        A[i] = i+1;
    }
    int p= N/2;
    swapArray(A, 0, p);
    swapArray(A, p, N);
    printArr(A,N);
    for(int i=0; i<N; i++) {
        A[i] = i+1;
    }
    revSwapArray(A, 0, N);
    printArr(A,N);
    return 0;
}