#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll M;
ll dpLen = 1000001;


//Do Binary search
ll binary_search(vector<ll> &list, ll num, ll s, ll e) {
  if( e <= s+1 ) return (list[s] <= num) ? s : -1;
  ll Mid = ( s+e )/2;
  if(list[ Mid ] == num) return Mid;
  else if(list[ Mid ] > num) return binary_search(list, num, s, Mid);
  else return binary_search(list, num, Mid, e);
}

vector<vector<ll>> create_count_dp(vector<vector<ll>> c_slices) {
  vector<vector<ll>> dp(dpLen);
  dp[0] = {-1, 0};
  for(auto i :c_slices) {
    dp[i[0]] = {-1, i[1]};
  }
  ll curr = 0, index = 0;
  for(auto i : dp) {
    if(i.size() > 0 && i[0] == -1) {
      curr = index;
    }
    else dp[index].push_back(curr);
    index++;
  }
  return dp;
}

pair<ll, vector<ll>> test_for_max(ll num, vector<vector<ll>> dp) {
  ll sum = num;
  num = 0;
  dp[sum][1]--;
  vector<ll> selected_nums= { sum };
  while(sum+num<M) {
    sum += num;
    if(num != 0) selected_nums.push_back(num);
    ll rem = M - sum;
    ll node = dp[(rem < dp.size()) ? rem : dp.size()-1][0];
    if(node == 0) break;
    if(node == -1) {
      node = (rem < dp.size()) ? rem : dp.size()-1;
    }
    while(!(dp[node].size() > 1 && dp[node][1] > 0)) {
      ll index = node-1;
      node = dp[node-1][0];
      if(node == 0) break;
      if(node == -1) node = index;
    }
    if(node == 0) break;
    num = node;
    dp[node][1]--;
  }
  return {sum, selected_nums};
}

vector<vector<ll>> makeCount(vector<ll> slices) {
  vector<vector<ll>> c_slices;
  c_slices.push_back({slices[0], 0});
  for(auto i : slices) {
    ll lst_sz = c_slices.size()-1;
    if(c_slices[lst_sz][0] == i) c_slices[lst_sz][1] += 1;
    else c_slices.push_back({i, 1});
  }
  return c_slices;
}

vector<ll> create_search_vector(vector<vector<ll>> slices) {
  vector<ll> search_vector;
  for(auto i : slices) {
    search_vector.push_back(i[0]);
  }
  return search_vector;
}

ll find_correct_index(vector<vector<ll>> slices, ll index) {
  if(index < 0) return -1;
  for(ll i = index; i>=0; i--) {
    if(slices[i][1] > 0) {
      return i;
    }
  }
  return -1;
}

vector<ll> find_num_position(vector<vector<ll>> counted_slices, vector<ll> required) {
  unordered_map<ll, vector<ll>> positions;
  ll ind = 0;
  for(auto i: counted_slices) {
    for(ll j=0; j<i[1]; j++) {
      positions[i[0]].push_back(ind++);
    }
  }
  vector<ll> pos;
  for(auto i : required) {
    pos.push_back(positions[i][positions[i].size()-1]);
    positions[i].pop_back();
  }
  return pos;
}

pair<ll, vector<ll>> search_max(vector<vector<ll>> counted_slices, ll end) {
  ll curr = end, sum = 0;
  vector<ll> search_vector = create_search_vector(counted_slices);
  ll search_vector_sz = search_vector.size();
  vector<ll> pizzas_slices = { end };
  while(sum + curr < M && curr != 0) {
    sum += curr;
    ll index = binary_search(search_vector, M-sum, 0, search_vector_sz);
    index = find_correct_index(counted_slices, index);
    if(index == -1) break;
    counted_slices[index][1]--;
    curr = counted_slices[index][0];
    pizzas_slices.push_back(curr);
  }
  cout<<sum<<endl;
  return { sum, pizzas_slices};
}

vector<ll> CalculateMaximumUsingBinarySearch(ll Ms, ll N, vector<ll> slices) {
  M = Ms;
  vector<vector<ll>> c_slices = makeCount(slices);
  /* vector<vector<ll>> dp = create_count_dp(c_slices); */
  ll max = 0;
  vector<ll> pizzas_slices;
  ll sz = c_slices.size();
  for(ll i=sz-1; i>=sz/2; i--) {
    c_slices[i][1]--;
    cout<<"testing for "<<c_slices[i][0]<<endl;
    pair<ll, vector<ll>> sum_nd_vec = search_max(c_slices, c_slices[i][0]);
    if(sum_nd_vec.first > max) {
      max = sum_nd_vec.first;
      pizzas_slices = sum_nd_vec.second;
    }
    c_slices[i][1]++;
  }
  return find_num_position(c_slices, pizzas_slices);
}

vector<ll> CalculateMaximumUsingDynamicProgramming(ll Ms, ll N, vector<ll> slices) {
  M = Ms;
  vector<vector<ll>> c_slices = makeCount(slices);
  vector<vector<ll>> dp = create_count_dp(c_slices);
  ll max = 0;
  vector<ll> pizzas_slices;
  ll sz = c_slices.size();
  for(ll i=sz-1; i>=sz/2; i--) {
    cout<<"testing for "<<c_slices[i][0]<<endl;
    pair<ll, vector<ll>> sum_nd_vec = test_for_max(c_slices[i][0], dp);
    if(sum_nd_vec.first > max) {
      max = sum_nd_vec.first;
      pizzas_slices = sum_nd_vec.second;
      cout<<max<<endl;
    }
  }
  return find_num_position(c_slices, pizzas_slices);
}

int main() {
  /* vector<string> files = { "a", "b", "c", "d", "e" }; */
  vector<string> files = { "c" };
  for(auto file : files) {
    ifstream input_file("inputs/"+file+".txt");
    ofstream output_file("outputs/"+file+".txt");
    ll M, N, slice;
    input_file>>M>>N;
    vector<ll> slices;
    vector<ll> pizzas;
    input_file>>slice;

    for(ll i=0; i<N; i++, input_file>>slice) slices.push_back(slice);

    pizzas = CalculateMaximumUsingDynamicProgramming(M, N, slices);

    //for(auto i=0; i<N; i++, input_file>>slice) slices.push_back(slice);

    output_file<<pizzas.size()<<"\n";
    for( auto pizza : pizzas ){
      output_file<<pizza<<' ';
    }
    input_file.close();
    output_file.close();
  }
  return 0;
}
