//for finding sum of elements within range.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FORI(s, n) for(long long i=s; i<=n; i++)

ll minn(ll a, ll b) {
    return a>b ? b : a;
}

int main() {
    ll N,M; cin>>N>>M;
    vector<vector<ll>> n(N, vector<ll>(2)), m(M, vector<ll>(2));
    FORI(0, N-1) {cin>>n[i][0]; n[i][1]=i;}
    FORI(0, M-1) {cin>>m[i][0]; m[i][1]=i;}
    auto fun = [](const auto& a, const auto& b) {
        return a[0]>b[0];
    };
    sort(n.begin(), n.end(), fun);
    sort(m.begin(), m.end(), fun);
    ll mi = minn(N, M);
    cout<<n[0][1]<<' '<<m[0][1]<<endl;
    FORI(1, mi-1) {
        cout<<n[i][1]<<' '<<m[i][1]<<endl;
        cout<<n[i-1][1]<<' '<<m[i][1]<<endl;        
    }
    if(mi == N) {
        FORI(N, M-1) {
            cout<<n[N-1][1]<<' '<<m[i][1]<<endl;
        }
    }
    else {
        FORI(M, N-1) {
            cout<<n[i][1]<<' '<<m[M-1][1]<<endl;
        }
    }
    return 0;
}