#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long CC = 0;

void printList(vector<long> s) {
    for(unsigned int i=0; i<s.size(); i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

long divide(long n, vector<long> s,long count, unordered_map<long, long> Map) {
    // cout<<count<<endl;
    if(CC>200000) return 0;
    CC++;
    long counter=0;
    long max=0, M;
    for(auto i=s.end(); i!=s.begin(); i--) {
        // cout<<"i "<<*i<<endl;
        if(n%(*i)==0 && n>(*i)) {
            long temp = *i;
            counter++;
            s.erase(i);
            // printList(s);
            M=divide(temp, s, count*n/temp, Map);
            cout<<"temp="<<temp<<endl;
            cout<<M<<endl;
            if(M>max) max=M;
            s.insert(i, temp);
        }
    }
    cout<<endl;
    // cout<<max+count<<endl;
    if(counter==0) return 0;
    return max+count;
}

long stoneDivision(long n, vector<long> s) {
    sort(s.begin(), s.end());
    unordered_map<long, long> M;
    long ans = divide(n, s, 1, M);
    cout<<ans<<endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        CC=0;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        long n = stol(nm[0]);

        int m = stoi(nm[1]);

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split_string(s_temp_temp);

        vector<long> s(m);

        for (int i = 0; i < m; i++) {
            long s_item = stol(s_temp[i]);

            s[i] = s_item;
        }

        long result = stoneDivision(n, s);

        fout << result << "\n";
    }

    fout.close();

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
