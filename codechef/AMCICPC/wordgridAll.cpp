#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;

string to_string(string s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string) s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto &x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}";
	return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

istream& operator>>(istream& input,vi& x){
	for(auto& i:x)
		input>>i;
	return input;
}

istream& operator>>(istream& input,pii& x){
	input>>x.F>>x.S;
	return input;
}


#ifdef PRINTERS
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int alpha[4];
int beta[4];
int beta2[4];
int alpha2[4];
string grid[4];

vector<string>best;

void takemin(){
	vector<string>cur(grid,grid+4);
	debug(cur);
	rep(i,0,4){
		rep(j,0,4)if(cur[i][j]=='#')cur[i][j]='A';
	}
	if(best.empty() or best>cur){
		best=cur;
	}
	rep(i,0,4){
		rep(j,i+1,4){
			swap(cur[i][j],cur[j][i]);
		}
	}
	if(best.empty() or best>cur){
		best=cur;
	}
}
#define gamma yo
int zeta[4];
int gamma[4];
int nongamma[4];
void solve(){
	best.clear();
	rep(i,0,4){
		grid[i]=string(4,'#');
	}
	int n;
	cin>>n;
	vector<string>v(n);
	rep(i,0,n)cin>>v[i];
	for(auto& i:v){
		string temp=i;
		reverse(all(temp));
		i=min(i,temp);
	}
	sort(all(v));
	v.resize(unique(all(v))-v.begin());
	if(sz(v)>8){
		cout<<"grid\nsnot\nposs\nible\n";
		return;
	}
	auto f=[](int x){
		int c,r;
		c = x&-x, r = x+c;
		return (((r^x) >> 2)/c) | r;
	};
	// x=mask of strings horizontally
	// y=mask of rows used (bits(y)==bits(x))
	if(sz(v)>6){
		int i=(1<<4)-1;
		while(i<(1<<sz(v))){
			int idx=0;
			int idx2=0;
			rep(l,0,sz(v)){
				if(i&(1<<l)){
					gamma[idx++]=l;
				}
				else nongamma[idx2++]=l;
			}
			do{
				rep(j,0,1<<3){
					rep(k,0,3){
						if(j&(1<<k))reverse(all(v[gamma[k+1]]));
					}
					set<string>can;
					rep(k,0,4){
						string a,b;
						rep(l,0,4)a.pb(v[gamma[l]][k]),b.pb(v[gamma[3-l]][k]);
						can.insert(a);
						can.insert(b);
					}
					bool good=1;
					rep(k,0,idx2){
						if(can.count(v[nongamma[k]])==0){good=0;break;}
					}
					if(good){
						debug(can);
						grid[0]=v[gamma[0]];
						grid[1]=v[gamma[1]];
						grid[2]=v[gamma[2]];
						grid[3]=v[gamma[3]];
						takemin();
					}
					rep(k,0,3){
						if(j&(1<<k))reverse(all(v[gamma[k+1]]));
					}
				}
			}while(next_permutation(gamma,gamma+4));
			i=f(i);
		}
		if(best.empty()){
			cout<<"grid\nsnot\nposs\nible\n";
			return;
		}
		else{
			for(auto i:best)
				cout<<i<<endl;
			return;
		}
	}
	rep(fuck,0,1<<sz(v)){
		rep(j,0,sz(v)){
			if(fuck&(1<<j))reverse(all(v[j]));
		}
		rep(i,0,5){
			if(sz(v)-i>4 or sz(v)-i<0 or i>sz(v)-i)continue;
			int x=(1<<i)-1;
			while(x<(1<<sz(v))){
				int stridx=0;
				int colidx=0;
				rep(j,0,sz(v)){
					if(x&(1<<j))beta[stridx++]=j;
					else beta2[colidx++]=j;
				}
				int y=(1<<i)-1;
				while(y<(1<<4)){
					int idx=0;
					rep(j,0,4){
						if(y&(1<<j))alpha[idx++]=j;
					}
					do{
					// alpha=permutation of selected rows
						int z=(1<<(sz(v)-i))-1;
						while(z<(1<<4)){
							int idxz=0;
							rep(k,0,4){
								if(z&(1<<k))alpha2[idxz++]=k;
							}
							do{
								rep(j,0,4){
									rep(k,0,4){
										grid[j][k]='#';
									}
								}
								rep(j,0,idx){
									grid[alpha[j]]=v[beta[j]];
								}
								bool good=true;
								rep(l,0,colidx){
									rep(_,0,idx){
										if(grid[alpha[_]][alpha2[l]]!='#' and grid[alpha[_]][alpha2[l]]!=v[beta2[l]][alpha[_]]){
											good=false;
											break;
										}
									}
									if(!good)break;
								}
								if(good){
									rep(l,0,colidx){
										rep(_,0,4){
											grid[_][alpha2[l]]=v[beta2[l]][_];
										}
									}
									takemin();
								}
							}while(next_permutation(alpha2,alpha2+idxz));
							if(z==0)break;
							z=f(z);
						}
					}while(next_permutation(alpha,alpha+idx));
					if(y==0)break;
					y=f(y);
				}
				if(x==0)break;
				x=f(x);
			}
		}
		rep(j,0,sz(v)){
			if(fuck&(1<<j))reverse(all(v[j]));
		}
	}
	if(best.empty()){
		cout<<"grid\nsnot\nposs\nible\n";
		return;
	}
	else{
		for(auto i:best)cout<<i<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}


//second--------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int t, n;
string s, s2, ans, temp;
set<string> words;
string lis[20];

bool possible(int i, int p, int step) {

	for(int cnt=0; cnt<4; cnt++) {
		if(temp[p] != '.' && temp[p] != lis[i][cnt])
			return 0;

		p += step;
	}

	return 1;
}

void change(int i, int p, int step, pair<int,  char> changes[]) {

	for(int cnt=0; cnt<4; cnt++) {
		changes[cnt] = make_pair(p, temp[p]);
		temp[p] = lis[i][cnt];

		p += step;
	}	
}

void revert(pair<int,  char> changes[]) {

	for(int i=0; i<4; i++)
		temp[changes[i].first] = changes[i].second;
}

void solve(int i) {

	if(i==n) {

		string temp2 = temp;
		for(int i=0; i<16; i++)
			if(temp2[i] == '.')
				temp2[i] = 'A';

		if(ans > temp2)
			ans = temp2;
		return;
	}

	pair<int,  char> changes[5];

	for(int p=0; p<16; p+=4) 
		if(possible(i, p, 1)) {
			change(i, p, 1, changes);
			solve(i+1);
			revert(changes);
		}

	for(int p=0; p<4; p++) 
		if(possible(i, p, 4)) {
			change(i, p, 4, changes);
			solve(i+1);
			revert(changes);
		}

	reverse(lis[i].begin(), lis[i].end());

	// Reverse words
	for(int p=0; p<16; p+=4) 
		if(possible(i, p, 1)) {
			change(i, p, 1, changes);
			solve(i+1);
			revert(changes);
		}

	for(int p=0; p<4; p++) 
		if(possible(i, p, 4)) {
			change(i, p, 4, changes);
			solve(i+1);
			revert(changes);
		}

	reverse(lis[i].begin(), lis[i].end());
}

int main() {

	cin >> t;
	while(t--) {

		cin >> n;
		words.clear();
		for(int i=0; i<n; i++) {
			cin >> s;
			s2 = s;
			reverse(s.begin(), s.end());

			words.insert(min(s, s2));
		}

		if(words.size() > 8) {
			printf("grid\nsnot\nposs\nible\n\n");
			continue;
		}

		n = 0;
		for(auto it : words)
			lis[n++] = it;

		ans = "";
		temp = "";

		for(int i=0; i<16; i++) {
			ans += "_";
			temp += ".";
		}

		solve(0);
		// printf("$$\n");

		temp = "";
		for(int i=0; i<16; i++) 
			temp += "_";
		
		if(ans == temp) {
			printf("grid\nsnot\nposs\nible\n\n");
			continue;
		}

		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				if(ans[i*4 + j] == '.')
					ans[i*4 + j] = 'A';
				printf("%c", ans[i*4 + j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
