#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll *min_num, *attempt;

ll digitSum(ll n) 
{ 
    ll sum; 
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
    return sum; 
} 

void minimumDigitsum(ll N, ll D,int this_attempt) {
    if(N<*min_num || (N==*min_num && this_attempt<*attempt)) {
        *min_num=N;
        *attempt=this_attempt;
    }
    if(this_attempt>10) return;

    if(N>9) minimumDigitsum(digitSum(N), D, this_attempt+1);

    minimumDigitsum(N+D, D, this_attempt+1);
}

int main()
{
    int T;
    cin>>T;
    ll N, D;
    for( int i=0; i<T; i++) {
    	cin>>N>>D;
    	ll min=N, att=0;
        min_num=&min;
        attempt=&att;
        minimumDigitsum(N, D, 0);
        cout<<min<<" "<<att<<endl;
    }
    return 0;
}
