#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string convertToAbbribation(string a) {
	ll middle = a.size() - 2;
	return a[0] + to_string(middle) + a[middle + 1];
}

int main() {
	ll n; cin>>n;
	for(int i=0; i<n; i++) {
		string t; cin>>t;
		if(t.size()>10) cout<<convertToAbbribation(t)<<endl;
		else cout<<t<<endl;
	}
	return 0;
}
