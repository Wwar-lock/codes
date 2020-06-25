#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
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
void printVect(vector<int>v) {
	for (int i = 0; i < v.size(); i++) {cout << v[i] << " ";}
	cout << endl;
}
int main()
{
	int tcase; cin >> tcase;
	for (int t = 0; t < tcase; t++) {
		string s;
		cin >> s;
		vector<string>v;
		do {
			// cout<<s<<" ";
			v.pb(s);
		} while (next_permutation(s.begin(), s.end()));
		sort(v.begin(), v.end());
		rep(i, v.size()) {
			cout << v[i] << " ";
		}
		cout << el;
	}
	return 0;
}