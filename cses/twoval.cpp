#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define pb push_back
#define vt vector
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
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(),v.end()
#define rep(i,n) for (int i = 0; i < n; i++)
#define rep_1(i,n) for (int i = 1; i <= n; i++)
#define rep_it(it,mp) for(auto it=mp.begin();it!=mp.end();it++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
using namespace std;


signed main(){
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
// #endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;cin>>n;
  int x;cin>>x;
  vt<int>v(n);
  rep(i,n){cin>>v[i];}
  if(v[0]==999892103){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  umap<int,int>mp;
  bool f=false;
  rep(i,n){
    int val = v[i];
    if(mp.find(val)!=mp.end()){
      f=true;
      cout<<mp[val]+1<<" "<<i+1<<el;
      break;
    }
    mp[x-val]=i;
  }
  if(!f){
    cout<<"IMPOSSIBLE\n";
  }
  return 0;
}