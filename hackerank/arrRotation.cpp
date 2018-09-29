#include<bits/stdc++.h>
using namespace std;

void rotateArray(vector<vector<int>> a,int r) {
    int first=a[0][0], row=0,col=0;
    int rowLength=a.size();
    int colLength=a[0].size();
    for(int k=0; k<r; k++) {
        row=0;
        col=0;
        while(row<rowLength/2 && col<colLength/2) {
            first=a[row][col]; 
            for(unsigned int i=col+1; i<(colLength-col); i++) {
                a[row][i-1]=a[row][i];
            }        
            for(unsigned int i=row+1; i<(rowLength-row); i++) {
                a[i-1][colLength-col-1]=a[i][colLength-col-1];
            }        
            for(unsigned int i=colLength-1-col; i>col; i--) {
                a[rowLength-1-row][i]=a[rowLength-1-row][i-1];
            }         
            for(unsigned int i=rowLength-1-row; i>row; i--) {
                a[i][col]=a[i-1][col];
            }
            a[row+1][col]=first;
            row++;
            col++;
        }
    }
    for(unsigned int i=0; i<a.size(); i++) {
        for(unsigned int j=0; j<a[0].size(); j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> a {{1, 2, 3, 4},{7, 8, 9, 10},{13, 14, 15, 16},{19, 20, 21, 22},{25, 26, 27, 28}};
    int r;
    for(unsigned int i=0; i<a.size(); i++) {
        for(unsigned int j=0; j<a[0].size(); j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cin>>r;
    rotateArray(a, r);
    return 0;
}