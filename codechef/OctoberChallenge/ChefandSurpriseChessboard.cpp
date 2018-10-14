#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<string> A;
vector<vector<int>> Falsy;
vector<vector<int>> Wrong;
int N, M, Max=1;

void findMaxSubBoard() {
    for(int i = 1; i < N; i++) 
    { 
        for(int j = 1; j < M; j++) 
        { 
            if(Falsy[i][j] > 0)  {
                Falsy[i][j] = min(Falsy[i][j-1], Falsy[i-1][j], Falsy[i-1][j-1]) + 1; 
                if (Falsy[i][j]>Max) Max = Falsy[i][j];
            }
            else Falsy[i][j] = 0; 
        }  
    } 
}

void reverseFalsy() {
    for(int i = 1; i < N; i++) 
    { 
        for(int j = 1; j < M; j++) 
        { 
        Falsy[i][j] = Falsy[i][j] == 0 ? 1 : 0;
        }  
    } 
}

int main()
{
    cin>>N>>M;
    A.resize(N);
    for( int i=0; i<N; i++) {
        string s;
    	cin>>s;
        A[i] = s;
    }
    vector<vector<int>> W, R;
    int counter=0;
    Falsy.resize(N);
    for( int i=0; i<N; i++) {
        Falsy[i].resize(M);
        for( int j=0; j<M; j++) {
            // cout<<A[i][j]<<" ";
            if((i+j)%2==0 && A[i][j] != '1') {
                vector<int> arr {i, j};
                W.push_back(arr);
                Falsy[i][j] = 0;
                // cout<<i<<j<<endl;
            }
            else if((i+j)%2!=0 && A[i][j] == '1') {
                vector<int> arr {i, j};
                W.push_back(arr);
                Falsy[i][j] = 0;
                // cout<<i<<j<<endl;
            }
            else {
                vector<int> arr {i, j};
                R.push_back(arr);
                counter++;
                Falsy[i][j] = 1;
            }
        }
        if(counter<(M*N)/2) {
            Wrong = W;
        }
        else {
            Wrong = R;
            reverseFalsy();
        }
        findMaxSubBoard();
        ll Q, query;
        cin>>Q;
        // ll query[Q];
        for(ll i=0; i<Q; i++) {
            // cin>>query[i];
            if(query >= Wrong.size()) cout<<min(N, M);
            else if(query == 0) cout<<Max<<endl;
            else {
                int n = min(N, M), m=min(N, M), sol=Max;
                while(n>Max) {
                    for(int i=0; i<max(N, M)-m; i++) 
                }
            }
        }
        cout<<endl;
    }
    // cout<<"Wrong"<<endl;
    // for( unsigned int i=0; i<Wrong.size(); i++) {
    //     cout<<Wrong[i][0]<<" "<<Wrong[i][1]<<endl;
    // }
    return 0;
}
