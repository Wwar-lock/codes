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

void printQ(priority_queue<int,vector<int>,greater<int>>pq){
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
  cout<<el;
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
    int n,x;
    cin>>n>>x;
    vi v(n);
    rep(i,n){cin>>v[i];}
    int mx = *max_element(all(v));
    int mn = *min_element(all(v));
    if(mx==mn){
      int cnt=0;
      while(x<mx){
        x*=2;
        cnt++;
      }
      cnt+=(v.size());
      cout<<cnt<<el;
    }
    else{
      int cnt=0;
      sort(all(v));
      // printV(v);
      vector<int>::iterator curr,pre,last;
      last = v.begin()+(v.size()-1);
      pre=v.begin()-1;
      while(true){
        curr = upper_bound(all(v),x);
        pre = curr-1;
        if(pre>=last){
          break;
        }
        // cout<<*pre<<" "<<x<<el;
        if(pre>=v.begin()&&2*(*pre)>=x){
          x = 2*(*pre);
          v.erase(pre);
          last = v.begin()+(v.size()-1);
        }
        else{
          x*=2;
        }
        cnt++;
      }
      cout<<cnt+v.size()<<el;
    }

  }

  return 0;
}