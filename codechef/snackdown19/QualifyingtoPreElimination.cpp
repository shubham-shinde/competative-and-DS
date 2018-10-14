#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin>>T;
    ll N, K, score, num;
    for( int q=0; q<T; q++) {
    	cin>>N>>K;
        int A[N];
    	for(int i=0; i<N; i++) {
            cin>>score;
            A[i]=score;
        }
        sort(A, A+N);
        num = A[N-K];
        ll count = K;
        for(int i=N-K-1; i>=0; i--) {
            if(A[i] == num) count++;
            else break;
        }
        cout<<count<<endl;
    }
    return 0;
}
