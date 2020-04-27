#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//Do Binary search
ll binary_search(vector<ll> &list, ll num, ll s, ll e) {
  if( e <= s+1 ) return (list[s] <= num) ? list[s] : -1;
  ll M = ( s+e )/2;
  if(list[ M ] == num) return num;
  else if(list[ M ] > num) return binary_search(list, num, s, M);
  else return binary_search(list, num, M, e);
}

int main() {
//  vector<string> files = { "a", "b", "c", "d", "e" };
  vector<string> files = { "a" };
  for(auto file : files) {
    ifstream input_file("inputs/"+file+".txt");
    ofstream output_file("outputs/"+file+".txt");
    ll M, N;
    input_file>>M>>N;
    vector<ll> slices;

    //for(auto i=0; i<N; i++, input_file>>slice) slices.push_back(slice);
    vector<ll> pizzas;

    for(ll i=slices.size()-1; i>=0; i--) {
      ll rem = M-slices[i];
      ll minus = binary_search(slices, rem, 0, i);
      vector<ll> curr_pz = {i};
      while(minus != -1) {
        rem -= minus;
        //handle double occurance and used number


      }
    }

    output_file<<pizzas.size()<<"\n";
    for( auto pizza : pizzas ){
      output_file<<pizza<<' ';
    }
    input_file.close();
    output_file.close();
  }
  return 0;
}
