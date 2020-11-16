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

ll func(ll x, ll y, ll z) { return (x & z)*(y & z); }

int find_max(ll X, ll Y, ll L, ll R) {
	bitset<DIG_L> x(X), y(Y), l(L), r(R), need;
	return 1;
}

int main()  {
	test {
		ll x, y, l, r; cin>>x>>y>>l>>r;
		cout<<find_max(x, y, l, r)<<endl;
	}
	return 0;
}
