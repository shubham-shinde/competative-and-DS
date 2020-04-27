#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(auto i=s; i!=n; i++)
typedef long long ll;

int* create_possibilites(int* arr, int len) {
	sort(arr, arr+len);
	int arrret[(len+1)/2], lent=(len+1)/2;
	int j=0;
	for(int i=0; i<len; i++) {
		if(i%2==0) arrret[j++] = arr[i];
	}
	return arrret;
}

int main()  {
		int matrix[] = {4, 2, 5, 3, 7}, n=5;
		create_possibilites(matrix, n);
	return 0;
}
