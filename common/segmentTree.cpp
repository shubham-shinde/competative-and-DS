//for finding sum of elements within range.
#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

int getMid(int s, int e) { return s+(e-s)/2; }

int fillSegmentTree(int arr[], int start, int end, int *segmentTree, int index) {
    if(start==end) {
        segmentTree[index] = arr[start];
        return arr[start];
    }
    int mid = getMid(start, end);
    segmentTree[index] = fillSegmentTree(arr, start, mid, segmentTree, index*2+1) +
                        fillSegmentTree(arr, mid+1, end, segmentTree, index*2+2);
    return segmentTree[index];
}

int *constructSegmentTree(int arr[], int N) {
    int x = (int)(ceil(log2(N)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *segmentTree = new int[max_size];
    fillSegmentTree(arr, 0, N-1, segmentTree, 0);
    return segmentTree;
}

int getQueryUtil(int *segmentTree, int tStart , int tEnd, int qStart, int qEnd, int index) {
    if( qStart <= tStart && qEnd >= tEnd) return segmentTree[index];

    if( tEnd < qStart || tStart > qEnd) return 0;

    int mid = getMid(tStart, tEnd);
    return getQueryUtil(segmentTree, tStart, mid, qStart, qEnd, 2*index+1) + 
            getQueryUtil(segmentTree, mid+1, tEnd, qStart, qEnd, 2*index+2);
}

int getQuery(int *segmentTree, int N, int qStart, int qEnd) {
    if(qStart < 0 || qEnd > N-1 || qStart > qEnd) return -1;
    return getQueryUtil(segmentTree, 0, N-1, qStart, qEnd, 0);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int *st = constructSegmentTree(arr, n); 
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    FORI(0, max_size-1) cout<<st[i]<<" ";
    cout<<endl;
    cout<<"Sum of values in given range = "<<getQuery(st, n, 1, 3); 
    return 0;
}