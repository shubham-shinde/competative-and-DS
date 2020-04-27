#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string a;
	while(true) {
		cin>>a;
		if(a=="0") break;
		ll len = a.size();
		ll i=1;
		vector<ll> dp(a.size(), 0);
		dp[0]=1;
		for(int i=1; i<a.size(); i++) {
			ll prv = a[i-1]-'0';
			ll ts = a[i]-'0';
			ll num = prv*10+ts;
			if(ts) {
				dp[i]=dp[i-1];
			}
			if(num > 9 && num < 27) {
				dp[i]+=dp[i-2<0?0:i-2];
			}
		}
		cout<<dp[dp.size()-1]<<endl;
	}
	return 0;
}
