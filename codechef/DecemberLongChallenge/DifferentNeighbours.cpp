#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(i, s, n) for(i=s; i<=n; i++);

int main() {
    ll T; cin>>T;
    while(T--) {
        ll N, M; cin>>N>>M;
        int a[N][M];
        ll num=1;
        int count=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                a[i][j] = num;
                count++;
                if(count>=2 && !(i==N-1 && j==M-1)) {
                    num++;
                    count=0;
                }
            }
        }
        cout<<num<<endl;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
