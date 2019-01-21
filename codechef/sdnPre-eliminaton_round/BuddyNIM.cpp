#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;


int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N, M;
        cin>>N>>M;
        ll a[N], b[M];
        FORI(0, N-1) cin>>a[i];
        FORI(0, M-1) cin>>b[i];
        bool bob = true;
        if(N!=M) {
            bob = false;
        }
        else {
            sort(a,a+N);
            sort(b,b+N);
            FORI(0, N-1) {
                if(a[i]!=b[i]) {
                    bob = false;
                    break;
                }
            }
        }
        bob ? cout<<"Bob"<<endl : cout<<"Alice"<<endl;
        
    }
    return 0;
}