#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    long long N;
    for( int i=0; i<T; i++) {
        long long a[3] {0};
    	cin>>N;
    	long long sum = (N/26);
        sum= pow(2, sum);
        long long mod = N%26;
      	if(mod==0) {
      		a[2]=1;
            sum/=2;
      	}
        else if(mod<= 2) {
            a[0] = 1;
        }
        else if (mod<=10) {
            a[1] = 1;
        }
        else if (mod<=26) {
            a[2] = 1;
        }
    	for(int i=0; i<3 ; i++) {
            cout<<a[i]*sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
