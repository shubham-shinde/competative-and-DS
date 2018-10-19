#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// 111011100110101100101000000000

int decToBinary(int n) 
{ 
    // Size of an integer is assumed to be 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            cout << "1"; 
        else
            cout << "0"; 
    } 
} 

int main()
{
    int T;
    cin>>T;
    ll A,B,C;
    for( ll q=0; q<T; q++) {
    	cin>>A>>B>>C;
    }
    return 0;
}