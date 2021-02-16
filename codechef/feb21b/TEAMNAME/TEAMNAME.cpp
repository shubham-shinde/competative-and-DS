#include<bits/stdc++.h>
using namespace std;
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define ld long double
typedef long long ll;
#define MOD 1000000007LL

#define FORI(s, n) for(auto i=s; i<n; i++)

static struct IO {
	char tmp[1 << 10];

	// fast input routines
	char cur;

	//#define nextChar() (cur = getc_unlocked(stdin))
	//#define peekChar() (cur)
	inline char nextChar() { return cur = getc_unlocked(stdin); }
	inline char peekChar() { return cur; }

	inline operator bool() { return peekChar(); }
	inline static bool isBlank(char c) { return (c < '-' && c); }
	inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

	inline IO& operator >> (char & c) { c = nextChar(); return *this; }

	inline IO& operator >> (char * buf) {
		if (skipBlanks()) {
			if (peekChar()) {
				*(buf++) = peekChar();
				while (!isBlank(nextChar())) *(buf++) = peekChar();
			} *(buf++) = 0; } return *this; }

	inline IO& operator >> (string & s) {
		if (skipBlanks()) {	s.clear(); s += peekChar();
			while (!isBlank(nextChar())) s += peekChar(); }
		return *this; }

	inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
			n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

	defineInFor(int)
		defineInFor(unsigned int)
		defineInFor(long long)

		// fast output routines

		//#define putChar(c) putc_unlocked((c), stdout)
		inline void putChar(char c) { putc_unlocked(c, stdout); }
	inline IO& operator << (char c) { putChar(c); return *this; }
	inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

	inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

	char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
	inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
			*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

	defineOutFor(int)
		defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

vector<ll> gv;

int main()  {
	ll TT; cin>>TT;
	while(TT--) {
		ll n; cin>>n;
		unordered_map<string, ll> ma;
		vector<string> vc;
		string ss, n1, n2;
		char c;
		while(n--) {
			cin>>ss;
			ma[ss] = 1;
			vc.push_back(ss);
		}
		ll ans = 0;
		for(ll i=0; i<vc.size()-1; i++) {
			c = vc[i][0];
			for(ll j=i+1; j<vc.size(); j++) {
				n1 = vc[i];
				n2 = vc[j];
				n1[0] = n2[0];
				n2[0] = c;
				if(ma.find(n1) == ma.end() && ma.find(n2) == ma.end()) ans+=2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}