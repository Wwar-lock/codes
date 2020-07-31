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

struct node{
  string name;
  string pn;
  int num;
  int in;
};

bool cmp(struct node &a,struct node &b){
  if(a.num==b.num){
    return a.in<b.in;
  }
  return a.num<b.num;
}

void printV(vt<struct node>a){
  rep(i,a.size()){
    cout<<a[i].name<<" "<<a[i].pn<<" "<<a[i].num<<el;
  }
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
    int n;cin>>n;
    vt<struct node>v(n);
    float sum=0;
    rep(i,n){
      v[i].in=i;
      cin>>v[i].name>>v[i].pn>>v[i].num;
      sum+=v[i].num;
    }
    float avg = sum/n;
    vt<struct node>ans;
    rep(i,n){
      if(avg>v[i].num){
        ans.pb(v[i]);
      }
    }
    sort(all(ans),cmp);
    printV(ans);
  }

  return 0;
}