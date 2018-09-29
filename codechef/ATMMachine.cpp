#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin>>T;
    int K, N;
    for(int q=0; q<T; q++) {
        cin>>N>>K;
        int pep[N];
        for(int i=0; i<N; i++) {
            cin>>pep[i];
        }
        char s[N];
        for(int i=0; i<N; i++) {
            if(pep[i]<=K) {
                s[i]='1';
                K-=pep[i];
            }
            else {
                s[i]='0';
            }
        }
        for(int i=0; i<N; i++) {
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
