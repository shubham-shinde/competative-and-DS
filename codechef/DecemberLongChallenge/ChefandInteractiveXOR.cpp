#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//give n-1
#define FORI(s, n) for(ll i=s; i<=n; i++)
#define FORJ(s, n) for(ll j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(ll i=s; i>=n; i--)
#define FORJMINUS(s, n) for(ll i=s; i>=n; i--)
// a 1 4
void for4(ll a[], ll s) {
    ll rply;
    ll ans[4] { };
    ll all=0;
    cout<<1<<" "<<s+1<<" "<<s+2<<" "<<s+3<<endl;
    cin>>rply;
    all=all^rply;
    ans[0] = rply;
    cout<<1<<" "<<s+2<<" "<<s+3<<" "<<s+4<<endl;
    cin>>rply;
    all=all^rply;
    ans[1] = rply;
    cout<<1<<" "<<s+3<<" "<<s+4<<" "<<s+1<<endl;
    cin>>rply;
    all=all^rply;
    ans[2] = rply;
    cout<<1<<" "<<s+4<<" "<<s+1<<" "<<s+2<<endl;
    cin>>rply;
    all=all^rply;
    ans[3] = rply;
    a[s]= all^ans[1];
    a[s+1]= all^ans[2];
    a[s+2]= all^ans[3];
    a[s+3]= all^ans[0];
}

void for5(ll a[], ll s) {
    ll rply;
    ll ans[5] { };
    ll all=0;
    cout<<1<<" "<<s+1<<" "<<s+2<<" "<<s+3<<endl;
    cin>>rply;
    all=all^rply;
    ans[0] = rply;
    cout<<1<<" "<<s+2<<" "<<s+3<<" "<<s+4<<endl;
    cin>>rply;
    all=all^rply;
    ans[1] = rply;
    cout<<1<<" "<<s+3<<" "<<s+4<<" "<<s+5<<endl;
    cin>>rply;
    all=all^rply;
    ans[2] = rply;
    cout<<1<<" "<<s+4<<" "<<s+5<<" "<<s+1<<endl;
    cin>>rply;
    all=all^rply;
    ans[3] = rply;
    cout<<1<<" "<<s+5<<" "<<s+1<<" "<<s+2<<endl;
    cin>>rply;
    all=all^rply;
    ans[4] = rply;
    a[s]= all^ans[0]^ans[3];
    a[s+1]= all^ans[1]^ans[4];
    a[s+2]= all^ans[2]^ans[0];
    a[s+3]= all^ans[3]^ans[1];
    a[s+4]= all^ans[4]^ans[2];
}

void for7(ll a[], ll s) {
    ll rply;
    ll ans[7] { };
    ll all=0;
    FORI(0, 6) {
        ll a1 = s+ ((i+1)%7 ? (i+1)%7 : 7);
        ll a2 = s+ ((i+2)%7 ? (i+2)%7 : 7);
        ll a3 = s+ ((i+3)%7 ? (i+3)%7 : 7);
        cout<<1<<" "<<a1<<" "<<a2<<" "<<a3<<endl;
        cin>>rply;
        all=all^rply;
        ans[i] = rply;
    }
    FORI(0, 6) {
        a[s+i] = all^ans[(i+1)%7]^ans[(i+4)%7];
    }
}

int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin>>N;
        ll ans[N] { };
        ll rply;
        
        switch (N%4)
        {
            case 0:
                for(ll i=0; i<N; i+=4) {
                    for4(ans, i);
                }
                break;
            case 1:
                for(ll i=0; i<N-5; i+=4) {
                    for4(ans, i);
                }
                for5(ans, N-5);
            break;
            case 2:
                for(ll i=0; i<N-10; i+=4) {
                    for4(ans, i);
                }
                for5(ans, N-10);
                for5(ans, N-5);
            break;
            case 3:
                for(ll i=0; i<N-7; i+=4) {
                    for4(ans, i);
                }
                for7(ans, N-7);
            break;
        }
        cout<<2;
        FORI(0,N-1) {      
            cout<<" "<<ans[i];
        }
        cout<<endl;
        cin>>rply;
        if(rply==-1) break;
    }
    return 0;
}