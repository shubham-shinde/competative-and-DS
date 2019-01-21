#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(auto i=s; i<=n; i++)
#define FORJ(s, n) for(auto j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(auto i=s; i>=n; i--)
#define FORJMINUS(s, n) for(auto i=s; i>=n; i--)
typedef long long ll;

void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 


void printAdjecencyMap(unordered_map<int, list<int>> adj) {
    for(auto i : adj) {
        cout<<i.first<<"  ";
        showlist(i.second);
        cout<<endl;
    }
}


int DFS(unordered_map<int, vector<int>> &Adj,bool V[],int vertex) {
    int sum=1;
    V[vertex]=true;

    if(Adj.find(vertex) == Adj.end()) return 1;

    for(auto i : Adj[vertex]) {
        if(!V[i]) {
            sum+=DFS(Adj, V, i);
        }
    }
    return sum;
}

int main() {
    ll N,P;
    cin>>N>>P;
    unordered_map<int, vector<int>> adj;
    FORI(0, P-1) {
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);

        adj[b].push_back(a);
    }

    bool V[N] { false };

    ll sol[N] { };

    FORI(0, N-1) {
        if(!V[i]) {
            sol[i]=DFS(adj, V, i);
        }
    }

    // cout<<endl;

    // for(auto i : sol) cout<<i<<" ";

    
    ll sum = 0;
    ll result = 0;
    FORI(0, N-1)
    {
        result += sum*sol[i];
        sum += sol[i];    
    }   
    cout<<result<<endl;

    
    return 0;
}

