#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FORI(s, n) for(int i=s; i<=n; i++)

int main()
{
    int T; cin >> T;
    while(T--) {
        int D; cin>>D;
        vector<vector<int>> dp;
        dp.resize(D, vector<int> (2, 0));
        FORI(0, D-1) cin>>dp[i][0]>>dp[i][1];
        int Q; cin>>Q;
        FORI(0, Q-1) {
            int a,b; cin>>a>>b;
            int ques=0;
            for(auto j : dp) {
                if(j[0]>a) break;
                ques+=j[1];
            }
            ques < b ? cout<<"Go Sleep" : cout<<"Go Camp";
            cout<<endl;
        }
    }
    return 0;
}
