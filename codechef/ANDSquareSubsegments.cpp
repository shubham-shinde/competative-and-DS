#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int T,N,Q;
    cin>>T;
    for(int q=0;q<T;q++) {
        cin>>N>>Q;
        int *A = new int[N];
        int *L = new int[Q];
        int *R = new int[Q];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<Q;i++) {
            cin>>L[i]>>R[i];
        }
        for(int i=1;i<N;i++) {
            cout<<A[i]<<" "<<A[i-1]<<"  "<<(A[i]&A[i-1])<<endl;
        }
        delete [] A;
        delete [] L;
        delete [] R;
    }
    return 0;
}