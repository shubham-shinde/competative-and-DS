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
        long long Max=C[0];
        int pos = 0;
        for(int i=1; i<N; i++) {
            if(C[i]>Max) {
                Max = C[i];
                pos=i;
            }
        }
        A[pos]--;
        C[pos]=A[pos]*B[pos];
    }
    long long Max=C[0];
    for(int i=1; i<N; i++) {
        if(C[i]>Max) Max = C[i];
    }
    cout<<Max<<endl;
    return 0;
}
