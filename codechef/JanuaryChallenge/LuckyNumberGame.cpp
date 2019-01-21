//for finding sum of elements within range.
#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

int main() {
    int T; cin>>T;
    while(T--) {
        ll N, A, a=0, B, b=0, ab=0, t;
        cin>>N>>A>>B;
        ll AB=A*B;
        for(int i=0; i<N; i++) {
            cin>>t;
            if(t%A==0) a++;
            if(t%B==0) b++;
            if(t%AB==0) ab++;
        }
        a-=ab;
        b-=ab;
        if(a==b) {
            ab!=0 ? cout<<"BOB" : cout<<"ALICE";
        }
        else if(a>b) cout<<"BOB";
        else cout<<"ALICE";
        cout<<endl;
    }
    return 0;
}