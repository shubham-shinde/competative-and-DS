#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
// typedef long double double;
typedef pair< const double, list< double > > makePair;
int N, Q;
map< const double, list< double > > MapOfLists = {
    {1 , { 2, 4 , 5}},
    {3 , { 5, 6 ,10}},
    {5.5 , { 6.4, 6.3, 10.10 }}
};

void printMap() {
    map< double, list< double > >::iterator ptr;
    for(ptr = MapOfLists.begin(); ptr != MapOfLists.end(); ptr++) {
        list< double > A = ptr->second;
        list< double >::iterator k;
        cout<<ptr->first<<"  ";
        for( k = A.begin(); k != A.end(); k++) {
            cout<<*k<<"->";
        }
        cout<<endl;
    }
}

int main()
{
    // cin>>N>>Q;
    printMap();
    return 0;
}
