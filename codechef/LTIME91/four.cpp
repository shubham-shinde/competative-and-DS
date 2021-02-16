#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;

bool check_matrix(vector<vector<ll>> v, ll x, ll y) {
	ll n = v.size();
	ll m = v[0].size();
	if(x < y) {
		y=y-x;
		x=0;
	} else {
		x=x-y;
		y=0;
	}
	ll eq = v[x][y];
	for(auto i=0; true; i++) {
		if(x+i >= n || y+i >= m) {
			break;
		}
		if(v[x+i][y+i] != eq) return false;
	}
	return true;
}

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n, m; cin>>n>>m;
		vector<vector<ll>> v(n, vector<ll>(m));
		for(auto i=0; i<n; i++) {
			for(auto j=0; j<m; j++) {
				ll ran; cin>>ran;
				v[i][j] = ran;
			}
		}
		ll q; cin>>q;
		for(auto i=0; i<q; i++) {
			ll x,y,u; cin>>x>>y>>u;
			v[x-1][y-1] = u;
			cout<<(check_matrix(v, x-1, y-1)?"Yes":"No")<<endl;
		}
	}
	return 0;
}
