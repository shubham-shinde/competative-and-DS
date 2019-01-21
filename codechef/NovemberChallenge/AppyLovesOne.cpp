#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
typedef long long ll;

int main() {
    ll N,Q,K;
    cin>>N>>Q>>K;
    bool a[N];
    FORI(0, N) {
        char temp;
        cin>>temp;
        a[i%N] = temp=='1' ? true : false;
    }
    ll k=0;
    FORI(0, N) if(a[i]==false) {
        k=i;
        break;
    }
    bool allAreOne=false;
    if(k==0 && a[0]!=false) {
        allAreOne=true;
    }
    // cout<<" K "<<k<<endl;
    ll Max=0, Min=0, s=0, e=0;
    ll count=0, s_temp;
    FORI(k, N+k+1) {
        if(count==0 && a[i%N]==true) {
            count++;
            s_temp=i%N;
        }
        else if(count>0 && a[i%N]==true) {
            count++;
        }
        else if(a[i%N]==false && count>0) {
            if(count > e-s) {
                Min = e-s;
                s=s_temp;
                e=i%N;
            }
            else if (count > Min) Min=i-s_temp;
            count=0;
        }
    } 
    Max = e-s<0 ? e+N-s : e-s;
    // cout<<"Max"<<Max<<endl;
    // cout<<"Min"<<Min<<endl;
    // cout<<"e, s"<<e<<" "<<s<<endl;
    ll b=0;
    FORI(0, Q) {
        char query;
        cin>>query;
        // cout<<" b "<<b;
        if(query=='!') b = b-1==-1 ? N-1 : b-1;
        else {
            if(allAreOne) {
                N>K ? cout<<K<<endl : cout<<N<<endl;
            }
            else if(e-s >=0 ) {
                if(b>=s && b<=e+1) {
                    ll m = max(b-s, e-b);
                    m= max(m, Min);
                    m>K ? cout<<K<<endl : cout<<m<<endl;
                }
                else {
                    (e-s)>K ? cout<<K<<endl : cout<<e-s<<endl;
                }
            }
            else {
                if((b>=s && b<N) || (b>=0 && b<=e)) {
                    ll m = max(b-s<0 ? N-s+b : b-s , b-s<0 ? e-b : N-b+e);
                    m= max(m, Min);
                    m>K ? cout<<K<<endl : cout<<m<<endl;
                }
                else {
                    Max>K ? cout<<K<<endl : cout<<Max<<endl;
                }
            }
        }
    }
    return 0;
}