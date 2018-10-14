#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> summ,sum, A = { 6, 10, 14, 15, 21, 22, 26, 33, 34, 35, 38, 39, 46, 51, 55, 57, 58, 62, 65, 69, 74, 77, 82, 85, 86, 87, 91, 93, 94, 95, 106, 111, 115, 118, 119, 122, 123, 129, 133, 134, 141, 142, 143, 145, 146, 155, 158, 159, 161, 166, 177, 178, 183, 185, 187, 194};

int main()
{
    int size = A.size();
    for(int i=0; i<size; i++) {
        for(int j=0; j<=i; j++) {
            sum.push_back(A[i]+A[j]);
        }
    }
    sort(sum.begin(),sum.end());
    summ.push_back(sum[0]);
    for(int i=1; i<sum.size(); i++) {
        if(sum[i-1]!=sum[i]) summ.push_back(sum[i]); 
    }
    // for(int i=0; i<summ.size(); i++) {
    //     cout<<summ[i]<<" ";
    // }
    int n=8;
    for(int i=0; i<summ.size(); i++) {
        // if(n==summ[i]) continue;
        while (n!=summ[i]) {
            if(n!=summ[i]) cout<<n<<" ";
            n++;
        }
        n++;
        if(n>200) break;
    }
    return 0;
}
