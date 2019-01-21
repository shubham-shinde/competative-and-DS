#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;
int divv=33;

ll Middle(ll a, ll b) { 
        ll mid = a+(b-a)/divv;
        return mid; 
    }



int main() {
    ll N,c;
    cin>>N>>c;
    bool stop = true;
    ll mid, start = 0,pstart = 0, end = N+1, rply;
    int ans = -1;
    // int max_c = 1000;
    while(true) {
    	if(start >= end-divv /*|| max_c <=0*/ ) break;
    	mid = Middle(start, end);
        if(mid == pstart) {
            mid++;
        }
    	cout<<1<<" "<<mid<<endl;
    	cin>>rply;
        if(rply == -1) break;
    	if(rply == 1) {
            cout<<2<<endl;
            // max_c -= c;
            end = mid;
        }
        else {
            // max_c--;
            pstart = start;
            start = mid;
        }
    }
    for(int i=start+1; i<=end; i++) {
    	cout<<1<<" "<<i<<endl;
        cin>>rply;
        if(rply==1) {
            ans = i;
            break;
        }
    }
    cout<<3<<" "<<ans;
    return 0;
}