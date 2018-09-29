#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the absolutePermutation function below.
int main() {
    int T;
    cin>>T;
    for(int q=0; q<T; q++) {
        int n,k;
        cin>>n>>k;
        int f,n_half=n/2;
        if(k==0) {
            for(int i=1; i<=n; i++) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if(k<=n_half && n%(k*2)==0) {
            f=1;
            for(int i=1; i<=n; i++) {
                if(f==1) {
                    cout<<i+k<<" ";
                }
                else {
                    cout<<i-k<<" ";
                }
                if(i%k==0) {
                    f==1 ? f=0 : f=1;
                }
            }
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}