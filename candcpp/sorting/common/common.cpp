#include "common.h"
#include<iostream>
using namespace std;

void printArray(int arr[], int size) {
    for ( int i = 0; i < size; i++ ) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap (int *arr, int element1, int element2) {
    int temp= arr[element1];
    arr[element1] = arr[element2];
    arr[element2] = temp;
}