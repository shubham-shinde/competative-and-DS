#include <bits/stdc++.h>
using namespace std;


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string number;
    while(getline(ss, number, delim)) {
        elems.push_back(number);
    }
    return elems;
}