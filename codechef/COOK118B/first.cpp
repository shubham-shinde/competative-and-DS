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
		string s; cin>>s;
		ll ans = 0;
		f(i, 2, s.size()) {
			if(
					s.substr(0, i/2) == s.substr(i/2, i/2)
					&&
					s.substr(i, (s.size()-i)/2) == s.substr((s.size()-i)/2), (s.size()-i)/2)
				) ans++;
		}
	}
	return 0;
}
