#include<bits/stdc++.h>
using namespace std;
typedef unsigned long ll;
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,a,b) for(int i=a;i>=b;i--)
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define all(a) a.begin(),a.end()
const ll DIG_L = numeric_limits<ll>::digits;

int main()  {
	test {
		ll x; cin>>x;
		vector<ll> ar(x);
		f(i, 0, x) cin>>ar[i];
		bool pos = true;
		unordered_map<ll,ll> mp, mmp;
		ll prv = ar[0];
		mp[ar[0]]=1;
		f(i, 1, x) {
			if(ar[i]==prv) {
				mp[ar[i]]++;
			} else {
				if(mp.find(ar[i]) == mp.end()) {
					mp[ar[i]] = 1;
				} else pos = false;
			}
			prv = ar[i];
		}
		for(auto i: mp) {
			if(mmp.find(i.second) != mmp.end()) {
				pos = false;
				break;
			}
			mmp[i.second] = i.first;
		}
		cout<<(pos? "YES" : "NO")<<endl;
	}
	return 0;
}
