#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define FORI(s, n) for(ll i=s; i<=n; i++)


template<typename T>  //print list and vector
void print (T t) {
	for (const auto& e : t) cout << e << " ";
	cout << endl;
}

template<typename T> 
void print (T t, int n) {
	for (int i=0; i<n; i++) {
        cout<<t[i]<<' ';
    }
    cout<<endl;
}


int main()
{
    ll T; cin >> T;
    while(T--) {
        string n; cin>>n;
        ll sz=n.size();
        int a[sz];
        FORI(0, sz-1) {
            a[i] = n[i] - 48;
        }
        rotate(a, a+sz-1, a+sz);
        ll mul_by = 1;
        for(ll j=0; j<sz; j++) {
            mul_by = (mul_by%mod)*(10%mod);
        }
        
        ll mul = 1;
        ll ans = 0;
        FORI(0, sz-1) {
            ll kd=1, num=0;
            for(ll j=sz-1; j>=0; j--) {
                num+=a[j]*kd;
                kd*=10;
            }
            // cout<<num<<" ";
            num = ((num%mod)*(mul%mod))%mod;
            // cout<<num<<"num"<<' '<<mul<<' ';
            ans=(ans%mod + num%mod)%mod;
            mul = (mul%mod)*(mul_by%mod);
            rotate(a,a+sz-1, a+sz);
        }
        cout<<ans<<endl;
    }
    return 0;
}