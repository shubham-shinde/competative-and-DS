#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;

int count(int x, int y) 
{ 
    int ans = 0;  // Initialize result 
      
    unordered_map<int, int> m; 
      
    // calculating remainder 
    while (x % y != 0) { 
  
        x = x % y; 
  
        ans++; 
  
        // if this remainder appeared before then  
        // the numbers are irrational and would not 
        // converge to a solution the digits after 
        // decimal will be infinite 
        if (m.find(x) != m.end())  
            return -1; 
  
        m[x] = 1; 
        x = x * 10; 
    } 
    return ans; 
} 
  


int main() {
    ll T;
    cin>>T;
    while(T--) {
        ll L, R;
        cin>>;
        if(X+Y == Z || Y+Z ==  X || X+Z == Y ) {
            cout<<"yes"<<endl;
            continue;
        }
        cout<<"no"<<endl;
    }
    return 0;
}