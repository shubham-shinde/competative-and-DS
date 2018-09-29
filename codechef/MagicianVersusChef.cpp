#include<iostream>
using namespace std;

int main() {
    unsigned short int T,N,X,S,A,B;
    cin>>T;
    cin>>N>>X>>S;
    while(S > 0) {
        cin>>A>>B;
        if(A == X) {
            X = B;
        }
        else if(B == X) {
            X = A;
        }
        S--;
    }
    cout<<X;
    return 0;
}