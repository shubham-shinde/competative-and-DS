#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;


int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N, M, K;
        cin>>N>>M>>K;
        ll a[N];
        FORI(0, N-1) cin>>a[i];
        sort(a, a+N);
        ll answer=a[M-1], number=K;
        FORIMINUS(M-2, 0) {
            if(number==0) {
                number = K;
                answer+=a[i];
            }
            else number--;
        }
        cout<<answer<<endl;
    }
    return 0;
}
