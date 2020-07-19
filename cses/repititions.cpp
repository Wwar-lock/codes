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

#define NO_OF_CHARS 256 
  
int longestUniqueSubsttr(string str) 
{ 
    int n = str.size(); 
  
    int res = 0; // result 
    vector<int> lastIndex(NO_OF_CHARS, -1); 
    int i = 0; 
    for (int j = 0; j < n; j++) { 
        i = max(i, lastIndex[str[j]] + 1); 
        res = max(res, j - i + 1); 
        lastIndex[str[j]] = j; 
    } 
    return res; 
} 

int longestRepString(string s){
  int n=s.size();
  int count=0;
  int res = s[0];
  int curr=1;
  rep(i,n){
    if(i<n-1&&s[i]==s[i+1]){
      curr++;
    }
    else{
      if(curr>count){
        count=curr;
        res=s[i];
      }
      curr=1;
    }
  }
  return count;
}

signed main(){
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
// #endif

//   ios::sync_with_stdio(false);
//   cin.tie(0), cout.tie(0);

  string s;
  cin>>s;
  // cout<<s<<el;
  cout<<longestRepString(s)<<el;

  return 0;
}