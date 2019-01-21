#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
#define FORJ(s, n) for(auto j=s; j!=n; j++)
#define MAX_SIZE_A 100000
typedef long long ll;

int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll N;
        cin>>N;
        // ll A[MAX_SIZE_A] { };
        ll AA[N];
        bool possible = false;
        FORI(0,N) {
            cin>>AA[i];
            // A[AA[i]] = i; 
        }
        FORI(0,N) {
            FORJ(i+1, N) {
                if(AA[i]!=AA[j] && AA[AA[i]-1] == AA[AA[j]-1]) {
                    possible = true;
                    break;
                }
            }
            if(possible) break;
        }
        possible ? cout<<"Truly Happy"<<endl : cout<<"Poor Chef"<<endl;
    }
    return 0;
}