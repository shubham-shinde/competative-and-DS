#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n, k; cin>>n>>k;
		vector<ll> v(n);
		FORI(0, n) cin>>v[i];
		ll sum = accumulate(v.begin(), v.end(), 0);
		cout<<(sum%k==0?0:1)<<endl;
	}
	return 0;
}
