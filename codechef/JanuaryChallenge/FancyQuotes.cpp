//for finding sum of elements within range.
#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

int main() {
    int T; 
    string t;
    getline(cin, t);
    stringstream geek(t); 
    geek>>T;
    while(T--) {
        string s;
        getline(cin, s);
        int a = s.find(" not ");
        if(a >= 0) {
            cout<<"Real Fancy"<<endl;
            continue;
        }
        int len = s.length();
        a = s.find("not");
        if(a==0 && len == 3) {
            cout<<"Real Fancy"<<endl;
            continue;
        }
        if(a == 0 && s[3]==' ') {
            cout<<"Real Fancy"<<endl;
            continue;
        }
        if(a == len-3 && s[len-4]==' ') {
            cout<<"Real Fancy"<<endl;
            continue;
        }
        cout<<"regularly fancy"<<endl;
    }
    return 0;
}