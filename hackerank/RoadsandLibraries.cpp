#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int DFS(vector<vector<int>> Adj,int V[],int vertex) {
    int n=Adj.size();
    int sum=1;
    V[vertex]=1;
    for(int i=0; i<n; i++) {
        if(V[i] != 1 && Adj[vertex][i] == 1) {
            sum+=DFS(Adj, V, i);
        }
    }
    return sum;
}

long roadsAndLibraries(intMa n, int c_lib, int c_road, vector<vector<int>> cities) {
    int n_roads = cities.size();
    if(c_lib < c_road) {
        return c_lib*n;
    }
    else {
        vector<vector<int>> Adj(n, vector<int>(n, 0));
        // for(int i=0; i<cities.size(); i++) {
        //     for(int j=0; j<cities[i].size(); j++) {
        //         cout<<cities[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(unsigned int i=0; i<cities.size(); i++) {
            int edge1 = cities[i][0]-1;
            int edge2 = cities[i][1]-1;
            Adj[edge1][edge2] = 1;
            Adj[edge2][edge1] = 1;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<Adj[i][j]<<" ";
            }
            cout<<endl;
        }
        int V[n] {0};
        int cost=0;
        for(int i=0; i<n; i++) {
            if(V[i] != 1) {
                int dfs = DFS(Adj, V, i)-1;
                cost+=c_road*dfs+c_lib;
                cout<<dfs;
            }
        }
        return cost;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
