#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(k) for(ll i=0; i<k; i++)
ll inf = numeric_limits<ll>::max();

int main() {
        ll n,st, ed,m; cin>>n>>ed>>st>>m;
        vector<pair<ll, ll>> a[n];
        ll dist[n];
        fori(m) {
            ll x, y, w; cin>>x>>y>>w;
            a[x-1].push_back({y-1, w});
        }

        fori(n) {
            dist[i] = inf;
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>> , greater<pair<ll, ll>> > q;
        q.push({0, ed-1});
        dist[ed-1] = 0;

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
        ll count = 0;
        for(auto i: dist) {
            if(i <= st) count++;
        }
        cout<<count;
        cout<<endl;
    return 0;
}