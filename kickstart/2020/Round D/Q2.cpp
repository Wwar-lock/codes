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

  int t;
  cin>>t;
  rep(k,t){
    int cnt=0;
    int n;cin>>n;
    vt<int>v(n);
    rep(i,n){cin>>v[i];}
    int l=1,r=4;
    for(int i=1;i<n;i++){
      if(v[i]>v[i-1]){
        l+=1;
        r=4;
      }
      else if(v[i-1]>v[i]){
        l=1;
        r-=1;
      }
      else{
        continue;
      }
      if(l>r){
        l=1;r=4;
        cnt++;
      }
    }
    cout<<"Case #"<<k+1<<": "<<cnt<<endl;
  }

  return 0;
}