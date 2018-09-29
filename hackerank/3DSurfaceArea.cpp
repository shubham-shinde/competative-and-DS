#include <bits/stdc++.h>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
    unsigned int m=A.size(), n=A[0].size();
    int Area=2*m*n;
    int a[n] {0};
    // cout<<Area<<endl;
    for(unsigned int i=0; i<m; i++) {
        for(unsigned int j=0; j<n; j++) {
            // cout<<A[i][j]<<" "<<a[j]<<endl;
            if(i==0) {
                a[j]+=2*A[i][j];
            }
            else if(A[i][j]>A[i-1][j]) {
                a[j]+=2*(A[i][j]-A[i-1][j]);
            }
        }
    }
    for(unsigned int j=0; j<n; j++) {
        Area+=a[j];
    }
    // cout<<Area<<endl;
    int b[m]{0};
    for(unsigned int i=0; i<n; i++) {
        for(unsigned int j=0; j<m; j++) {
            // cout<<A[j][i]<<" "<<b[j]<<endl;
            if(i==0) {
                b[j]+=2*A[j][i];
            }
            else if(A[j][i]>A[j][i-1]) {
                b[j]+=2*(A[j][i]-A[j][i-1]);
            }
        }
    }
    for(unsigned int j=0; j<m; j++) {
        Area+=b[j];
    }
    return Area;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> A(m);
    for (int i = 0; i < m; i++) {
        A[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    int l=surfaceArea(A);
    cout<<l;
    return 0;
}