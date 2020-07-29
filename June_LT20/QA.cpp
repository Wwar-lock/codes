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


string f1(int x){
  string str;
  while(x){
    str+=to_string(x%2);
    x=x/2;
  }
  return str;
}

int f3(string s){
  int num=0,base=1;
  reverse(all(s));
  for(int i=0;i<s.size();i++){
    if(s[i]=='1'){
      num+=base;
    }
    base*=2;
  }
  return num;
}

int f(int x,int y){
  string sx,sy;
  sx = f1(x);
  sy = f1(y);
    reverse(all(sx));reverse(all(sy));
  // cout<<sx<<" "<<sy<<el;
  string xy,yx;
  xy = sx+sy;
  yx = sy+sx;
  int a = f3(xy);
  int b = f3(yx);
  return a-b;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int t;
  cin>>t;
  // cout<<t<<el;
  wl(t--){
    int n;cin>>n;
    vt<int>v(n);
    rep(i,n){cin>>v[i];}
    sort(all(v));
    int mx = v[v.size()-1];
    int mn = v[0];
    // cout<<mn<<" "<<mx<<el;
    cout<<f(mn,mx)<<el;
  }

  return 0;
}