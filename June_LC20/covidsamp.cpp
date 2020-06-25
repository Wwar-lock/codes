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

int solve(int i, int j, int n) {
	int num;
	cout << 1 << " ";
	cout.flush();
	cout << i << " ";
	cout.flush();
	cout << 0 << " ";
	cout.flush();
	cout << i << " ";
	cout.flush();
	cout << n << el;
	cout.flush();
	cin >> num;

	cout << 1 << " ";
	cout.flush();
	cout << 0 << " ";
	cout.flush();
	cout << j << " ";
	cout.flush();
	cout << n << " ";
	cout.flush();
	cout << j << el;
	cout.flush();
	cin >> num;

	cout << 1 << " ";
	cout.flush();
	cout << i << " ";
	cout.flush();
	cout << j << " ";
	cout.flush();
	cout << i << " ";
	cout.flush();
	cout << j << el;
	cout.flush();
	cin >> num;
	return num;
}


signed main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	ios::sync_with_stdio(false);
// 	cin.tie(0), cout.tie(0);
	srand(time(0));
	int t;
	cin >> t;
	wl(t--) {
		int n, p;
		cin >> n >> p;
		int num;
		vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				v[i][j] = solve(i, j, n);
				// cout << 1 << " ";
				// cout.flush();
				// cout << i << " ";
				// cout.flush();
				// cout << j << " ";
				// cout.flush();
				// cout << i << " ";
				// cout.flush();
				// cout << j << el;
				// cout.flush();
				// cin >> num;
				// v[i][j] = num;
			}
		}

		cout << 2 << el;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << v[i][j] << " ";
				cout.flush();
			}
			cout << el;
			cout.flush();
		}
		int x;
		cin >> x;
		if (x == -1) {
			break;
		}
	}

	return 0;
}