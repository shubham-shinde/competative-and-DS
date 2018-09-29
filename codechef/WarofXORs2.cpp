#include<iostream>
#include<algorithm>
using namespace std;

long int seriesSum(long int x) {
    long int sum=0;
    for(long int i=0;i<x-1;i++) {
        sum=sum+i+1;
    }
    return sum;
}

long int noToMinus(long int arr[],long int n) {
    long int Count[n], A[n],c=0,sum=0;
    Count[0]=0;
    A[0]=arr[0];
    for(long int j=0;j<n;j++) {
        if(arr[j]==A[c]) {
            Count[c]++;
        }
        else {
            c++;
            A[c]=arr[j];
            Count[c]=1;
        }
    }
    for(long int j=1;j<c+1;j++) {
        if((A[j-1]^A[j])==2) {
            sum=sum+(Count[j-1]*Count[j]);
        }
    }
    for(long int j=0;j<c+1;j++) {
        sum+=seriesSum(Count[j]);
    }
    return sum;
}

int main() {
    long int T,N,Input,x,y,minus;
    cin>>T;
    for(long int q=0;q<T;q++) {
        cin>>N;
        long int *E = new long int[N];
        long int *O = new long int[N];
        x=0;
        y=0;
        for(long int i=0; i<N; i++) {
            cin>>Input;
            if(Input%2==0) {
                E[x]=Input;
                x++;
            }
            else {
                O[y]=Input;
                y++;
            }
        }
        sort(E, E+x);
        sort(O, O+y);
        minus=noToMinus(O, y)+noToMinus(E, x);
        cout<<seriesSum(x)+seriesSum(y)-minus<<endl;
        delete [] E;
        delete [] O;
    }
    return 0;
}