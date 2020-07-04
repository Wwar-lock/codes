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
    unordered_map<int,int>ma,mb,mp;
    set<int>st;
    rep(i,n){cin>>a[i];ma[a[i]]++;mp[a[i]]++;st.insert(a[i]);}
    rep(i,n){cin>>b[i];mb[b[i]]++;mp[b[i]]++;st.insert(b[i]);}
    bool f=true;
    for(auto it=mp.begin();it!=mp.end();it++){
      if(it->ss&1){
        f=false;
        break;
      }
    }
    if(!f){cout<<-1<<el;continue;}
    mp.clear();
    if(ma==mb){
      cout<<0<<el;
    }
    else{
      vi v;
      int mn;
      for(auto it=st.begin();it!=st.end();it++){v.pb(*it);}
      mn = *min_element(all(v));
      vi tmp;
      for(int i=0;i<v.size();i++){
        if(ma[v[i]]!=mb[v[i]]){
          int tt = abs((ma[v[i]]-mb[v[i]]))/2;
          rep(j,tt){
            tmp.pb(v[i]);
          }
        }
      }
      // printV(tmp);
      int s=0,e=tmp.size()-1;
      int cost=0;
      while(s<=e){
        if(tmp[s]<=2*mn){
          cost+=tmp[s];
          s++;e--;
        }
        else{
          cost+=mn;
          e--;
        }
      }
      cout<<cost<<el;
    }
  }

  return 0;
}