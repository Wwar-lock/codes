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
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
// #endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n,x;
  cin>>n>>x;
  vi v(n);
  bool f=false;
  unordered_map<int,int>mp;
  rep(i,n){cin>>v[i];mp.insert({v[i],i+1});}
  unordered_set<int>st;
  for(int i=0;i<n;i++){
    if(f){
      break;
    }
    st.clear();
    int curr = x-v[i];
    for(int j=i+1;j<n;j++){
      if(st.find(curr-v[j])!=st.end()){
        cout<<mp[v[i]]<<" "<<mp[v[j]]<<" "<<mp[curr-v[j]]<<el;
        f=true;break;
      }
      st.insert(v[j]);
    }
  }
  if(!f){
    cout<<"IMPOSSIBLE";
  }

  return 0;
}