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
		ll x, sum = 1; cin>>x;
		bool pos= true;
		vector<ll> ar;
		while((x+sum)/(sum*2) > 0) {
			ll s = (x+sum)/(sum*2);
			ar.push_back(s);
			sum*=2;
		}
		ll ans = 0;
		sum = 1;
		f(i,0, ar.size()) {
			ans +=ar[i]*sum;
			if(i==(ar.size()-1) && x==sum) pos=false;
			sum *=2;
		}
		cout<<(pos ? (ans-1) : (-1))<<endl;
	}
	return 0;
}
