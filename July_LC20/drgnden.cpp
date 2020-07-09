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

struct Node{
  int x;
  int h;
  int a;
};

void printV(vector<struct Node>v){
  rep(i,v.size()){
    cout<<v[i].x<<" "<<v[i].h<<" "<<v[i].a<<el;
  }
}

// only for 10 marks

signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n,q;
  cin>>n>>q;
  vector<struct Node>v(n);
  rep(i,n){
    v[i].x=i;
    cin>>v[i].h;
  }
  rep(i,n){
    cin>>v[i].a;
  }
  // printV(v);return 0;

  rep(k,q){
    int x,y,z;
    cin>>x>>y>>z;
    if(x==1){
      y-=1;
      v[y].a = z;
    }
    else{
      int st,en;
      st=y-1;
      en=z-1;
      if(st==en){
        cout<<v[st].a<<el;
        continue;
      }
      if(v[st].h<=v[en].h){
        cout<<-1<<el;
        continue;
      }
      bool f=true;
      int hst = v[st].h;
      int hen = v[en].h;
      for(int i=st+1;i<en;i++){
        if(v[i].h>=hst&&v[i].h>=hen){
          f=false;
          break;
        }
      }
      if(!f){cout<<-1<<el;}
      else{
        stack<int>stk;
        f=true;
        if(st>en){
          for(int i=st;i>=en;i--){
            if(stk.empty()){
              stk.push(i);
            }
            else if(v[stk.top()].h<=v[i].h){
              while(v[stk.top()].h<=v[i].h&&!stk.empty()){
                stk.pop();
                if(stk.empty()){
                  f=false;
                  break;
                }
              }
              if(!f){break;}
              stk.push(i);
            }
            else{
              stk.push(i);
            }
          }
          if(stk.size()<2){
            cout<<-1<<el;continue;
          }
          int ans=0;
          while(!stk.empty()){
            ans+=v[stk.top()].a;
            stk.pop();
          }
          cout<<ans<<el;
        }
        else{
          f=true;
          for(int i=st;i<=en;i++){
            if(stk.empty()){
              stk.push(i);
            }
            else if(v[stk.top()].h<=v[i].h){
              while(v[stk.top()].h<=v[i].h&&!stk.empty()){
                stk.pop();
                if(stk.empty()){
                  f=false;
                  break;
                }
              }
              if(!f){break;}
              stk.push(i);
            }
            else{
              stk.push(i);
            }
          }
          if(stk.size()<2){
            cout<<-1<<el;continue;
          }
          int ans=0;
          while(!stk.empty()){
            ans+=v[stk.top()].a;
            stk.pop();
          }
          cout<<ans<<el;
        }
      }
    }
  }

  return 0;
}