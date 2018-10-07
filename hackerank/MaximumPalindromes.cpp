#include <bits/stdc++.h>
using namespace std;

const int No_Char=26;
const long long MAX=1000000007;
const long long fact[] =  {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 3178290612, 2674358865, 10789741616, 13425606282, 7660911438, 12557316391, 11146326140, 3072847323, 1602640644, 13860734651, 20657629440, 16440732500, 11459042088, 12394134297, 11035757964, 1036978723, 1109361480, 3390205663, 12486580544, 16057155180, 1943272312, 33014530675, 523095984, 19354551408, 13472948450, 18444986001, 17799435000, 32776830121, 32626855674, 26954784350, 42010503392, 472639410, 21741412860, 34846397511, 40627069104, 30726372376, 36318608300 };
const long long bin[] = {1, 500000004, 333333336, 250000002, 400000003, 166666668, 142857144, 125000001, 111111112, 700000005, 818181824, 83333334, 153846155, 71428572, 466666670, 562500004, 352941179, 55555556, 157894738, 850000006, 47619048, 409090912, 739130440, 41666667, 280000002, 576923081, 370370373, 35714286, 758620695, 233333335, 129032259, 281250002, 939393946, 676470593, 628571433, 27777778, 621621626, 78947369, 717948723, 425000003, 658536590, 23809524, 395348840, 204545456, 822222228, 369565220, 404255322, 520833337, 448979595, 140000001 };

long long binary_exp(long long x, long long n)
{
    if(x<=50) return bin[x-1];
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
    if(n<=50 && n!=0) return fact[n-1]%MAX;
    if(n <= max) return max;  
    else return (n%(MAX)) * (factorial(n - 1, max)%(MAX));
}

int main() {
    string S;
    cin>>S;
    long len = S.length();
    long Q;
    cin>>Q;
    long A[len];
    for(int i=0; i<len; i++) {
        A[i] = S[i]-'a';
    }
    long long k, odds, r, l, multi;
    for(int q=0; q<Q; q++) {
        cin>>l>>r;
        long long a[No_Char] = {0};
        for(int i=l-1; i<r; i++) {
            a[A[i]]++;
        }
        k=0;
        odds=0;
        multi=1;
        for(int i=0; i<No_Char; i++) {
            if(a[i]%2==0) k+=a[i]/2;
            else {
                k+=a[i]/2;
                odds++;
            }
        }
        if(odds==0) {
            odds=1;
        }
        // long long max=a[0], poi=0;
        // for(unsigned int i=0; i<No_Char; i++) {
        //     if(a[i]>max) {
        //         max=a[i];
        //         poi=i;
        //     }
        // }
        // a[poi]= 1;
        long long Ans=factorial(k, 1);
        // cout<<Ans<<" fact"<<endl;

        // cout<<Ans<<endl;
        // cout<<Ans<<endl;
        for(int i=0; i<No_Char; i++) {
            if(a[i]>3) {
                multi=((multi%MAX)*(factorial(a[i]/2, 1)%MAX))%MAX;
                // cout<<multi<<endl;
            }
        }
        // cout<<multi<<endl;
        multi = binary_exp(multi, MAX-2);
        // cout<<multi<<" multi e"<<endl;//<---------
        multi = (Ans%MAX)*(multi%MAX);
        // cout<<multi<<" multi A"<<endl;//<---------
        cout<<((multi%MAX)*(odds%MAX))%MAX<<endl;
    }
    return 0;
}
