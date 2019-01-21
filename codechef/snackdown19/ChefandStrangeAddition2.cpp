#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long T;
    cin>>T;
    long long A,B,C;
    while(T--) {
    	cin>>A>>B>>C;
        long long arrOfDp[50][50][50][2] {0};
        long long arr[40] {0};
        long long tp=1,c1=0,c2=0;
        while(C>0) {
            arr[tp++]=C%2;
            C/=2;
        }
        while(A>0) {
            if(A%2!=0) c1++;
            A/=2;
        }
        while(B>0) {
            if(B%2>0) c2++;
            B/=2;
        }
        arrOfDp[0][c1][c2][0]=1;
        for(long long i=1; i<35; i++) {
            if(arr[i]==1) {
                for(int j=0; j<=34; j++) {
                    for(int tp=0; tp<=34;tp++) {
                        arrOfDp[i][j][tp][0]+=(arrOfDp[i-1][j][tp+1][0]+arrOfDp[i-1][j][tp][1]+arrOfDp[i-1][j+1][tp][0]);
                        arrOfDp[i][j][tp][1]+=(arrOfDp[i-1][j+1][tp+1][1]);
                    }
                }
            }
            else {
                for(int j=0; j<34; j++) {
                    for(int tp=0; tp<=34; tp++) {
                        arrOfDp[i][j][tp][0]+=(arrOfDp[i-1][j][tp][0]);
                        arrOfDp[i][j][tp][1]+=(arrOfDp[i-1][j+1][tp+1][0]+arrOfDp[i-1][j][tp+1][1]+arrOfDp[i-1][j+1][tp][1]);
                    }
                }
            }
        }
        cout<<arrOfDp[34][0][0][0]<<endl;
    }
    return 0;
}