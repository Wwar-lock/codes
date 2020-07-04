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

  int t;
  cin>>t;
  wl(t--){
    int n;
    cin>>n;
    map<int,int>mp;
    set<int>st;
    vi a(n),b(n);
    map<int,int>ma,mb;
    rep(i,n){cin>>a[i];mp[a[i]]++;st.insert(a[i]);ma[a[i]]++;}
    rep(i,n){cin>>b[i];mp[b[i]]++;st.insert(b[i]);mb[a[i]]++;}
    bool f=true;
    for(auto it=mp.begin();it!=mp.end();it++){
      if(it->ss%2==1){
        f=false;
        break;
      }
    }
    if(!f){
      cout<<-1<<el;
      continue;
    }
    mp.clear();
    vi v,tmp;
    for(auto it=st.begin();it!=st.end();it++){
      if(ma[*it]!=mb[*it]){
        tmp.pb(*it);
      }
      v.pb(*it);
    }
    int mn = *min_element(all(v));
    v.clear();
    // cout<<mn<<el;
    int cost=0;
    int s=0,e=tmp.size()-1;
    // code
    
    cout<<cost<<el;
  }

  return 0;
}