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
		ll N;cin>>N;
		ll n = sub(N,1);
		auto ans = mul(n,mul(sum(n, 1),sum(n, 3)));
		cout<<sum(ans, 1)<<endl;
	}
	return 0;
}
