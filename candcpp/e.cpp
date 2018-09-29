#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    stringstream geek(s);
    int x=0;
    geek>>x;
    if(s[8]=='P') {
        x!=12 ? x+=12 : x=12;
    }
    else if (s[8]=='A' && x==12) {
        x=00;
    }
    string p = to_string(x);
    if(x<10) {
        s.replace(0,1,"0");
        s.replace(1,1,p);
    }
    else {
        s.replace(0,2,p);
    }
    // return s.substr(0,8);
    cout << s.substr(0,8)<<endl;
}
