#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007LL
typedef long long ll;

ll mul(ll n, ll x) {
	return ((n%mod)*(x%mod))%mod;
}
ll sum(ll n, ll x) {
	return ((n%mod)+(x%mod))%mod;
}
ll sub(ll n, ll x) {
	return ((n%mod)-(x%mod))%mod;
}


int main() {
	ll T;
	cin>>T;
	while(T--) {
		string N;cin>>N;
		ll n = mul(100 , sum((N[0]-'a'),1));
		ll ans = 0;
		for(auto i : N) ans = sum(ans, sum(n, i-'a'));
		cout<<ans<<endl;
	}
	return 0;
}
