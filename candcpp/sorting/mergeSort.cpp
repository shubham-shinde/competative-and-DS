#include<iostream>
#include<chrono>
#include"common/common.h"

using namespace std::chrono;
using namespace std;

void printArray(int arr[], int n);
void swap (int *arr, int element1, int element2);

void MergeSort (int *arr, int n) {
    
}

int main()
{
    int arrLen = 100;
    int *arr = new int[arrLen];

    for(int i=0; i<arrLen; i++) {
        arr[i] = i;
    }

    auto start = high_resolution_clock::now();    
    MergeSort(arr, arrLen);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout <<"\nTime taken:: "<< duration.count()<<"\n"; 
    printArray(arr, arrLen);
    return 0;
}
