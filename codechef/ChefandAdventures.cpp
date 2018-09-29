#include<iostream>
using namespace std;

int main() {
    int T;
    cin>>T;
    int N,M,X,Y,n,m;
    bool arr[T];
    for(int i=0; i<T; i++) {
        cin>>N>>M>>X>>Y;
        N = N-1;
        M = M-1;
        n = N%X;
        m = M%Y;
        if(N==M && M<=1) {
            arr[i] = true;
        }
        else if((M==0 && N==1 && X==2 && Y==1) || (M==1 && N==0 && X==1 && Y==2)) {
            arr[i] = false;
            // cout<<1<<" ";
        }
        else if(X==Y && X==1) {
            arr[i] = true;
            // cout<<2<<" ";
        }
        else if((M==1 && X==1 && N>1) || (N==1 && Y==1 && M>1)) {
            arr[i] = true;
            // cout<<3<<" ";
        }
        else if((n==0 && Y==1) || (m==0 && X==1)) {
            arr[i]=true;
            // cout<<4<<" ";
        }  
        else if(((n==0 || n==1) && Y==1) && ((m==0 || m==1) && X==1)) {
            arr[i]=true;
            // cout<<5<<" ";
        } 
        else if((X==2 && Y==1 && M>1) || (Y==2 && X==1 && N>1)) {
            arr[i]=true;
            // cout<<6<<" ";
        } 
        else if((X==1 && m<=1 && N>0) || (Y==1 && n<=1 && M>0)) {
            arr[i]=true;
            // cout<<7<<" ";
        } 
        else if(n==m && (n==0 || n==1)) {
            arr[i]=true;
            // cout<<8<<" ";
        }
        else {
            arr[i]=false; 
            // cout<<9<<" ";
        }               
        arr[i] ? cout<<"Chefirnemo\n" : cout<<"Pofik\n";
    }
    // for(int i=0; i<T; i++) {
    //     arr[i] ? cout<<"Chefirnemo\n" : cout<<"Pofik\n";
    // }
    return 0;
}