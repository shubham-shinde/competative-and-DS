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
    ll T, N;
    cin>>T;
    while(T--) {
    	cin>>N;
        map<ll, ll> B;
        ll temp;
        for(ll i=0; i<N; i++) {
            cin>>temp;
            if(B.find(temp) == B.end()) {
                B[temp] = 1;
            }
            else {
                B.at(temp) += 1;
            }
        }
        ll counter=0;
        for( auto i= B.rbegin(); i!= B.rend(); i++) {
            // cout<<i->first<<endl;
            for( auto j=B.begin(); j != B.end(); j++) {
                if(j->first > i->second) break;
                if(j->first == i->first) break;
                if(i->first <= j->second && j->first <= i->second) counter+=2;
            }

            if(i->first <= i->second) counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}