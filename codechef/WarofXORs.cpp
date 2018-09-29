#include<iostream>
using namespace std;

int main() {
    int T,N,C,a;
    cin>>T;
    int t=0;
    int sum=0;
    for(int i=0; i<T; i++) {
        cin>>N;
        C=0;
        t=0;
        int A[N];
        for(int i=0; i<N; i++) {
            cin>>A[i];
            if(A[i]%2==0) {
                t++;
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=i+1; j<N; j++) {
                a = A[i]^A[j];
                // if(a%2==0 && a==2) {
                    cout<<A[i]<<" "<<A[j]<<"      "<<a<<"\n";
                // }
                if(a%2==0 && a!=2 && a!=0) {
                    C++;
                }
            }
        }
        cout<<C<<" "<<t;
        for(i=0;i<t;i++) {
            sum=sum+i+1;
        }
        cout<<sum;
    }
    return 0;
}