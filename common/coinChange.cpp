#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(k) for(ll i=0; i<k; i++)
ll inf = numeric_limits<ll>::max();

ll coinChange(vector<ll> coins, ll count) {
    sort(coins.begin(), coins.end());
    vector<ll> c;
    c.push_back(1);
    for(int i=1; i<=count; i++) {
        ll curr = 0;
        for(auto j : coins) {
            if(i-j >= 0) {
                curr+=c[i-j];
            } 
        }
        c.push_back(curr);
    }
    return c[c.size()-1];
}

int main() {
    coinChange({2,3, 4}, 10);
    return 0;
}