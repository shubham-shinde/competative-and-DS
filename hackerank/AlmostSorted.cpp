#include <bits/stdc++.h>
#define ll long long;
#define FORI(s, n) for(auto i=s; i<=n; i++)

using namespace std;

void swapOrReverse(int* a, int n) {
    vector<int> dip;
    FORI(1, n-1) {
        if(a[i]<a[i-1]) {
            dip.push_back(i);
        }
    }
    
    switch (dip.size())
    {
        case 0: {
            cout<<"no"<<endl;
            break;
        }
        case 1: {
            int fp = dip[0]-2 < 0 ? 0 : a[dip[0]-2];
            int sn = dip[0]+1 < n ? a[dip[0]+1] : numeric_limits<int>::max();

            if(fp < a[dip[0]] && sn > a[dip[0]-1]) cout<<"yes"<<endl<<"swap"<<' '<<dip[0]<<' '<<dip[0]+1<<endl;

            else cout<<"no"<<endl;

            break;
        }
        case 2: {
            int fp,f,fn,sp,s,sn;
            int first = dip[0];
            int last = dip[1];
            fn = a[first];
            f = a[first-1];
            fp = first-2 < 0 ? 0 : a[first-2];
            s = a[last];
            sp = a[last-1];
            sn = last+1 < n ? a[last+1] : numeric_limits<int>::max();
            if(s>fp && s<fn && f>sp && f<sn) cout<<"yes"<<endl<<"swap"<<' '<<first<<' '<<last+1<<endl;
            else {
                cout<<"no"<<endl;
            }
            break;
        }
        default: {
            bool check=true;
            FORI(1, dip.size()-1) {
                if(dip[i]-1 != dip[i-1]) {
                    check = false;
                    break;
                }
            }
            if(check) {
                int fp,f,sn,s;
                int first = dip[0];
                int last = dip[dip.size()-1];
                f = a[first-1];
                fp = first-2 < 0 ? 0 : a[first-2];
                s = a[last];
                sn = last+1 < n ? a[last+1] : numeric_limits<int>::max();
                if(s>fp && f<sn) cout<<"yes"<<endl<<"reverse"<<' '<<first<<' '<<last+1<<endl;
                else {
                    cout<<"no"<<endl;
                }
            }
            else {
                cout<<"no"<<endl;
            }
            break;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    swapOrReverse(arr, n);
    return 0;
}