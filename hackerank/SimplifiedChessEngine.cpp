#include <bits/stdc++.h>

using namespace std;
typedef pair< char, bool > makePair;
typedef pair< char, pair< int, int>> triplate;
const int SS = 4;

void printVector(vector<vector<char>> v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printVectorPair(vector<vector<makePair>> v) {
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            cout<<v[i][j].first<<','<<v[i][j].second<<" ";
        }
        cout<<endl;
    }
}

vector<string> split_string(string);

bool whiteTurn(vector<vector<makePair>> matrix, vector<triplate> white, vector<triplate> blacks,int w_index, int b_index, int w) {
    if(w == 0 || w_index>white.size()) {
        return 0;
    }
    char turnOf = white[w_index].first;
    int x = white[w_index].second.first,
        y = white[w_index].second.second;
    if(turnOf=='N') {
        if (x+2 < SS && y-1 < SS) {
            if(matrix[x+2][y-1].first == 'Q') return 1
            else if(matrix[x+2][y-1].first != '@' && matrix[x+2][y-1].second == 0) {
                
            }
        }

        if (x+2 < SS && y+1 < SS) {
            if(matrix[x+2][y+1].first == 'Q') return 1
            else if(matrix[x+2][y+1].first != '@' && matrix[x+2][y+1].second == 0) {
                
            }
        }

        if (x-2 < SS && y-1 < SS) {
            if(matrix[x-2][y-1].first == 'Q') return 1
            else if(matrix[x-2][y-1].first != '@' && matrix[x-2][y-1].second == 0) {
                
            }
        }

        if (x+2 < SS && y+1 < SS) {
            if(matrix[x+2][y+1].first == 'Q') return 1
            else if(matrix[x+2][y+1].first != '@' && matrix[x+2][y+1].second == 0) {
                
            }
        }

        if (x+1 < SS && y-2 < SS) {
            if(matrix[x+1][y-2].first == 'Q') return 1
            else if(matrix[x+1][y-2].first != '@' && matrix[x+1][y-2].second == 0) {
                
            }
        }

        if (x-1 < SS && y-2 < SS) {
            if(matrix[x-1][y-2].first == 'Q') return 1
            else if(matrix[x-1][y-2].first != '@' && matrix[x-1][y-2].second == 0) {
                
            }
        }

        if (x+1 < SS && y+2 < SS) {
            if(matrix[x+1][y+2].first == 'Q') return 1
            else if(matrix[x+1][y+2].first != '@' && matrix[x+1][y+2].second == 0) {
                
            }
        }

        if (x-1 < SS && y+2 < SS) {
            if(matrix[x-1][y+2].first == 'Q') return 1
            else if(matrix[x-1][y+2].first != '@' && matrix[x-1][y+2].second == 0) {
                
            }
        }

    }
}

string simplifiedChessEngine(vector<vector<char>> whites, vector<vector<char>> blacks, int moves) {
    // printVector(whites);
    // printVector(blacks);
    vector<vector<makePair>> board {{{'@', 0},{'@', 0},{'@', 0},{'@', 0}},
                                    {{'@', 0},{'@', 0},{'@', 0},{'@', 0}},
                                    {{'@', 0},{'@', 0},{'@', 0},{'@', 0}},
                                    {{'@', 0},{'@', 0},{'@', 0},{'@', 0}}};

    vector<triplate> white, black;
    for(int i=0; i<whites.size(); i++) {
        int x = whites[i][1]-65, y = whites[i][2]-49;
        triplate temp = { whites[i][0], { x, y} };
        white.push_back(temp);
        board[x][y].first = whites[i][0];
        board[x][y].second = 1;
    }
    for(int i=0; i<blacks.size(); i++) {
        int x = blacks[i][1]-65, y = blacks[i][2]-49;
        triplate temp = { blacks[i][0], { x, y} };
        black.push_back(temp);
        board[x][y].first = blacks[i][0];
    }
    printVectorPair(board);
    string s = whites[0][0]=='N' ? "YES": "NO";
    return s;
}

int main()
{
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string wbm_temp;
        getline(cin, wbm_temp);

        vector<string> wbm = split_string(wbm_temp);

        int w = stoi(wbm[0]);

        int b = stoi(wbm[1]);

        int m = stoi(wbm[2]);

        vector<vector<char>> whites(w);
        for (int whites_row_itr = 0; whites_row_itr < w; whites_row_itr++) {
            whites[whites_row_itr].resize(3);

            for (int whites_column_itr = 0; whites_column_itr < 3; whites_column_itr++) {
                cin >> whites[whites_row_itr][whites_column_itr];

                if (whites_column_itr != 3 - 1) {
                    cin.ignore(numeric_limits<streamsize>::max(), ' ');
                }
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<vector<char>> blacks(b);
        for (int blacks_row_itr = 0; blacks_row_itr < b; blacks_row_itr++) {
            blacks[blacks_row_itr].resize(3);

            for (int blacks_column_itr = 0; blacks_column_itr < 3; blacks_column_itr++) {
                cin >> blacks[blacks_row_itr][blacks_column_itr];

                if (blacks_column_itr != 3 - 1) {
                    cin.ignore(numeric_limits<streamsize>::max(), ' ');
                }
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = simplifiedChessEngine(whites, blacks, m);
        cout<<result<<endl;
    }

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
