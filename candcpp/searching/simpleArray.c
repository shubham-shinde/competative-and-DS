#include <stdio.h>

int linear_search(int a[], int n, int no) {
    int i;
    for (i=0; i<n; i++) {
        if(no == a[i]) {
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int lb, int ub , int no) {
    int mid = (ub+lb)/2;
    if(no == a[mid]) {
        return mid;
    }
    else if ((ub - lb) == 1) {
        return -1;
    }
    else if (no > a[mid]) {
        return binary_search(a, mid, ub, no );
    }
    else if (no < a[mid]) {
        return binary_search(a, lb, mid, no );
    }
}

void main()
{
    int i, j ,n, a[20], no, value;
    printf("Enter no. of lenght of array h\n");
    scanf("%d", &n);
    printf("Enter array\n");
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter no to search in the array\n");
    scanf("%d", &no);
    value = binary_search(a, 0, n, no );
    printf("Index of the given no is :- %d \n", value);
}
