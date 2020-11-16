#define ll long long
#define ld long double
#define mod 1000000007LL
#define eps 1e-13
#define PI 3.141592653589793238L
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define endl '\n'
#define vi vector<int>
// #define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
// #define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mp make_pair
#define F first
#define S second
#define pb(x) push_back(x)
#define fo(i,a,n) for(i = (a); i < (n); i++)
#define foi(i,a,n) for(i = (a); i <= (n); i++)
#define pd(x) cout<<x
#define sd(x) cin>>x
#define nl cout<<endl
#define gtl(x) getline(cin, (x))
#define flsh fflush(stdout)
#define sws ios_base::sync_with_stdio(false); cin.tie(0)
#define gcd __gcd
#define clr(x) memset(x,0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(a) (int)((a).size())


#define FORI(s, n) for(int i=s; i<=n; i++)

ll mul(ll n, ll x) {
	return ((n%mod)*(x%mod))%mod;
}
ll sum(ll n, ll x) {
	return ((n%mod)+(x%mod))%mod;
}
ll sub(ll n, ll x) {
	return ((n%mod)-(x%mod))%mod;
}

// defining 2D vector of defined size ---  vector<vector<long>> dp(row, vector<long> (col, -1));

template<typename T>  //print list and vector
void print (T t) {
	for (const auto& e : t) cout << e << " ";
	cout << endl;
}

template<typename T>  //print list and vector
void print_map (T t) {
	for (const auto& e : t) {
		cout<<t.first<<" -> ";
		for(auto& i: t.second) {
			cout<<t<<" ";
		}
		cout<<endl;
	}
}

//building graph ---------------------------------------------
		unordered_map<int, vector<int>> graph;
        FORI(1, n) graph[i].push_back(0);
        FORI(0,m-1) {
            int f,s; cin>>f>>s;
            graph[f].push_back(s);
            graph[s].push_back(f);
        }
        print_map(graph);

//lambda function for sorting string with its length
auto sortByLength = [](const auto& a, const auto& b) { return a.size () < b.size (); };
sort (v.begin (), v.end (), sortByLength);
