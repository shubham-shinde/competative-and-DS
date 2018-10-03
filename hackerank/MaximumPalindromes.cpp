#include <bits/stdc++.h>
using namespace std;

long factorial(int n)
{
    if(n > 1) return (n * factorial(n - 1))%1000000007;
    else return 1;
}

int main() {
    string S;
    cin>>S;
    int len = S.length();
    int Q;
    cin>>Q;
    int A[len];
    for(int i=0; i<len; i++) {
        A[i] = S[i]-'a';
    }
    int L[Q],R[Q];
    int k, odds, r, l, *ar, *a, poi=0;
    for(int q=0; q<Q; q++) {
        cin>>L[q]>>R[q];
    }
    for(int q=0; q<Q; q++) {
        r=R[q];
        l=L[q];
        int lent = r-l+1;
        int ar[lent];
        for(int i=l-1; i<r; i++) {
            ar[i-l+1]=A[i];
        }
        sort(ar, ar + lent);
        int a[lent];
        a[0]=1;
        poi=0;
        for(int i=1; i<lent; i++) {
            if(ar[i]==ar[i-1]) a[poi]++;
            else {
                poi++;
                a[poi]=1;
            }
        }
        k=0;
        odds=0;
        for(unsigned int i=0; i<=poi; i++) {
            if(a[i]%2==0 && a[i]>0) k+=a[i]/2;
            else if(a[i]>1) {
                k+=a[i]/2;
                odds++;
            }
            else odds++;
        }
        if(odds==0) {
            odds=1;
        }
        // cout<<factorial(k)<<endl;
        long Ans=factorial(k);
        cout<<Ans<<endl;
        // cout<<Ans<<endl;
        for(unsigned int i=0; i<=poi; i++) {
            if(a[i]%2==0) Ans/=factorial(a[i]/2);
            else Ans/=factorial((a[i]-1)/2);
        }
        cout<<(Ans*odds)%(1000000007)<<endl;
    }
    return 0;
}