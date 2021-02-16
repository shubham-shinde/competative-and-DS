//for finding sum of elements within range.
#include<bits/stdc++.h>
using namespace std;
#define FORI(s, n) for(int i=s; i<=n; i++)
typedef long long ll;

bool isPrime(int n)
{
	if (n <= 1) return false;

	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return false;

	return true;
}

