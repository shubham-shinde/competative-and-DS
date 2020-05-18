#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;
vector<vector<ll>> global2s;

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n; cin>>n;
		vector<ll> v(n);
		FORI(0, n) cin>>v[i];
		ll min = numeric_limits<ll>::max(), max = 0, curr=1;
		FORI(1, n) {
			if((v[i] - v[i-1]) > 2) {
				if(min > curr) min = curr;
				if(max < curr) max = curr;
				curr = 1;
			}
			else curr++;
		}
		if(min > curr) min = curr;
		if(max < curr) max = curr;
		else curr++;

		cout<<min<<' '<<max<<endl;
	}
	return 0;
}
