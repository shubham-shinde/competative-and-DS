#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int T;
    cin>>T;
    ll N,sum;
    for( ll q=0; q<T; q++) {
    	cin>>N;
        unordered_map<string, ll> B;
        string temp;
        for(ll i=0; i<N; i++) {
            cin>>temp;
            if(B.find(temp) == B.end()) {
                B[temp] = 1;
            }
            else {
                B.at(temp) += 1;
            }
        }
        sum = 0;
        for(auto j=B.begin(); j!=B.end(); j++) {
            ll summ=2;
            string s = j->first;
            for(int i=1; i<s.length(); i++) {
                if (((s[i]=='d' || s[i]=='f') && (s[i-1]=='j' || s[i-1]=='k')) ||
                ((s[i]=='j' || s[i]=='k') && (s[i-1]=='d' || s[i-1]=='f'))) {
                     summ+=2;   
                }
                else if(((s[i]=='d' || s[i]=='f') && (s[i-1]=='f' || s[i-1]=='d')) ||
                        ((s[i]=='k' || s[i]=='j') && (s[i-1]=='j' || s[i-1]=='k'))) {
                    summ+=4;
                }
            }
            // cout<<summ<<" "<<j->first<<" "<<j->second<<endl;
            sum+=summ;
            sum+=(summ/2)*((j->second)-1);
        }
        cout<<sum<<endl;
    }
    return 0;
}