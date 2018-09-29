#include<stdio.h>

int main() {
    int T,N,X,S,A,B;
    scanf("%d",&T);
    scanf("%d %d %d",&N, &X, &S);
    while(S > 0) {
        scanf("%d %d",&A, &B);
        if(A == X) {
            X = B;
        }
        else if(B == X) {
            X = A;
        }
        S--;
    }
    printf("%d",X);
    return 0;
}