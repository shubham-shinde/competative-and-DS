#define MAX 1000001
#include<bits/stdc++.h>
#include<iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef long long ll;
bool prime[1000001];

inline long long int sscan()
{
	long long int n=0;
	int ch=gc();
	while( ch < '0' || ch > '9' )
		ch=gc();
	while(  ch >= '0' && ch <= '9' )
	{
		n = (n<<3)+(n<<1) + ch-'0';
		ch=gc();
	}

	return n;
}

inline void lprint(long int a)
{                                       /**for print long int**/
	int i=0;
	char S[20];
	while(a>0)
	{
		S[i++]=a%10+'0';
		a=a/10;
	}
	--i;
	while(i>=0)
		pc(S[i--]);
	pc('\n');
}

int main() {
	int tt = sscan();
	int x, y;
	ll n = 1000000;
	memset(prime, true, 1000001);
	for (int p = 2; p * p <= n; p++)
		if (prime[p] == true)
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
	ll sz = 78498;
	ll primes[sz];
	ll nnn = 0;
	for (int p = 2; p <= n; p++) {
		if (prime[p]) {
			primes[nnn] = p;
			nnn++;
		}
	}

	while(tt--) {
		x = sscan();
		y = sscan();
		if(y > sz || prime[y] > x) {
			/* g_fo.PrintChar('C'); */
			/* g_fo.PrintChar('h'); */
			/* g_fo.PrintChar('e'); */
			/* g_fo.PrintChar('f'); */
			cout<<"Chef";
		} else {
			/* g_fo.PrintChar('D'); */
			/* g_fo.PrintChar('i'); */
			/* g_fo.PrintChar('v'); */
			/* g_fo.PrintChar('y'); */
			/* g_fo.PrintChar('a'); */
			/* g_fo.PrintChar('m'); */
			cout<<"Divyam";
		}
		cout<<endl;
	}
	return 0;
}
