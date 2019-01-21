#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FORI(s, n) for(int i=s; i<=n; i++);

int main() {
    ll T; cin>>T;
    while(T--) {
        ll n, p; cin>>n>>p;
        ll rem = n%(n/2 + 1);
        if(rem==0) cout<<p*p*p<<endl;
        else cout<<(p-rem)*(p-rem) + (p-rem)*(p-n) + (p-n)*(p-n)<<endl;
    }
    return 0;
}