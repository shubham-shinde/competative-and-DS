#include<bits/stdc++.h>
using namespace std;
//give n-1
#define FORI(s, n) for(int i=s; i<=n; i++)
#define FORJ(s, n) for(int j=s; j<=n; j++)
//form s to n
#define FORIMINUS(s, n) for(int i=s; i>=n; i--)
#define FORJMINUS(s, n) for(int i=s; i>=n; i--)
typedef long long ll;
vector<vector<string>> global;

const int SIZE = 4;
vector<string> returnMatrix;

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string number;
    while(getline(ss, number, delim)) {
        elems.push_back(number);
    }
    return elems;
}

void printMatrix(vector<string>& matrix) { 
    for (int i = 0; i < SIZE; i++) 
        cout << matrix[i] << endl; 
    cout<<endl;
} 
  
vector<string> checkHorizontal(int x, int y, vector<string> matrix, string currentword) {
    for(int i=0; i<4; i++) {
        if(matrix[x][y+i] == '0' || matrix[x][y+i] == currentword[i]) 
            matrix[x][y+i] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

vector<string> checkHorizontalReverse(int x, int y, vector<string> matrix, string currentword) {
    for(int i=3; i>=0; i--) {
        // cout<<x<<" "<<y-i<<" "<<i<<endl;
        if(matrix[x][y-i] == '0' || matrix[x][y-i] == currentword[i]) 
            matrix[x][y-i] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

vector<string> checkVertical(int x, int y, vector<string> matrix, string currentword) {
    for(int i=0; i<4; i++) {
        if(matrix[x+i][y] == '0' || matrix[x+i][y] == currentword[i]) 
            matrix[x+i][y] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

vector<string> checkVerticalReverse(int x, int y, vector<string> matrix, string currentword) {
    for(int i=3; i>=0; i--) {
        if(matrix[x-i][y] == '0' || matrix[x-i][y] == currentword[i]) 
            matrix[x-i][y] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

void recuresAndFind(vector<string> crossword, vector<string> words,int index) {
    // cout<<index<<endl;
    // if(counter > 50) return;
    // counter++;
    if(index<words.size()) {
        string currentWord = words[index];
        //vertical check
        for(int i=0; i<4; i++) {
            vector<string> temp = checkVertical(0, i, crossword, currentWord);
            if(temp[0][0] != '@') {
                recuresAndFind(temp, words, index+1);
            }
        }

        for(int i=0; i<4; i++) {
            vector<string> temp = checkVerticalReverse(3, i, crossword, currentWord);
            if(temp[0][0] != '@') {
                recuresAndFind(temp, words, index+1);
            }
        }

        //horizontal check
        for(int i=0; i<SIZE; i++) {
            vector<string> temp = checkHorizontal(i, 0, crossword, currentWord);
            if(temp[0][0] != '@') {
                recuresAndFind(temp, words, index+1);
            }
        }

        for(int i=0; i<SIZE; i++) {
            vector<string> temp = checkHorizontalReverse(i, 3, crossword, currentWord);
            if(temp[0][0] != '@') {
                recuresAndFind(temp, words, index+1);
            }
        }
    }
    else {
        FORI(0, 3) {
            FORJ(0, 3) {
                if(crossword[i][j]=='0') {
                    return;
                }
            }
        }
        global.push_back(crossword);
        return;
    }
}

// Complete the crosswordPuzzle function below.
void buildGrid(vector<string> word) {
    vector<string> Words = { "0000", "0000", "0000", "0000" };
    recuresAndFind(Words, word, 0);
    return;
}

int main()
{
    ll T;
    cin>>T;
    while(T--) {
        global.clear();
        int N;
        cin>>N;
        vector<string> word;
        FORI(0, N-1) {
            string crossword_item;
            cin>>crossword_item;
            word.push_back(crossword_item);
        }
        buildGrid(word);
        if(global.size()==0) {
            cout<<"grid"<<endl<<"snot"<<endl<<"poss"<<endl<<"ible"<<endl<<endl;
            continue;
        }
        vector<string> AAAA;
        for(int i=0; i<global.size(); i++) {
            string d;
            FORJ(0, 3) {
                d=d+global[i][j];
            }
            AAAA.push_back(d);
            // cout<<d<<endl;
        }
        sort(AAAA.begin(), AAAA.end());
        // FORI
        int t=0;
        FORI(0,3) {
            FORJ(0,3) {

                cout<<AAAA[0][t++];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
