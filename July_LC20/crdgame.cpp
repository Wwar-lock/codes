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

int findSum(int x){
  int s=0;
  while(x){
    int r = x%10;
    s+=r;
    x=x/10;
  }
  return s;
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
    int n;
    cin>>n;
    vi a(n),b(n);
    rep(i,n){
      cin>>a[i]>>b[i];
    }
    int ca=0,cb=0;
    rep(i,n){
      int sa = findSum(a[i]);
      int sb = findSum(b[i]);
      // cout<<sa<<" "<<sb<<el;
      if(sa==sb){
        ca++;cb++;continue;
      }
      if(sa>sb){
        ca++;
        continue;
      }
      if(sa<sb){
        cb++;
        continue;
      }
    }
    if(ca==cb){
      cout<<2<<" "<<ca<<el;continue;
    }
    if(ca>cb){
      cout<<0<<" "<<ca<<el;continue;
    }
    if(ca<cb){
      cout<<1<<" "<<cb<<el;continue;
    }

  }

  return 0;
}