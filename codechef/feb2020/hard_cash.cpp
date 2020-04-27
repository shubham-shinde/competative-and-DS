#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
typedef long long ll;

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n, tt; cin>>n; cin>>tt;
		vector<ll> r, a1, a2;
		ll sum = 0;
		FORI(0, n) {
			ll t; cin>>t;
			sum+=t;
			r.push_back(t);
		}
		cout<<sum%tt;
	}
	return 0;
}
