#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

int countReservior(ll a[], int start, int end) {
    ll max=a[start],index=start;
    if(start==end)
    return 1;
    FORI(start+1, end) {
        if(a[i]>max) {
            max=a[i];
            index=i;
        }
    }
    if(abs(end - start)<=2) {
        return (index==start || index==end) ? 1: 2;
    }
    if(index==start || index==end) return 1;
    int first = countReservior(a, start, index-1);
    int second = countReservior(a, index+1, end);
    return (first > second) ? second+1 : first+1;
}

int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin>>N;
        ll a[N];
        FORI(0, N-1) cin>>a[i];
        cout<<countReservior(a, 0, N-1)<<endl;
    }
    return 0;
}
