#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
typedef long long ll;

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n; cin>>n;
		vector<ll> a1, a2;
		FORI(0, n) {
			ll t; cin>>t;
			a1.push_back(t);
		}
		FORI(0, n) {
			ll t; cin>>t;
			a2.push_back(t);
		}
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end());
		ll sum = 0;
		FORI(0, n) {
			if(a1[i]<a2[i]) sum+=a1[i];
			else sum+=a2[i];
		}
		cout<<sum<<endl;
	}
	return 0;
}
