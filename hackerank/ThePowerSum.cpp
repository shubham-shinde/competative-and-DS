#include <bits/stdc++.h>

using namespace std;

int counter=0;
int X;
int L;

// Complete the powerSum function below.
void combination(int a[],int sum, int start, int end,int index, int r) {
    if(index == r) {
        if(sum==X) {
            counter++;
        }
        // cout<<sum<<" ";
        return;
    }
    if(sum<X) 
        for(int i=start; i<=end && end-i+1 >= r-index; i++)
            combination(a, sum+a[i], i+1, end, index+1, r);
}

int powerSum(int N) {
    
    int count = pow(X, 1.0/N);
    L = count;
    int num[count];
    for( int i=1; i<=count; i++) {
        num[i-1] = pow(i, N);
        // cout<<num[i-1]<<" ";
    }
    // cout<<endl;
    for(int i=1; i<=count; i++)
        combination(num, 0, 0, count-1, 0, i);
    // cout<<endl;
    // cout<<counter;
    return counter;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    cin >> X;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = powerSum(N);

    fout << result << "\n";

    fout.close();

    return 0;
}
