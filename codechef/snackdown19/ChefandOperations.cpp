#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin>>T;
    ll N;
    for( ll q=0; q<T; q++) {
    	cin>>N;
        int stop=0;
        ll a[N], b[N], c[N];
        for(ll i=0; i<N; i++) {
            cin>>a[i];
        }
        for(ll i=0; i<N; i++) {
            cin>>b[i];
        }
        for(ll i=0; i<N; i++) {
            c[i] = b[i] - a[i];
        }
        for(ll i=0; i<=N-3; i++) {           
            if(c[i]<0) {
                stop=1;
                break;
            }
            else if(c[i]>0){
                c[i+1] -= 2*c[i];
                c[i+2] -= 3*c[i];
                c[i] = 0;
            }
        }
        // cout<<stop<<endl;
        if(stop==0 && (c[N-2]!=0 || c[N-1]!=0)) {
            stop=1;
        }
        stop==0 ? cout<<"TAK"<<endl : cout<<"NIE"<<endl;
    }
    return 0;
}