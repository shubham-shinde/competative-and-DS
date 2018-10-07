#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    long long P1, P2, K;
    for( int i=0; i<T; i++) {
    	cin>>P1>>P2>>K;
    	long long sum = (P1+P2)%(2*K);
    	(sum>=K) ? cout<<"COOK"<<endl : cout<<"CHEF"<<endl ;
    	
    }
    return 0;
}
