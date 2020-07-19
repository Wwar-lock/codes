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

void printV(vi v){
  rep(i,v.size()){
    cout<<v[i]<<" ";
  }
  cout<<el;
}


signed main(){
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
// #endif

//   ios::sync_with_stdio(false);
//   cin.tie(0), cout.tie(0);

  int n;
  cin>>n;
  int s = (n*(n+1))/2;
  if(s&1){
    cout<<"NO";
  }
  else{
    cout<<"YES\n";
    vi a,b;
    if(n%2==0){
      int d = n/4;
      for(int i=1;i<=d;i++){
        a.pb(i);
        a.pb(n-i+1);
      }
      sort(all(a));
      for(int i=d+1;i<=n-d;i++){
        b.pb(i);
      }
      cout<<a.size()<<el;
      printV(a);
      cout<<b.size()<<el;
      printV(b);
    }
    else{
      a.pb(1);a.pb(2);
      b.pb(3);
      int d = (n-3)/4;
      for(int i=4;i<4+d;i++){
        a.pb(i);
        a.pb(n-(i-3)+1);
      }
      sort(all(a));
      for(int i=4+d;i<=n-d;i++){
        b.pb(i);
      }
      cout<<a.size()<<el;
      printV(a);
      cout<<b.size()<<el;
      printV(b);
    }
  }

  return 0;
}