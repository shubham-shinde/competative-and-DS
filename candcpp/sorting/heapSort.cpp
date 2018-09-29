#include<iostream>
#include<chrono>
#include"common/common.h"

using namespace std::chrono;
using namespace std;

void printArray(int arr[], int n);
void swap (int *arr, int element1, int element2);

void heapify(int *arr, int n, int e) {
    int r = 2*e+2, l = 2*e+1;
    int large=e;
    if( l < n && arr[large] < arr[l]) {
        large = l;
    }
    if(r < n && arr[large] < arr[r]) {
        large = r;
    }
    if(e != large) {
        swap( arr, e, large);
        heapify(arr, n, large);
    }
}

void heapShort (int *arr, int n) {
    for(int i=(n-2)/2; i>=0; i--) {
        heapify(arr, n, i);
    }
    printArray(arr, n);
    for(int i=n-1;i>=0;i--) {
        swap(arr, i, 0);
        heapify(arr, i, 0);
    }

}

int main()
{
    int arrLen = 100;
    int *arr = new int[arrLen];

    for(int i=0; i<arrLen; i++) {
        arr[i] = i;
    }

    auto start = high_resolution_clock::now();    
    heapShort(arr, arrLen);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout <<"\nTime taken:: "<< duration.count()<<"\n"; 
    printArray(arr, arrLen);
    return 0;
}
