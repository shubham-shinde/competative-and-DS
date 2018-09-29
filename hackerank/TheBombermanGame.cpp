#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
string *bomberMan(int n, string *grid, int row, int col) {
    int k=1;
    if(n==1 || n==0) {
        return grid;
    }
    else if (n%2==0 && n>=2) {
        for(unsigned int i=0; i<row; i++) {
            for(unsigned int j=0; j<col; j++) {
                grid[i][j]='O';
            }
        }
        return grid;
    }
    else {
        string *a= new string[row];

        for (int i=0; i<row; i++) {
            a[i].resize(col);
            for(int j=0; j<col; j++) {
                a[i][j]=grid[i][j];
            }
        }
        if((n-1)%4==0) {            
            while(k!=5) {
                k+=2;
                char b = 'O';
                string *g = new string[row];
                for(int i=0; i<row; i++) {
                    g[i].resize(col);
                    for(int j=0; j<col; j++) {
                        if(
                            (i>0 && a[i-1][j]==b) || 
                            (i<row-1 && a[i+1][j]==b) || 
                            (j>0 && a[i][j-1]==b) || 
                            (j<col-1 && a[i][j+1]==b) ||
                            (a[i][j]==b)
                        ) {
                        g[i][j]='.'; 
                        }
                        else {
                            g[i][j]='O';
                        }
                    }
                }
                for (int i=0; i<row; i++) {
                    for(int j=0; j<col; j++) {
                        a[i][j]=g[i][j];
                    }
                }
                delete [] g;
            }
            return a;
        }
        while(k!=3) {
            k+=2;
            char b = 'O';
            string *g = new string[row];
            for(int i=0; i<row; i++) {
                g[i].resize(col);
                for(int j=0; j<col; j++) {
                    if(
                        (i>0 && a[i-1][j]==b) || 
                        (i<row-1 && a[i+1][j]==b) || 
                        (j>0 && a[i][j-1]==b) || 
                        (j<col-1 && a[i][j+1]==b) ||
                        (a[i][j]==b)
                    ) {
                       g[i][j]='.'; 
                    }
                    else {
                        g[i][j]='O';
                    }
                }
            }
            for (int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                    a[i][j]=g[i][j];
                }
            }
            delete [] g;
        }
        return a;
    }
}

int main()
{
    int row,col,t;
    cin>>row>>col>>t;
    string a[row];

    for (int i=0; i<row; i++) {
        a[i].resize(col);
        for(int j=0; j<col; j++) {
            cin>>a[i][j];
        }
    }

    string *grid = bomberMan(t, a, row, col);

    for (int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

    return 0;
}
