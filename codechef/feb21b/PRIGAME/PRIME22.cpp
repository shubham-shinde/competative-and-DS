#include<bits/stdc++.h>
using namespace std;
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define ld long double
typedef long long ll;
#define MOD 1000000007LL
#define FORI(s, n) for(auto i=s; i<n; i++)

vector<ll> SieveOfEratosthenes()
{
	ll count = 100000;
	ll n = 1000000;
	vector<vector<bool>> prime(11, vector<bool> (count, true));
	for (int p = 2; p * p <= n; p++) {
		/* cout<<p/count<<' '<<(p - (p/count)*count)<<' '<<p<<endl; */
		if (prime[p/count][p - (p/count)*count] == true)
			for (int i = p * p; i <= n; i += p) {
				if(i/count < 11) prime[i/count][i - (i/count)*count] = false;
			}
	}
	cout<<"final"<<endl;
	vector<ll> prim;
	ll num = 0;
	for (auto i: prime) for(auto j: i) {
		num++;
		if (j)
			prim.push_back(num);
	}
	return prim;
}


int main()  {
	ll TT; cin>>TT;
	vector<ll> primes = SieveOfEratosthenes();
	cout<<primes.size()<<endl;
	while(TT--) {
		ll x, y; cin>>x>>y;
		/* cout<<primes.size(); */
		if(y > primes.size() || primes[y] > x)
			cout<<"Chef"<<endl;
		else
			cout<<"Divyam"<<endl;
	}
	return 0;
}
