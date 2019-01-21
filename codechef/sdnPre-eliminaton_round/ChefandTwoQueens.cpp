#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;

int calcSafe(ll i, ll j, ll N, ll M) 
{    
    // calc distance in four direction 
    int dis_11 = min ( abs(1-i), abs (1-j)); 
    int dis_18 = min ( abs(1-i), abs (M-j)); 
    int dis_81 = min ( abs(N-i), abs (1-j)); 
    int dis_88 = min ( abs(N-i), abs (M-j)); 
  
    // calc total sum of distance  + 1 for unsafe positions 
    int sum = dis_11 + dis_18 + dis_81 + dis_88 + 1; 
  
    // return total safe positions 
    return (M*N - sum); 
} 


int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N, M, X, Y;
        cin>>N>>M>>X>>Y;
        X-=1;
        Y-=1;
        ll a[N][M] { };
        a[X][Y] = 1;
        ll all = 0;
        FORI(0, N-1) FORJ(0, M-1) {
            all+= calcSafe(i,j,N,M);
            all-= N + M;
            if(X==i) {
                all+= Y>j ? M-j+1 : j;
            }
            else if(Y==j) {
                all+= X>i ? N-i+1 : i;
            }
            else {
                bool slop = abs(X-i) == abs(Y-j);
                if(slop) {
                    
                }
            }
        }    
        cout<<all<<endl;    
    }
    return 0;
}