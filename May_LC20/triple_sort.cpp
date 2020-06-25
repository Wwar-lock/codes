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
#define mod 1000000007
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
	for (int i = 1; i < v.size(); i++) {cout << v[i] << " ";}
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
void printSet(set<int>s) {
	for (auto i = s.begin(); i != s.end(); i++) {
		cout << *i << " ";
	}
	cout << el;
}

// --------------------GENERAL FUNCTIONS END------------------

//This code sucks, you know it and I know it.
//Move on and call me an idiot later.

std::vector<pair<int, pair<int, int>>>a;
map<int, int>mp, smp;

void swapOP(pair<int, int>p1, pair<int, int>p2, pair<int, int>p3, vi &v) {

	// cout << p1.ss << " " << p2.ss << " " << p3.ss << el;
	int t = v[p2.ss];
	v[p2.ss] = v[p1.ss];
	v[p1.ss] = v[p3.ss];
	v[p3.ss] = t;
	mp[p1.ss] = v[p1.ss];
	mp[p2.ss] = v[p2.ss];
	mp[p3.ss] = v[p3.ss];
	smp[v[p1.ss]] = p1.ss;
	smp[v[p2.ss]] = p2.ss;
	smp[v[p3.ss]] = p3.ss;
	// printVect(v);
	a.pb({p1.ss, {p2.ss, p3.ss}});
}

bool func(int a, int b, int c) {
	if (a == b || b == c || c == a) {
		return true;
	}
	return false;
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
	int counter = 0;
	wl(t--) {
		// cout << "-----------------------------\n";
		int n, k; cin >> n >> k;
		vi v(n + 1);
		a.clear();
		mp.clear();
		smp.clear();
		set<int>st;
		int f = 0, count = 0;
		pair<int, int>last1, last2, last3, last4;
		rep_1(i, n) {cin >> v[i]; mp.insert({i, v[i]}); smp.insert({v[i], i});}
		vi ans = v;
		sort(all(ans));
		// printVect(v);
		for (int j = 0; j < 6; j++) {
			for (int i = 1; i <= n; i++) {
				int a = v[i];
				int b = mp[mp[v[i]]];

				// cout << " number of iteration " << i << " ---> " << a << " " << b << el;

				if (v[i] == i) {
					continue;
				}
				else if (a == b) {
					continue;
				}
				else {
					// if (func(v[i], mp[v[i]], mp[mp[v[i]]])) {
					// 	f = 1;
					// 	continue;
					// }
					// else {
					swapOP({v[i], i}, {mp[v[i]], v[i]}, {mp[mp[v[i]]], mp[v[i]]}, v);
					// }
				}

				// printVect(v);
			}
		}
		// printVect(v);
		st.clear();
		if (ans != v) {
			// std::vector<pair<int, pair<int, int>>> sv;
			set<int>s;
			int fl = 0;
			for (int i = 1; i <= n; i++) {
				if (v[i] != i && s.find(i) == s.end()) {
					count++;
					s.insert(v[i]);
					s.insert(mp[v[i]]);
				}

			}
			s.clear();
			// cout << count << el;
			if (count % 2 == 0) {
				// printVect(v);
				set<int>is;
				for (int i = 1; i <= n; i++) {
					if (v[i] == i) {
						continue;
					}
					else {
						if (is.find(i) == is.end()) {
							if (is.size() == 0) {
								last1 = {v[i], i};
								last2 = {mp[v[i]], v[i]};
								is.insert(v[i]); is.insert(mp[v[i]]);
								// cout << last1.ff << last2.ff << el;
							}
							else {
								if (is.find(v[i]) == is.end()) {
									last3 = {v[i], i};
									last4 = {mp[v[i]], v[i]};
									// cout << last1.ss << last2.ss << el;
									// cout << last3.ss << last4.ss << el;
									swapOP(last4, last2, last3, v);
									if (v == ans) {
										break;
									}
									// printVect(v);
									swapOP(last2, last3, last1, v);
									is.clear();
									// printVect(v);
									// continue;
								}
							}
						}
						else if (!func(v[i], mp[v[i]], mp[mp[v[i]]])) {

							pair<int, int>a = {v[i], i};
							pair<int, int>b = {mp[v[i]], v[i]};
							pair<int, int>c = {mp[mp[v[i]]], mp[v[i]]};
							swapOP(a, b, c, v);
							if (v == ans) {
								break;
							}

						}
					}
					// printVect(v);
				}
			}
		}
		// printVect(v);
		if (ans == v) {
			if (a.size() > k) {
				cout << -1 << el;
				continue;
			}
			counter++;
			cout << a.size() << el;
			for (int i = 0; i < a.size(); i++) {
				cout << a[i].ff 	<< " " << a[i].ss.ff << " " << a[i].ss.ss << el;
			}
		}
		else {
			cout << -1 << el;
		}

	}
	// cout << counter << el;


	return 0;
}