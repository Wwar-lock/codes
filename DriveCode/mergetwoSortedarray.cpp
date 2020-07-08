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


signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n,m;
  cin>>n>>m;
  vi a(n),b(m);
  rep(i,n){cin>>a[i];}
  rep(i,m){cin>>b[i];}
  vi c;
  int i=0,j=0;
  while(i<a.size()&&j<b.size()){
    if(a[i]<b[i]){c.pb)a[i];i++;}
    else{c.pb(b[j]);j++;}
  }
  while(i<a.size()){c.pb(a[i]);}
  while(j<b.size()){c.pb(b[j]);}
  rep(i,c.size()){
    cout<<c[i]<< " ";
  }
  cout<<el;
  return 0;
}