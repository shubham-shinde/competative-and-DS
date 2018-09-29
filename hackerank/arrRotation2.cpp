#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, r;
    cin>>n>>m>>r;
    int a[n][m];
    int arraySize= n<m ? n/2 : m/2;
    for(int i=0; i<n ;i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }
    // for(int i=0; i<n ;i++) {
    //     for(int j=0; j<m; j++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int row=0, col=0;
    vector<vector<int *>> matrix;

    for(int q=0; q<arraySize; q++) {
        vector<int *> fuck;
        for(int i=col; i<(m-col); i++) {
            fuck.push_back(&a[row][i]);
        }
        for(int i=row+1; i<(n-row); i++) {
            fuck.push_back(&a[i][m-col-1]);
        }
        for(int i=m-1-col; i>col; i--) {
            fuck.push_back(&a[n-1-row][i-1]);
        }
        for(int i=n-1-row; i>row+1; i--) {
            fuck.push_back(&a[i-1][col]);
        }
        matrix.push_back(fuck);
        row++;
        col++;
    }

    // for(unsigned int i=0; i<matrix.size(); i++) {
    //     for(unsigned int j=0; j<matrix[i].size(); j++) {
    //         cout<<*matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
    for(unsigned int i=0; i<matrix.size(); i++) {
        int rr=r%matrix[i].size();
        vector<int> temp;
        for(unsigned int j=0; j<rr; j++) {
            temp.push_back(*matrix[i][j]);
        }
        for(unsigned int j=rr; j<matrix[i].size(); j++) {
            *matrix[i][j-rr]=*matrix[i][j];
        }
        for(unsigned int j=0; j<rr; j++) {
            *matrix[i][j+matrix[i].size()-rr]=temp[j];
        }

    }

    // for(unsigned int i=0; i<matrix.size(); i++) {
    //     for(unsigned int j=0; j<matrix[i].size(); j++) {
    //         cout<<*matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<n ;i++) {
        for(int j=0; j<m; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}