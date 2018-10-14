#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
// typedef long double double;
vector<double> MIN, MAX;
int N, Q;

void CalMaxAndMin(double x, double y, double r, double x1, double y1, double r1) {
    double d = sqrt(pow(x-x1,2) + pow(y-y1, 2));
    double sum = r+r1, dif = abs(r-r1);
    double min, max;
    if(d > sum) {
        min = d-sum;
        max = d+sum;
    }
    else if(d <= sum && d > dif) {
        min = 0;
        max = d+sum;
    }
    else if(d <= dif) {
        min = dif - d;
        max = d + dif;
    }
    MIN.push_back(min);
    MAX.push_back(max);
}

long long queryMapOfList(double q) {
    long long count=0;
    for(unsigned int i=0; i<MIN.size(); i++) {
        if(q > MIN[i] && q < MAX[i]) {
            count++;
        }
    }
    return count;    
}

int main()
{
    cin>>N>>Q;
    double x,y,r;
    vector<double> X, Y, R;
    for( int i=0; i<N; i++) {
        cin>>x>>y>>r;
        int b=0;
        for(unsigned int i=0; i<X.size(); i++) {
            if(X[i]==x && Y[i]==y && R[i]==r) {
                b=1;
                break;
            }
        }
        if(b==1) continue;
        for(unsigned int i=0; i<X.size(); i++) {
            CalMaxAndMin(x,y,r, X[i], Y[i], R[i]);
        }
        X.push_back(x);
        Y.push_back(y);
        R.push_back(r);
    }       
    cout<<"From here"<<endl;
    for(unsigned int i=0; i<MIN.size(); i++) {
        cout<<MIN[i]<<" "<<MAX[i]<<endl;
    } 
    cout<<"endl"<<endl;
    double q;
    for( int k=0; k<Q; k++) {
        cin>>q;
        cout<<queryMapOfList(q)<<endl;
    }
    return 0;
}
