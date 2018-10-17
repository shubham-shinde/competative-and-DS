#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10;
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
} 
  
vector<string> checkHorizontal(int x, int y, vector<string> matrix, string currentword) {
    int n = currentword.length();
    for(int i=0; i<n; i++) {
        if(matrix[x][y+i] == '-' || matrix[x][y+i] == currentword[i]) 
            matrix[x][y+i] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

vector<string> checkVertical(int x, int y, vector<string> matrix, string currentword) {
    int n = currentword.length();
    for(int i=0; i<n; i++) {
        if(matrix[x+i][y] == '-' || matrix[x+i][y] == currentword[i]) 
            matrix[x+i][y] = currentword[i];
        else {
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}

void recuresAndFind(vector<string> crossword, vector<string> words,int index) {
    if(index<words.size()) {
        string currentWord = words[index];
        int maxLen = SIZE - currentWord.size();
        //vertical check
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<=maxLen; j++) {
                vector<string> temp = checkVertical(j, i, crossword, currentWord);
                if(temp[0][0] != '@') {
                    // printMatrix(temp);
                    recuresAndFind(temp, words, index+1);
                }
            }
        }

        //horizontal check
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<=maxLen; j++) {
                vector<string> temp = checkHorizontal(i, j, crossword, currentWord);
                if(temp[0][0] != '@') {
                    // printMatrix(temp);
                    recuresAndFind(temp, words, index+1);
                }
            }
        }
    }
    else {
        printMatrix(crossword);
        return;
    }
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(vector<string> crossword, string words) {
    vector<string> Words = split(words, ';');
    recuresAndFind(crossword, Words, 0);
    return returnMatrix;
}

int main()
{
    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    crosswordPuzzle(crossword, words);

    return 0;
}
