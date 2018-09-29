#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

vector<string> split_string(string);

void Healthy(int n,vector<string> g, vector<int> h, int s, vector<int> start, vector<int> end, vector<string> d ) {
    // sort(g.begin(),g.end());
    int health[s];
    for(int i=0; i<s; i++) {
        int sum=0;
        for(int j=start[i]; j<=end[i]; j++) {
            int index, pos=0;
            while(pos != -1) {
                pos = d[i].find(g[j], pos);
                if(pos == -1) {
                    continue;
                }
                sum+=h[j];
                pos++;
            }
        }
        health[i]=sum;
    }
    int max=0;
    for(unsigned int i=0; i<s; i++) {
        if(health[i]>max) {
            max=health[i];
        }
    }
    int min=max;
    for(unsigned int i=0; i<s; i++) {
        if(health[i]<min) {
            min=health[i];
        }
    }
    cout<<endl;
    cout<<min<<" "<<max;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split_string(genes_temp_temp);

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split_string(health_temp_temp);

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max=0,min=0;

    for (int i = 0; i < s; i++) {
        string firstLastd_temp;
        getline(cin, firstLastd_temp);

        vector<string> firstLastd = split_string(firstLastd_temp);

        int first = stoi(firstLastd[0]);

        int last = stoi(firstLastd[1]);

        string d = firstLastd[2];

        int sum=0;
        for(int j=first; j<=last; j++) {
            int index, pos=0;
            while(pos != -1) {
                pos = d.find(genes[j], pos);
                if(pos == -1) {
                    continue;
                }
                sum+=health[j];
                pos++;
            }
        }
        if(sum>max) {
            max=sum;
        }
        if(i==0) {
            min=sum;
        }
        else if(sum<min) {
            min=sum;
        }
    }
    cout<<min<<" "<<max<<endl;
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