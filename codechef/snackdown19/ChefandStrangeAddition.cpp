#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// 111011100110101100101000000000

void decToBinary(int n) 
{ 
    int binaryNum[1000]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
}

ll coutbit(ll n) { 
    if (n == 0) 
        return 0;   
    else
        return (n & 1) + coutbit(n >> 1); 
} 
  

int main()
{
    ll T;
    cin>>T;
    ll A,B,C;
    ll counter;
    for( ll q=0; q<T; q++) {
    	cin>>A>>B;
        C=A+B;
        counter=0;
        ll C_Aa = coutbit(A);
        ll c_Bb = coutbit(B);
        bool flag = C_Aa==c_Bb;
        cout<<flag<<endl;
        decToBinary(A);
        cout<<" ";
        decToBinary(B);
        cout<<" ";
        cout<<C_Aa<<" "<<c_Bb<<endl;
        for(ll i=0; i<=(C/2); i++) {
            decToBinary(i);
            cout<<" "<<i<<endl;
            if(coutbit(i)==C_Aa || coutbit(C-i)==c_Bb || 
                coutbit(i)==c_Bb || coutbit(C-i)==C_Aa) {
                    cout<<"pass"<<endl;
                }
            if((coutbit(i)==C_Aa && coutbit(C-i)==c_Bb) || 
                (coutbit(i)==c_Bb && coutbit(C-i)==C_Aa)) {
                // cout<<i<<" "<<C-i<<"  "<<endl;
                // decToBinary(i);
                // cout<<" ";
                // decToBinary(C-i);
                // cout<<endl;
                if(flag && i != C-i) {
                    counter++;
                    // cout<<C-i<<"  "<<i<<" "<<"flag on"<<endl;
                    // decToBinary(C-i);
                    // cout<<" ";
                    // decToBinary(i);
                    // cout<<endl;
                }
                counter++;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}