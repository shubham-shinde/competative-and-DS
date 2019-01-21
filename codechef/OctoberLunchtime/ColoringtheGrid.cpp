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
        ll N, M;
        cin>>N>>M;
        ll a[N][M];
        int b[N][M] { };
        FORI(0, N-1) {
            FORJ(0, M-1) cout<<b[i][j]<<" ";
            cout<<endl;
        }
        char temp;
        FORI(0, N-1) FORJ(0, M-1) {
            cin>>temp;
            if(temp == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
        FORI(1, N-1) FORJ(1, M-1) {
            if(a[i-1][j]!=0 && a[i-1][j-1]!=0 && a[i][j-1]!=0 && a[i][j]!=0) {
                b[i-1][j]=1;
                b[i-1][j-1]=1;
                b[i][j-1]=1;
                b[i][j]=1;
            }
        }
        bool yes = true;
        FORI(0, N-1) {
            FORJ(0, M-1) cout<<b[i][j]<<" ";
            cout<<endl;
        }
        FORI(0, N-1) FORJ(0, M-1) {
            if(b[i][j]==0 && a[i][j]!=0) {
                yes = false;
                break;
            }
            if(yes==false) break;
        }
        yes ? cout<<"YES": cout<<"NO";
        cout<<endl;
    }
    return 0;
}