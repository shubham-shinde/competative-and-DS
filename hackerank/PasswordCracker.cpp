#include <bits/stdc++.h>

using namespace std;

string ans = "WRONG PASSWORD";
int temt = 0;

void printArr( vector <string> pass, int r) {
    for(int i=0; i<r; i++) {
        cout<<pass[i]<<" ";
    }
    cout<<endl;
}

void join(const vector<string>& v, char c, string& s, int r) {

   s.clear();

   for (int i=0; i<r; i++) {
      s += v[i];
      if (i != r-1)
        s += c;
   }
}


void crack(vector <string> pass, string attempt, string word, vector<string> fucked) {
    // cout<<word<<endl;
    if(temt> 2000) return;
    // printArr(fucked, fucked.size());
    if(attempt.length() == word.length()) {
        string ss;
        join(fucked, ' ', ss, fucked.size());
        ans = ss;
        return;
    }
    int size = pass.size();
    for(int i=0; i<size; i++) {
        temt++;
        int correct = 1;
        for(int j=0; j<pass[i].length(); j++) {
            if(pass[i][j] != attempt[word.length()+j]) {
                correct=0;
                break;
            }
        }
        if(correct == 1 && word.length() + pass[i].length() <= attempt.length()) {
            fucked.push_back(pass[i]);
            crack(pass, attempt, word+pass[i], fucked);
            fucked.pop_back();
        }
    }
}

string passwordCracker(vector <string> pass, string attempt) {
    string s;
    vector <string> fucked;
    crack(pass, attempt, s, fucked);
    return ans;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        temt = 0;
        ans = "WRONG PASSWORD";
        cin >> n;
        vector<string> pass(n);
        for(int pass_i = 0; pass_i < n; pass_i++){
        	cin >> pass[pass_i];
        }
        string attempt;
        cin >> attempt;
        string result = passwordCracker(pass, attempt);
        cout << result << endl;
    }
    return 0;
}

