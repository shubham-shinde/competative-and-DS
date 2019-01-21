#include<bits/stdc++.h>
#define FORI(s,n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;
const int KK = 1000000;
// typedef long double double;
// typedef pair< double, list< double > > makePair;
int N, Q;
// map< double, list< double > > MapOfLists;

// void insertElement(double min, double max) {
//     list< double > A;
//     if(MapOfLists.find(min) == MapOfLists.end()) {
//         A.push_back(max);
//         MapOfLists.insert(makePair(min, A));
//     }
//     else {
//         A = MapOfLists.find(min)->second;
//         list< double >::iterator ptr;
//         for( ptr = A.begin(); ptr != A.end(); ptr++) {
//             if(*ptr > max)  {
//                 break;
//             }
//         }
//         A.insert(ptr, max);
//     }    
// }

// void printMap() {
//     map< double, list< double > >::iterator ptr;
//     for(ptr = MapOfLists.begin(); ptr != MapOfLists.end(); ptr++) {
//         list< double > A = ptr->second;
//         list< double >::iterator k;
//         cout<<ptr->first<<"  ";
//         for( k = A.begin(); k != A.end(); k++) {
//             cout<<*k<<"->";
//         }
//         cout<<endl;
//     }
// }

void CalMaxAndMin(double x, double y, double r, double x1, double y1, double r1, int query[]) {
    double d = sqrt(pow(x-x1,2) + pow(y-y1, 2));
    double sum = r+r1, dif = abs(r-r1);
    double min, max;
    if(d > sum) {
        min = d-sum;
        max = d+sum;
    }
    else if(d <= sum && d >= dif) {
        min = 0;
        max = d+sum;
    }
    else {
        min = dif - d;
        max = d + dif;
    }
    query[(int)ceil(min)]++;
    query[(int)floor(max)+1]--;
    // insertElement(min, max);
}

// long long queryMapOfList(double q) {
//     long long counter=0;
//     map< double, list< double > >::iterator ptr;
//     // for(ptr = MapOfLists.begin(); ptr != MapOfLists.end(); ptr++) {
//     //     // cout<<ptr->first;
//     //     if(ptr->first > q) break;
//     //     list< double > A = ptr->second;
//     //     list< double >::iterator k;
//     //     for(k = A.begin(); k!=A.end(); k++) {
//     //         if(*k >= q) counter++;
//     //     }
//     // }
//     return counter;    
// }

int main()
{
    cin>>N>>Q;
    double x,y,r;
    vector<double> X, Y, R;
    int query[KK] {0}; 
    for( int i=0; i<N; i++) {
        cin>>x>>y>>r;
        for(unsigned int i=0; i<X.size(); i++) {
            CalMaxAndMin(x,y,r, X[i], Y[i], R[i], query);
        }
        X.push_back(x);
        Y.push_back(y);
        R.push_back(r);
    }
    //prefix sum
    cout<<endl;
    FORI(1,KK) query[i] +=query[i-1];
    cout<<endl;
    // printMap();
    int q;
    for( int k=0; k<Q; k++) {
        cin>>q;
        // cout<<queryMapOfList(q)<<endl;
        cout<<query[q]<<endl;
    }
    return 0;
}
