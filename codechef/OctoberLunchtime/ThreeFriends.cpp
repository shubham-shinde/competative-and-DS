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
        ll X, Y, Z;
        cin>>X>>Y>>Z;
        if(X+Y == Z || Y+Z ==  X || X+Z == Y ) {
            cout<<"yes"<<endl;
            continue;
        }
        cout<<"no"<<endl;
    }
    return 0;
}