#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll T; cin>>T;
    while(T--) {
        ll n, p; cin>>n>>p;
        ll max = 0, count = 0, mod;
        for(int i=1; i<=p; i++) {
            for(int j=1; j<=p; j++) {
                for(int k=1; k<=p; k++) {
                    mod = n%i%j%k%n;
                    if(mod==max) {
                        count++;
                    }
                    else if(mod>max) {
                        max = mod;
                        count=1;
                    }
                }
            }
        }
        cout<<count<<' '<<max<<endl;
    }
    return 0;
}