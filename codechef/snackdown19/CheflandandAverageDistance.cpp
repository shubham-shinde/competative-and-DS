#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int T;
    cin>>T;
    while (--T >= 0) {
        int N,M;
        cin>>N>>M;
        vector<int> arr1, arr2;
        for (int i = 0; i < N; i++) {
            string s;
            cin>>s;
            for (int j = 0; j < M; j++) {
                if (s[j] == '1') {
                    int index = j + 1;
                    arr1.push_back(i + 1);
                    arr2.push_back(index);
                }

            }
        }
        int ans[N+M-2]{0};
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = i+1; j < arr1.size(); j++) {
                int a=arr1[i];
                int b=arr2[i];
                int c=arr1[j];
                int d=arr2[j];
                int dis=abs(a-c)+abs(b-d);
                if(1<=dis&&dis<=N+M-2) {
                    ans[dis-1]++;
                }
            }
        }
        for(int i=0;i<N+M-2;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
