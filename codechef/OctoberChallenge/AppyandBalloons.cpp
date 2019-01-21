
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    long long M;
    cin>>N>>M;
    long long A[N], B[N], C[N];
    for( int i=0; i<N; i++) {
        cin>>A[i];
    }
    for( int i=0; i<N; i++) {
        cin>>B[i];
        C[i]=A[i]*B[i];
    }
    while(M!=0) {
        long long *Max = max_element(C, C+N);
        int pos = Max-C;
        A[pos]<=1 ? A[pos]=0 : A[pos]--;
        C[pos]=A[pos]*B[pos];
        M--;
    }
    cout<<*max_element(C, C+N)<<endl;
    return 0;
}
