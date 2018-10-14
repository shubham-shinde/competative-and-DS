#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int T;
    cin>>T;
    ll N;
    for( int q=0; q<T; q++) {
    	cin>>N;
        int a[N];
        for(int i=0; i<N; i++) {
            cin>>a[i];
        }
        int day=1, sum=a[0], sumind=1;
        // bool complete=false;
        while(sum <= N) {
            int summ=0;
            int i;
            for(i=0; i<sum; i++) {
                summ+=a[sumind+i];
            }
            day++;
            sumind=i+1;
            sum+=summ;
        }
        cout<<day-1<<endl;
    }
    return 0;
}