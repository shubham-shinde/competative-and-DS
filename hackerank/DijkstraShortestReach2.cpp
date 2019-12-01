#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(k) for(ll i=0; i<k; i++)
ll inf = numeric_limits<ll>::max();

int main() {
    ll tt; cin>>tt;
    while(tt--) {
        ll n,m; cin>>n>>m;
        vector<pair<ll, ll>> a[n];
        ll dist[n];
        vector<vector<ll>> am(n, vector<ll> (n, -1));
        fori(m) {
            ll x, y, w; cin>>x>>y>>w;
            if(am[x-1][y-1] == -1 || am[x-1][y-1] > w) {
                am[x-1][y-1] = w;
                am[y-1][x-1] = w;
            }
        }

        fori(n) for(int j=0; j<i; j++) {
            if(am[i][j] != -1) {
                a[i].push_back({j, am[i][j]});
                a[j].push_back({i, am[i][j]});
            }
        }

        fori(n) {
            dist[i] = inf;
        }

        ll req; cin>>req;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>> , greater<pair<ll, ll>> > q;
        q.push({0, req-1});
        dist[req-1] = 0;

        while (!q.empty()) {
            ll curr = q.top().second;
            q.pop();
            for(auto i : a[curr]) {
                if(dist[i.first] > dist[curr] + i.second) {
                    dist[i.first] = dist[curr] + i.second;
                    q.push({dist[i.first], i.first});
                }
            }
        }
        fori(n) {
            if(dist[i]==inf) {
                dist[i] = -1;
            }
            if(i!= req-1) {
                cout<<dist[i]<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}