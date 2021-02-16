#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;

int main()  {
	ll T; cin>>T;
	while(T--) {
		string s; cin>>s;
		unordered_map<char, ll> h;

		ll maxx = 0;
		for(auto i : s) {
			if (h.find(i) == h.end()) h[i]=0;
			h[i]++;
			if(h[i] > maxx) maxx=h[i];
		}
		if(maxx>=3 && s.size() >= 3) {
			cout<<6<<endl;
		} else if(maxx==2 && s.size() >= 3) {
			cout<<2<<endl;
		} else {
			cout<<0<<endl;
		}
	}
	return 0;
}
