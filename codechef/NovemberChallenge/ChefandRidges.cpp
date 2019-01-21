#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;
typedef pair< ll, ll > makePair;

makePair addFractions(makePair P, ll add, bool plus) {
    P.first = plus ? P.first*add + P.second: P.first * add-P.second;
    P.second = P.second*add;
    ll g = __gcd(P.first, P.second);
    P.first/=g;
    P.second/=g;
    return P;
}

int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin>>N;
        makePair p {1, 2};
        FORI(1, N-1) {
            p = addFractions(p, pow(2,i+1), (i+1)%2);
        }
        cout<<p.first<<" "<<p.second<<" ";
    }
    return 0;
}