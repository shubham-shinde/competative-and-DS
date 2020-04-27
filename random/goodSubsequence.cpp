#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;

long long GoodSubArray (int N, int*arr, bool* is_bad) {
	vector<ll> numbers(N), goodorbad(N);
	FORI(0, N-1) numbers[i]=arr[i];
	FORI(0, N-1) goodorbad[i]=is_bad[i];
	//saperate into accending;
	vector<vector<pair<ll,ll>>> accendings;
	accendings.push_back({{numbers[0], goodorbad[0]}});
	FORI(1, N-1) {
		ll acc_lst = accendings.size()-1;
		if(numbers[i] > accendings[acc_lst][accendings[acc_lst].size()-1].first) {
			accendings[acc_lst].push_back({numbers[i], goodorbad[i]});
		}
		else {
			accendings.push_back({{numbers[i], goodorbad[i]}});
		}
	}
	ll ans = 0;
	for(auto a : accendings) {
		for(auto i=0; i<a.size(); i++) {
			if(a[i].second==0) {
				ans+= a.size()-i;
			}
		}
	}
	return ans;
}


int main() {
	ll Tt;
	cin>>Tt;
	while(Tt--) {
		ll N;
		cin>>N;
		vector<ll> numbers(N), goodorbad(N);
		FORI(0, N-1) cin>>numbers[i];
		FORI(0, N-1) cin>>goodorbad[i];
		//saperate into accending;
		vector<vector<pair<ll,ll>>> accendings;
		accendings.push_back({{numbers[0], goodorbad[0]}});
		FORI(1, N-1) {
			ll acc_lst = accendings.size()-1;
			if(numbers[i] > accendings[acc_lst][accendings[acc_lst].size()-1].first) {
				accendings[acc_lst].push_back({numbers[i], goodorbad[i]});
			}
			else {
				accendings.push_back({{numbers[i], goodorbad[i]}});
			}
		}
		ll ans = 0;
		for(auto a : accendings) {
			for(auto i=0; i<a.size(); i++) {
				if(a[i].second==0) {
					ans+= a.size()-i;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

