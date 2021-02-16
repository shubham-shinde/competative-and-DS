#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i<n; i++)
typedef long long ll;

ll count_one(string s) {
	ll count = 0;
	for(auto i : s) {
		if(i=='1') count++;
	}
	return count;
}

int main()  {
	ll T; cin>>T;
	while(T--) {
		ll n; cin>>n;
		ll not_flag=0;
		string s, p; cin>>s>>p;
		if(count_one(s)!=count_one(p)) {
			not_flag = 1;
		} else {
			ll one_count=0;
			for(auto i=0; i<s.size(); i++) {
				if(s[i] != p[i]) {
					if(s[i] == '1') {
						one_count++;
					}
					else {
						one_count--;
						if(one_count<0) {
							not_flag=1;
						}
					}
				}
			}
		}
		cout<<(not_flag==1?"No":"Yes")<<endl;
	}
	return 0;
}
