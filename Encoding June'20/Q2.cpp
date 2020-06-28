// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Do not continue reading if you dont want to die..............XD
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// When I wrote this, only God and I understood what I was doing
// Now, God only knows

// Aditya Sharma ------------------------------ IIIT-Allahabad 2017-2021


#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define int long long int
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define pll pair<long long, long long>
// #define mod 1000000007
#define inf 1000000000000000001
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define ff first
#define ss second
#define el endl
#define MAX 100005
#define wl while
#define all(v) v.begin(),v.end()
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep_1(i,n) for (int i = 1; i <= n; i++)
#define rep_it(it,mp) for(auto it=mp.begin();it!=mp.end();it++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
using namespace std;


// -----------------UNION/FIND-----------------------

vector< int >point;
vector< set<int> >connected;

void pre(int n)
{
	point.resize(n + 1);
	connected.resize(n + 1);
	for (int i = 1; i <= n; i++) point[i] = i;
	for (int i = 1; i <= n; i++) connected[i].insert(i);
}

void merge(int x, int y)
{
	for (auto node : connected[y])
	{
		point[node] = x;
	}
	connected[x].insert(connected[y].begin(), connected[y].end());
	connected[y].clear();
}

bool same(int x, int y)
{
	return point[x] == point[y];
}

void add(int x, int y)
{
	if (same(x, y)) return;
	if (connected[point[x]].size() <= connected[point[y]].size())
	{
		merge(point[y], point[x]);
	}
	else
	{
		merge(point[x], point[y]);
	}
}

// -----------------UNION/FIND END-----------------------

// -----------------PRIMESIEVE-------------------------
vector<bool>isprime(100000001, 1);
void pre()
{
	for (int i = 2; i < 100000001; i++)
	{
		if (isprime[i])
		{
			if (i < 10001)
			{
				for (int j = i * i; j < 100000001; j += i)
					isprime[j] = 0;
			}
		}
	}
}

// ----------------PRIMESIEVE-END--------------------


// --------------------SEGMENT TREE-------------------
vector<long long>tree(2 * (1e5 + 1));

void build(long long n)
{
	for (long long i = n - 1; i > 0; --i)
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

void modify(long long pos, long long val, long long n)
{
	pos += n;
	for (tree[pos] = val; pos > 1; pos >>= 1)
	{
		tree[pos >> 1] = (tree[pos] + tree[pos ^ 1]);
	}
}

long long sum(long long l, long long r, long long n)
{
	long long ans = 0;
	for (l += n, r = r + n + 1; l < r ; l >>= 1, r >>= 1)
	{
		if (l & 1) ans += tree[l++];
		if (r & 1) ans += tree[--r];
	}
	return ans;
}

// --------------------SEGMENT TREE END-------------------

// ---------------------nCr-------------------------------
int printNcR(int n, int r) {
	int p = 1, k = 1;
	if (n - r < r) {
		r = n - r;
	}

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			long long m = __gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}

	else {
		p = 1;
	}

	return p;
}

// ----------------------END nCr--------------------------------


// --------------------GENERAL FUNCTIONS------------------

int gcd(int a, int b) {
	if (a == 0) {return b;} return gcd(b % a, a);
}
void printVect(vector<int>v) {
	for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}
	cout << endl;
}
void printMap(map<int, int>mp) {
	for (auto it = mp.begin(); it != mp.end(); it++) {
		cout << it->ff << " -> " << it->ss;
	} cout << endl;
}
int modpow(int a, int b, int c) {
	int ans = 1;
	while (b != 0) {
		if (b % 2 == 1) {
			ans = (ans * a) % c;
		}
		a = (a * a) % c;
		b /= 2;
	}
	return ans;
}

// --------------------GENERAL FUNCTIONS END------------------

//This code sucks, you know it and I know it.
//Move on and call me an idiot later.

void findFactors(int x, set<int>&st) {
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (x / i == i) {
				st.insert(i);
				st.insert(-1 * i);
			}
			else {
				st.insert(i);
				st.insert(x / i);
				st.insert(-1 * i);
				st.insert(-1 * x / i);
			}
		}
	}
}
int findMod(double a, double b)
{
	double mod;
	// Handling negative values
	if (a < 0)
		mod = -a;
	else
		mod = a;
	if (b < 0)
		b = -b;

	// Finding mod by repeated subtraction

	while (mod >= b)
		mod = mod - b;

	// Sign of result typically depends
	// on sign of a.
	if (a < 0)
		return -mod;

	return mod;
}

signed main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	wl(t--) {
    int cnt=0;
		double p, q, r;
		double a, b, c;
		cin >> p >> q >> r;
		cin >> a >> b >> c;
		// cout << "p-> " << p << " q-> " << q << " r-> " << r << el;
		// cout << "a-> " << a << " b-> " << b << " c-> " << c << el;
		int id;
		bool f = false;
		for (int i = 0; i < 4; i++) {
			// break condition
			if (f == true) {
				break;
			}
			// if answer is 0
			if (i % 4 == 0) {
				if (a == p && q == b && c == r) {
					id = i % 4;
					f = true;
					// break;
				}
			}
			// if answer is 1
			if (i % 4 == 1) {
				// addition case "+"
				double d1, d2, d3;
				d1 = a - p;
				d2 = b - q;
				d3 = c - r;
				if (d1 == d2 && d2 == d3) {
					id = i % 4;
					f = true;
          cnt++;
					// break;
				}
				if ((d1 != 0 && d2 == 0 && d3 ==  0) || (d3 != 0 && d2 == 0 && d1 ==  0) || (d2 != 0 && d1 == 0 && d3 ==  0)) {
					id = i % 4;
					f = true;
          cnt++;
					// break;
				}
				if ((d1 == d2 && d3 == 0) || (d1 == d3 && d2 == 0) || (d3 == d2 && d1 == 0)) {
					id = i % 4;
					f = true;
					// break;
				}
				// multiplication case
				if (p != 0 && q != 0 && r != 0) {
					double r1, r2, r3;
					r1 = a / p ;
					r2 = b / q ;
					r3 = c / r ;
					// cout << r1 << " " << r2 << " " << r3 << " " << el;
					if (r1 == r2 && r2 == r3 && ceil(r1) == floor(r1) && ceil(r2) == floor(r2) && ceil(r3) == floor(r3) ) {
						id = i % 4;
						f = true;
						// break;
					}
					if (r1 == r2 && r3 == 1 && ceil(r1) == floor(r1) ) {
						id = i % 4;
						f = true;
						// break;
					}
					if (r2 == r3 && r1 == 1 && ceil(r2) == floor(r2)) {
						id = i % 4;
						f = true;
						// break;
					}
					if (r1 == r3 && r2 == 1 && ceil(r1) == floor(r1)) {
						id = i % 4;
						f = true;
						// break;
					}
				}
				if (p == 0 && r != 0 && q != 0) {
					double r1, r2;
					r1 = c / r;
					r2 = b / q;
					if (r1 == r2 && ceil(r1) == floor(r1)) {
						id = i;
						f = true;
					}
				}
				if (q == 0 && p != 0 && r != 0) {
					double r1, r2;
					r1 = a / p;
					r2 = c / r;
					if (r1 == r2 && ceil(r1) == floor(r1)) {
						id = i;
						f = true;
					}
				}
				if (r == 0 && p != 0 && q != 0) {
					double r1, r2;
					r1 = a / p;
					r2 = b / q;
					if (r1 == r2 && ceil(r1) == floor(r1)) {
						id = i;
						f = true;
					}
				}
			}
			// if answer is 2
			if (i % 4 == 2) {
				// case 1 : "++")
				double d1, d2, d3;
				d1 = a - p;
				d2 = b - q;
				d3 = c - r;
				// cout << d1 << " " << d2 << " " << d3 << el;
				if (d1 == d2 || d2 == d3 || d3 == d1) {
					id = i % 4;
					f = true;
          cnt++;
					// break;
				}
				if (d1 + d2 == d3 || d2 + d3 == d1 || d3 + d1 == d2) {
					id = i % 4;
					f = true;
          cnt++;
					// break;
				}
				if ((d1 == 0 && d2 != 0 && d3 != 0) || (d2 == 0 && d1 != 0 && d3 != 0) || (d3 == 0 && d2 != 0 && d1 != 0)) {
					id = i % 4; f = true;
					// break;
          cnt++;
				}

				// case 2 : "**"
				if (p != 0 && r != 0 && q != 0) {
					if (findMod(a, p) == 0 && findMod(b, q) == 0 && findMod(c, r) == 0) {
						double r1, r2, r3;
						r1 = a / p ;
						r2 = b / q ;
						r3 = c / r ;
						// cout << r1 << " " << r2 << " " << r3 << el;
						if (r1 == r2 || r2 == r3 || r3 == r1) {
							id = i % 4;
							f = true;
							// break;
						}
						if (r1 * r2 == r3 || r2 * r3 == r1 || r3 * r1 == r2) {
							id = i % 4;
							f = true;
							// break;
						}
					}
				}

				// case 3 : "+*"
				int x, y;
				// subcase->1
				// (a,b)
				if (a - b != 0) {
					x = (b * p - a * q) / (a - b);
				}
				if (p + x != 0) {
					y = a / (p + x);
				}
				if (p + x != 0 && a - b != 0) {
					// cout << x << " " << y << el;
					if ((r + x == c || r * y == c || (r + x)*y == c) && (p + x)*y == a && (q + x)*y == b) {
						id = i % 4;
						f = true;
						// break;
					}
				}
				// (b,c)
				if (b - c != 0) {
					x = (c * q - b * r) / (b - c);
				}
				if (q + x != 0) {
					y = b / (q + x);
				}
				if (b - c != 0 && q + x != 0) {
					if ((p + x == a || p * y == a || (p + x)*y == a) && (q + x)*y == b && (r + x)*y == c) {
						id = i % 4;
						f = true;
						// break;
					}
				}
				// (c,a)
				if (c - a != 0) {
					x = (a * r - c * p) / (c - a);
				}
				if (r + x != 0) {
					y = c / (r + x);
				}
				if (r + x != 0 && c - a != 0) {
					if ((q + x == b || q * y == b || (q + x)*y == b) && (p + x)*y == a && (r + x)*y == c) {
						id = i % 4;
						f = true;
						// break;
					}
				}



				// case 4 : "*+"

				// subcase->1
				// (a,b)
				if (p - q != 0) {
					x = (a - b) / (p - q);
					y = a - (p * x);
					// cout << x << " " << y << el;
					if ((r * x == c || r + y == c || (r * x) + y == c) && (p * x) + y == a && (q * x) + y == b) {
						// cout << x << " " << y << el;
						id = i % 4; f = true;
						// break;
					}
				}
				// (b,c)
				if (q - r != 0) {
					x = (b - c) / (q - r);
					y = b - (q * x);
					if ((p * x == a || p + y == a || (p * x) + y == a) && (q * x) + y == b && (r * x) + y == c) {
						id = i % 4;
						f = true;
						// break;
					}
				}
				// (c,a)
				if (r - p != 0) {
					x = (c - a) / (r - p);
					y = c - (r * x);
					if ((q + y == b || q * x == b || (q * x) + y == b) && (p * x) + y == a && (r * x) + y == c) {
						id = i % 4;
						f = true;
						// break;
					}
				}

				// special cases
				// (a,(b,c))
				if (q != 0) {
					x = b / q;
					y = c - r;
					if ((p + y == a || p * x == a || (p * x) + y == a) && r + y == c && q * x == b) {
						id = i % 4; f = true;
						// break;
					}
				}
				// (a,(c,b))
				if (r != 0) {
					x = c / r;
					y = b - q;
					if ((p + y == a || p * x == a || (p * x) + y == a) && q + y == b && r * x == c) {
						id = i % 4; f = true;
						// break;
					}
				}
				// (b,(c,a))
				if (r != 0) {
					x = c / r;
					y = a - p;
					if ((q + y == b || q * x == b || (q * x) + y == b) && p + y == a && r * x == c) {
						id = i % 4; f = true;
						// break;
					}
				}
				if (p != 0) {
					// (b,(a,c))
					x = a / p;
					y = c - r;
					if ((q + y == b || q * x == b || (q * x) + y == b) && r + y == c && p * x == a) {
						id = i % 4; f = true;
						// break;
					}
				}
				// (c,(a,b));
				if (p != 0) {
					x = a / p;
					y = b - q;
					if ((r * x == c || r + y == c || (r * x) + y == c) && q + y == b && p * x == a) {
						id = i % 4; f = true;
						// break;
					}
				}
				// (c,(b,a))
				if (q != 0) {
					x = b / q;
					y = a - p;
					if ((r * x == c || r + y == c || (r * x) + y == c) && p + y == a && q * x == b) {
						id = i % 4; f = true;
						// break;
					}
				}
				// most special case
				// (a,(b,c))
				if (q != 0) {
					x = c - r;
					y = b / q;
					if ((p + x == a || p * y == a || (p + x)*y == a) && q * y == b && r + x == c) {
						id = i % 4;
						f = true;
					}
				}
				// (a,(c,b))
				if (r != 0) {
					x = b - q;
					y = c / r;
					if ((p + x == a || p * y == a || (p + x)*y == a) && y * r == c && q + x == b) {
						id = i % 4;
						f = true;
					}
				}
				// (b,(a,c))
				if (p != 0) {
					x = c - r;
					y = a / p;
					if ((q + x == b || q * y == b || (q + x)*y == b) && p * y == a && r + x == c) {
						id = i % 4;
						f = true;
					}
				}
				// (b,(c,a))
				if (r != 0) {
					x = a - p;
					y = c / r;
					if ((q + x == b || q * y == b || (q + x)*y == b) && r * y == c && p + x == a) {
						id = i % 4;
						f = true;
					}
				}
				// (c,(a,b))
				if (p != 0) {
					x = b - q;
					y = a / p;
					if ((r + x == c || r * y == c || (r + x)*y == c) && p * y == a && q + x == b) {
						id = i % 4;
						f = true;
					}
				}
				// (c,(b,a))
				if (q != 0) {
					x = a - p;
					y = b / q;
					if ((r + x == c || r * y == c || (r + x)*y == c) && q * y == b && p + x == a) {
						id = i % 4;
						f = true;
					}
				}
			}
			// if answer is 3
			if (i % 4 == 3) {
				id = i % 4;
				// break;
			}
		}
    cout<<cnt<<el;
		// cout << id << el;
	}

	return 0;
}

// 1
// 9 -5 0
// -6 10 -6