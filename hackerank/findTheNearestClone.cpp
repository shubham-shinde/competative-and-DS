#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fori(k) for(ll i=0; i<k; i++)
ll inf = numeric_limits<ll>::max();

int main() {
    ll n,m; cin>>n>>m;
    vector<ll> a[n];
    ll color[n], visited[n], id[n];
    fori(m) {
        ll x, y; cin>>x>>y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }

    fori(n) {
        ll tmp; cin>>tmp;
        color[i] = tmp;
        visited[i] = -1;
        id[i] = -1;
    }

    ll req; cin>>req;

    queue<ll> q;
    fori(n) {
        if(color[i]==req) {
            q.push(i);
            visited[i] = 0;
            id[i] = i;
        }
    }

    ll ans = -1;

    while (!q.empty()) {
        ll curr = q.front();
        for(auto i : a[curr]) {
            if(visited[i] != -1 && id[i]!=id[curr]) {
                ll ansn = visited[i] + visited[curr] + 1;
                if(ans == -1 || ansn < ans) {
                    ans = ansn;
                }
            }
            else if(id[i] == -1) {
                visited[i] = visited[curr] + 1;
                id[i] = id[curr];
                q.push(i);
            }
        }
        if(ans != -1) break;
        q.pop();
    }
    
    cout<<ans<<endl;

    return 0;
}