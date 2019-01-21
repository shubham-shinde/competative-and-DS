#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;

int countReservior() {

}

int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin>>N;
        ll a[N];
        FORI(0, N-1) cin>>a[i];
        cout<<countReservior()<<endl;
    }
    return 0;
}