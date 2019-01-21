#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
vector<vector<long>> dp;

// Complete the getWays function below.
long getWays(long n, vector<long> c) {
    long len = c.size();
    if(dp[n][len] > -1) return dp[n][len];
    if(n == 0) return 1;

    else if(len==0) return 0;

    long ele = c[len-1];
    c.pop_back();
    long ite = 0;
    long sol = 0;

    while(ite <= n) {
        sol += getWays(n-ite, c);
        ite += ele;
    }
    dp[n][len] = sol;
    return sol;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<long> c(m);

    for (int i = 0; i < m; i++) {
        long c_item = stol(c_temp[i]);

        c[i] = c_item;
    }

    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'

    dp.resize(n+1, vector<long> (c.size() + 1, -1));

    long ways = getWays(n, c);

    dp.clear();

    cout<<ways<<endl;

    // fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
