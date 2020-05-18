#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;

unordered_map<char, ll> createMap(string s) {
	unordered_map<char, ll> mp;
	for(auto i: s) {
		if(mp.find(i) == mp.end()) mp[i] = 1;
		else mp[i]++;
	}
	return mp;
}

ll findQuery(unordered_map<char, ll> mp, ll t) {
	ll rt = 0;
	for(auto i : mp) {
		if(i.second > t) rt+= i.second-t;
	}
	return rt;
}

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		unordered_map<char, ll> mp = createMap(s);
		FORI(0, q) {
			ll t; cin>>t;
			cout<<findQuery(mp, t)<<endl;
		}
	}
	return 0;
}
