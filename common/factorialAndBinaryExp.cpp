#include <bits/stdc++.h>
using namespace std;

const long long MAX=1000000007;

long long binary_exp(long long x, long long n)
{
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x % MAX;
    } else {
        long long int temp = binary_exp(x, n / 2);
        temp = (temp * temp) % MAX;
         
        if (n % 2 == 0) {
            return temp;
        } else {
            return ((x % MAX) * temp) % MAX;
        }
    }
}

long long factorial(int n,int max)
{
    if(n <= max) return max;  
    else return (n%(MAX)) * (factorial(n - 1, max)%(MAX));
}

int main() {
    for(int i=1; i<=50; i++) {
        cout<<i<<" "<<factorial(i, 1)<<" "<<binary_exp(i, MAX-2)<<endl;
    }
}