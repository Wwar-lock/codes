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

set<string>generateAllSubstrings(string s){
  set<string>st;
  for(int i=0;i<s.size();i++){
    for(int j=1;j<=s.size()-i;j++){
      st.insert(s.substr(i,j));
    }
  }
  return st;
}

void printS(set<string>st){
  for(auto it=st.begin();it!=st.end();it++){
    cout<<*it<<el;
  }
}

signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin>>n;
  set<string>st;
  rep(i,n){
    string s;
    cin>>s;
    st.insert(s);
  }
  // printS(st);
  int sz;
  cin>>sz;
  string s;cin>>s;

  set<string>szt = generateAllSubstrings(s);
  // printS(szt);
  int cnt=0;
  for(auto it = szt.begin();it!=szt.end();it++){
    if(st.find(*it)!=st.end()){
      cnt++;
    }
  }
  cout<<cnt<<el;
  return 0;
}