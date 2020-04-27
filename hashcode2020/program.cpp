#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<string> files = { "a", "b", "c", "d", "e" };
//  vector<string> files = { "a" }
  for(auto file :files) {
    ifstream input_file("inputs/"+file+".txt");
    ofstream output_file("outputs/"+file+".txt");
    int M, N;
    input_file>>M>>N;
    int k, n=0, sum = 0, type_of_pizza = 0;
    vector<int> pizzas;
    while(input_file>>k && sum+k<=M) {
      sum+=k;
      type_of_pizza++;
      pizzas.push_back(n++);
    }
    output_file<<type_of_pizza<<"\n";
    for( auto pizza : pizzas ){
      output_file<<pizza<<' ';
    }
    input_file.close();
    output_file.close();
  }
  return 0;
}
