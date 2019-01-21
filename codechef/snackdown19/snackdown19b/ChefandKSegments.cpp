#include<bits/stdc++.h>
using namespace std;
//give n
#define FORI(s, n) for(int i=s; i!=n; i++)
#define FORJ(s, n) for(int j=s; j!=n; j++)
//form s to n-1
#define FORIMINUS(s, n) for(int i=s; i!=n; i--)
#define FORJMINUS(s, n) for(int i=s; i!=n; i--)
typedef long long ll;


int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N, K;
        cin>>N>>K;
        ll num = 1000000000;
        int a[num] {0};
        ll t1, t2;
        FORI(0, N) {
            cin>>t1>>t2;
            a[t1-1]++;
            a[t2]--;
        }
        FORI(1, num) a[i] += a[i-1];

        ll max=0, temp=0;

        FORI(0, num) {
            if(a[i]>=K) temp++; 
            else if(a[i]<K && temp!=0) {
                max = max<temp ? temp : max;
                temp = 0;
            }
        }
        cout<<max-1<<endl;
    }
    return 0;
}