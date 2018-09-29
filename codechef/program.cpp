#include<iostream>
#include<cmath>
using namespace std;

void swap(int arr[],int p1,int p2) {
    int temp = arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
}

void D2print(int *arr, int r, int c,int *count) {
    for(int i=0; i<r; i+=c) {
        for(int j=0; j<c; j++) {
            cout<<arr[i+j]<<" ";
        }
        cout<<" "<<count[i/c]<<endl;
    }
}

void permute(int *arr,int *A, int N, int left, int right, int length) {
    if(left!=right) {
        for(int i=left;i<=right;i++) {
            swap(A, left, i);
            permute(arr, A, N, left+1, right, length);
            swap(A, left, i);
        }
    }
    else {
        for(int i=0;i<length;i+=N) {
            if(arr[i]==0) {
                for(int j=i; j<i+N; j++) {
                    arr[j]=A[j-i];
                }
                break;
            }
        }
    }
}

void Calculate(int *arr, int *count, int *A, int N, int ptr,int limit, int length) {
    if(limit!=0) {
        for(int i=0; i<N;i++) {
            swap(A, ptr, i);
            Calculate(arr, count, A, N, ptr+1, limit-1, length);
            swap(A, ptr, i);
        }
    }
    else {
        for(int i=0;i<length;i+=N) {
            if(arr[i]==A[0]) {
                for(int j=1; j<N; j++) {
                    if(arr[i+j]!=A[j]) {
                        break;
                    }
                    if(j==N-1) {
                        count[i/N]++;
                    }
                }
            }
        }
    }
}

int main() {
    int N;
    cin>>N;
    int fact=1;
    for(int i=2;i<=N;i++) {
        fact *= i;
    }
    int *arr = new int[fact*N] {0};
    int *count = new int[fact] {0};
    int *A = new int[N];
    for(int i=0; i<N; i++) {
        A[i] = i+1;
    }
    permute(arr, A, N, 0, N-1, fact*N);
    Calculate(arr, count ,A , N, 0, N, fact*N);
    D2print(arr, fact*N, N, count);
    int max=0, min=fact*N;
    for(int i=0; i<fact; i++) {
        if(count[i]>count[max]) {
            max=i;
        }
    }
    min=max;
    for(int i=0; i<fact; i++) {
        if(count[i]<count[min]) {
            min=i;
        }
    }
    for(int i=0;i<N;i++) {
        cout<<arr[max*N+i]<<" ";
    }
    cout<<count[max];
    cout<<endl;
    for(int i=0;i<N;i++) {
        cout<<arr[min*N+i]<<" ";
    }
    cout<<count[min];
    cout<<endl;
    // cout<<"Max "<<max<<endl;
    // cout<<"Min "<<min<<endl;
    return 0;
}