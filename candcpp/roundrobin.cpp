#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

void printArray(unsigned short arr[], int size) {
    for ( int i = 0; i < size; i++ ) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int remainingProcess( int *array, int n, int p) {
    for( int i=(p+1)%n; i!=p; i=(i+1)%n ) {
        if(array[i] > 0) {
            return i;
        }
    }
    if(array[p] > 0) {
        return p;
    }
    return -1;
};

float roundRobinAvgWt(unsigned short *arrival, unsigned short *run, int n, int q) {
    int time = 0, workingProcess = 0, i;
    float sum=0;
    int *wt = new int[n], *runTime = new int[n];
    for(i=0; i<n; i++) {
        runTime[i] = run[i];
    }
    while(workingProcess >= 0) {
        if(arrival[workingProcess] > time) {
            if(runTime[workingProcess-1] > 0) {
                workingProcess--;
            }
            else {
                time++;
            }
        }
        else if(runTime[workingProcess] <= q) {
            time += runTime[workingProcess];
            runTime[workingProcess] =0;
            wt[workingProcess] = time-arrival[workingProcess]-run[workingProcess];
            workingProcess = remainingProcess(runTime, n, workingProcess);
        }
        else {
            time  += q;
            runTime[workingProcess] -= q;
            workingProcess = remainingProcess(runTime, n, workingProcess);
        }
    }

    for(i=0; i<n; i++) {
        sum += wt[i];
    }
    return sum/n;
}

int main() {
    float AvgWt;
    int totalP = 10;
    unsigned short *arrival = new unsigned short[totalP] {0, 2, 5, 7, 7, 7, 7, 8, 9, 9}, *run= new unsigned short[totalP] {3000, 5, 8, 3, 156, 4 ,6 ,3, 6 ,7};
    auto start = high_resolution_clock::now();
    AvgWt = roundRobinAvgWt(arrival, run, 2, 1);
    auto stop = high_resolution_clock::now();
    cout<<AvgWt<<endl;
    printArray(run, totalP);
    auto duration = duration_cast<microseconds>(stop-start);
    cout <<"\nTime taken:: "<< duration.count()<<"\n"; 
    return 0;
}
