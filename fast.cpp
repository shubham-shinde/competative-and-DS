#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

int main()
{
	string i;
	cin>>i;
	for(auto j=0; j<i.length(); j++) {
		int jj = int(i[j]);
		jj = 97 + (jj-97 + 3)%26;
		i[j] = char(jj);
	}
	cout<<i;
	return 0;
}
