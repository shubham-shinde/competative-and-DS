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
        ll N;
        cin>>N;
        ll ans[N] { };

        ll rply, a, b, c;

        cout<<1<<" "<<1<<" "<<2<<" "<<3<<endl;
        cin>>a;

        cout<<1<<" "<<4<<" "<<2<<" "<<5<<endl;
        cin>>b;

        cout<<1<<" "<<4<<" "<<5<<" "<<3<<endl;
        cin>>c;
        
        ll aa = a^b^c;
        // FORI(1,N) {
        //     cout<<1<<" "<<i<<" "<<i<<" "<<i<<endl;
        //     cin>>rply;
        //     if(rply == -1) break;
        //     ans[i-1]=rply;
        // }
        cout<<2;
        FORI(0,N-1) {
            cout<<" "<<aa++;
        }
        cout<<endl;
        cin>>rply;
        if(rply==-1) break;
    }
    return 0;
}