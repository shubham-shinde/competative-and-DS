#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sort_gapped(ll start, ll g, vector<ll>& a) {
	vector<ll> pos, vec;
	while(start < a.size()) {
		pos.push_back(start);
		vec.push_back(a[start]);
		start+=g;
	}
	sort(vec.begin(), vec.end());
	for(ll i=0; i<pos.size(); i++) a[pos[i]] = vec[i];
}

string is_sorted(vector<ll>& a) {
	ll prv = -1;
	for(auto i: a) {
		if(i<prv) return "no";
		prv=i;
	}
	return "yes";
}


int main() {
	ll tt; cin>>tt;
	while(tt--) {
		ll n,g; cin>>n>>g;
		vector<ll> a(n);
		for(int i=0; i<n; i++) cin>>a[i];
		for(int i=0; i<g; i++) sort_gapped(i, g, a);
		cout<<is_sorted(a)<<endl;
	}
	return 0;
}
