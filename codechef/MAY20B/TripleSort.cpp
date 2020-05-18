#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;
vector<vector<ll>> global2s;

vector<vector<ll>> operateOnChain(vector<ll> chain) {
	vector<vector<ll>> tripleList;
	if(chain.size() <= 2) {
		global2s.push_back(chain);
		return {};
	}
	ll strt = 0;
	while((chain.size()-strt) > 3) {
		tripleList.push_back({chain[strt], chain[strt+1], chain[strt+2]});
		chain[strt+2] = chain[strt];
		strt+=2;
	}
	if(chain.size()-strt == 2) {
		global2s.push_back({chain[strt], chain[strt+1]});
	}
	else tripleList.push_back({chain[strt], chain[strt+1], chain[strt+2]});
	return tripleList;
}

vector<vector<ll>> globls2sList() {
	vector<vector<ll>> tripleList;
	ll strt = 0;
	while(global2s.size()-strt > 1) {
		vector<ll> frst = global2s[strt], sec = global2s[strt+1];
		tripleList.push_back({frst[0], frst[1], sec[0]});
		tripleList.push_back({frst[0], sec[1], sec[0]});
		strt+=2;
	}
	return tripleList;
}

pair<vector<vector<ll>>, ll> solveChain(vector<ll> permut, ll k) {
	unordered_set<ll> buged;
	vector<vector<ll>> tripleList;
	FORI(0, permut.size()) {
		if((i+1) != permut[i] && buged.find(i) == buged.end()) {
			buged.insert(i);
			ll curr = i+1, nxt = permut[i];
			vector<ll> chain = {i};
			while(nxt != curr) {
				buged.insert(nxt-1);
				chain.push_back(nxt-1);
				nxt = permut[nxt-1];
			}
			vector<vector<ll>> temp = operateOnChain(chain);
			tripleList.insert(tripleList.end(), temp.begin(), temp.end());
		}
	}
	if(global2s.size()%2!=0) return {{}, 0};
	if(global2s.size()) {
		vector<vector<ll>> temp = globls2sList();
		if(temp.size() <= 0) {
			return {};
		}
		tripleList.insert(tripleList.end(), temp.begin(), temp.end());
	}
	return { tripleList, 1 };
}

void printTripleList(vector<vector<ll>> tripleList) {
	cout<<tripleList.size()<<endl;
	for( auto i : tripleList ) {
		for( auto j : i ) cout<<j+1<<' ';
		cout<<endl;
	}
}

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n, k; cin>>n>>k;
		vector<ll> v(n);
		FORI(0, n) cin>>v[i];
		pair<vector<vector<ll>>, ll> res = solveChain(v, k);
		if(res.second == 0) cout<<-1<<endl;
		else printTripleList(res.first);
		global2s = {};
	}
	return 0;
}
