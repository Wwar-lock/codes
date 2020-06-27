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

bool cmp(pair<int,int>&a, pair<int,int>&b){
  if(a.first==b.first){
    return a.second<b.second;
  }
  return a.first>b.first;
}

int calPow(int n,int i){
  int p=1;
  while(i>0){
    p*=2;
    i--;
  }
  return p;
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
  wl(t--){
    int n,k;
    cin>>n>>k;
    vi v(n);
    rep(i,n){
      cin>>v[i];
    }
    bitset<32>btset[n];
    rep(i,n){
      btset[i]=v[i];
    }
    // break;
    vector<pair<int,int>>vp; // <sum,bit_number>
    for(int i=0;i<=30;i++){
      int cnt=0;
      for(int j=0;j<n;j++){
        cnt+=btset[j].test(i);
      }
      if(cnt!=0){
        int msum = cnt*calPow(2,i);
        vp.pb({msum,i});
      }
    }
    sort(all(vp),cmp);
    int ans=0;
    for(int i=0;i<k;i++){
      ans+=pow(2,vp[i].second);
    }
    cout<<ans<<el;
  }

  return 0;
}