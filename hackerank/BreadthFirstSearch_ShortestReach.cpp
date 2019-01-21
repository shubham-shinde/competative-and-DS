#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FORI(s, n) for(int i=s; i<=n; i++)
const int eW = 6; //edge weight


template<typename T>  //print list and vector
void print_map (T t) {
	for (const auto& e : t) {
		cout<<e.first<<" -> ";
		for(auto& i: e.second) {
			cout<<i<<" ";
		}
		cout<<endl;
	}
}

template<typename T>  //print list and vector
void print (T t) {
	for (const auto& e : t) cout << e << " ";
	cout << endl;
}

void BFS(unordered_map<int, vector<int>> &g, vector<int> &dis, int vertex, int d) {
    for(auto i : g[vertex]) {
        if(dis[i-1] > d+eW || dis[i-1] < 0 ) {
            dis[i-1] = d+eW;
            BFS(g, dis, i , d+eW);
        }
    }
}

vector<int> sortestReach(unordered_map<int, vector<int>> &graph, int first) {
    vector<int> ret;
    ret.resize( graph.size(), -1);
    ret[first-1] = 0;
    BFS(graph, ret, first, 0);
    return ret;
}

int main()
{
    int T; cin >> T;
    int n,m;

    while(T--) {
        cin>>n>>m;
        unordered_map<int, vector<int>> graph;
        FORI(1, n) graph[i];
        FORI(0,m-1) {
            int f,s; cin>>f>>s;
            graph[f].push_back(s);
            graph[s].push_back(f);
        }
        int s; cin>>s;
        print_map(graph);
        auto e = sortestReach(graph, s);
        for(auto i : e) if(i!=0) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}