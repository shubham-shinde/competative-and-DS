#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define FORI(s, n) for(auto i=s; i<n; i++)
#define forirev(s, n) for(long long i=s; i>=n; i--)
const ll DIG_L = numeric_limits<ll>::digits;

ll func(ll x, ll y, ll z) { return (x & z)*(y & z); }

ll find_max(ll X, ll Y, ll L, ll R) {
	bitset<DIG_L> x(X), y(Y), l(L), r(R), need, extra;
	if(X == 0 || Y==0 ) return L;
	if(L==R) return L;
	need = y|x;
	if(need.to_ullong() < L) {
		forirev(need.size()-1, 0) {
			if(!l.test(i) && need.test(i)) break;
			if(l.test(i)) need.set(i, l.test(i));
		}
	}
	ll u;
	if(need.to_ullong() >= R) {
		vector<ll> nmax;
		forirev(r.size()-1, 0) {
			if(r.test(i)) break;
			else need.set(i, 0);
		}
		extra = need|l;
		u = extra.to_ullong();
		if(u <= R && u >= L) {
			nmax.push_back(u);
		}
		u = need.to_ullong();
		if(u <= R && u >= L) {
			nmax.push_back(u);
		}
		forirev(need.size()-1, 0) {
			if(!need.test(i)) {
				need.set(i, 1);
				u = need.to_ullong();
				if(u <= R && u >= L) {
					nmax.push_back(u);
				}
				need.set(i, 0);
			}
		}
		forirev(need.size()-1, 0) {
			if(need.test(i)) {
				need.set(i, 0);
				u = need.to_ullong();
				if(u <= R && u >= L) {
					nmax.push_back(u);
				}
				extra = need|l;
				u = extra.to_ullong();
				if(u <= R && u >= L) {
					nmax.push_back(u);
				}
				if(i>1) {
					for(long long j=i-1; j>=0; j--) {
						if(!need.test(j)) {
							need.set(j, 1);
							u = need.to_ullong();
							if(u <= R && u >= L) {
								nmax.push_back(u);
							}
							need.set(j, 0);
						}
					}
				}
				need.set(i, 1);
			}
		}
		forirev(need.size()-1, 0) if(!r.test(i)) {
			need.set(i, 0);
		}
		u = need.to_ullong();
		if(u <= R && u >= L) {
			nmax.push_back(u);
		}
		if(nmax.size()) {
			sort(nmax.begin(), nmax.end());
			ll max=0, ret = nmax[0];
			for(auto i: nmax) {
				if(func(X, Y, i)>max) {
					max = func(X,Y,i);
					ret = i;
				}
			}
			need = bitset<DIG_L>(ret);
		}
		else need = r;
	}
	if(func(X, Y, need.to_ullong()) == func(X, Y, L)) return L;
	return need.to_ullong();
}

ll brouteForceMax(ll x, ll y, ll l, ll r) {
	ll mx = func(x, y, l);
	ll z=l;
	FORI(l, r+1) {
		if(func(x, y, i)>mx){
			mx = func(x, y, i);
			z=i;
		}
	}
	return z;
}

int main()  {
	ll num = 20, cunt=0;
	FORI(0, num) {
		for(ll j=0; j<num; j++) for(ll k=0; k<num; k++) for(ll m=k; m<num; m++) {
			if(find_max(i, j, k, m) != brouteForceMax(i, j, k, m)) {
				ll f = find_max(i, j, k, m);
				ll b = brouteForceMax(i, j, k, m);
				string bn(to_string(b)+'('+to_string(func(i, j, b))+')');
				string fn(to_string(f)+'('+to_string(func(i, j, f))+')');
				cout<<i<<' '<<j<<' '<<k<<' '<<m<<' '<<bn<<' '<<fn<<endl;
				cunt++;
			}
		}
	}
	cout<<cunt<<endl;
	return 0;
}
/* 1 */
/* 12 7 16 20 */
/* 1 */
/* 1000000000000 1 0 1000000000000 */
