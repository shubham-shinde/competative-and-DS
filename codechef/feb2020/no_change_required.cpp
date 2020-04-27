#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
typedef long long ll;
ll n, p;

vector<ll> findCoins(vector<ll> v) {
	ll num=-1;
	FORI(0, n) {
		if(p%v[i]!=0) {
			num = i;
			break;
		}
	}
	if(num==-1) return {};
	FORI(0, n) {
		if(num==i) v[i] = p/v[i] + 1;
		else v[i] = 0;
	}
	return v;
}

int main()  {
	ll T; cin>>T;
	while(T--) {
		cin>>n>>p;
		vector<ll> a1;
		FORI(0, n) {
			ll t; cin>>t;
			a1.push_back(t);
		}
		vector<ll> ans = findCoins(a1);
		if(ans.size() > 0) {
			cout<<"YES"<<' ';
			for(auto i: ans) cout<<i<<' ';
		}
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}
