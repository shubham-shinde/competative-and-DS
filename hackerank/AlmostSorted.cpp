#include <bits/stdc++.h>

using namespace std;

void almostSorted(int* a, int n) {
    for(int i=1; i<n-1; i++) {
        if(a[i]<a[i-1] && a[i]<a[i+1]) {
            cout<<"dip ";
            continue;
        }
        if(a[i]>a[i-1] && a[i]>a[i+1]) {
            cout<<"down ";
            continue;
        }
        cout<<"* ";
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    almostSorted(arr, n);

    return 0;
}