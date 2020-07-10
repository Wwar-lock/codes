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
#define mod 998244353
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

vector<string>vs;
map<string,int>wmp,mp;

set<string>generateAllSubstrings(string s){
  set<string>st;
  for(int i=0;i<s.size();i++){
    for(int j=1;j<=s.size()-i;j++){
      vs.pb(s.substr(i,j));
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

void printV(vector<string>vs){
  rep(i,vs.size()){
    cout<<vs[i]<<el;
  }
}

void printM(map<string,int>mp){
  for(auto it=mp.begin();it!=mp.end();it++){
    cout<<it->ff<<" "<<it->ss<<el;
  }
}

int modInv(int a,int m){
  int m0 = m;
  int y=0,x=1;
  if(m==1){
    return 0;
  }
  while(a>1){
    int q = a/m;
    int t = m;
    m = a%m;
    a=t;
    t=y;

    y = x-q*y;
    x=t;

  }
  if(x<0){
    x+=m0;
  }
  return x;
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
    vs.clear();mp.clear();wmp.clear();
    string s;cin>>s;
    vi v(26);
    rep(i,26){cin>>v[i];}
    set<string>st = generateAllSubstrings(s);
    // printS(st);
    // printV(vs);
    int n = s.size();
    int total = (n*(n+1))/2;
    for(auto it=st.begin();it!=st.end();it++){
      string tmp = *it;
      int cnt=0;
      rep(i,vs.size()){
        if(vs[i]==tmp){cnt++;}
      }
      mp[tmp]=cnt;
    }
    for(auto it=st.begin();it!=st.end();it++){
      string tmp = *it;
      int w=0;
      set<string>ts = generateAllSubstrings(tmp);
      cout<<tmp<<el;
      for(auto its = ts.begin();its!=ts.end();its++){
        // cout<<*its<<el;
        string tts = *its;
        // if(tts==tmp){continue;}
        int wt=0;
        rep(i,tts.size()){
          wt+=v[tts[i]-'a'];
        }
        w+=wt;
        
        // cout<<w<<el;
      }
      wmp[tmp]=w;
    }
    printM(wmp);
    cout<<"------------\n";
    int ans=0;
    for(auto it=st.begin();it!=st.end();it++){
      string tmp = *it;
      cout<<tmp<<el;
      cout<<mp[tmp]<<" "<<wmp[tmp]<<el;   
      ans += ((wmp[tmp]*mp[tmp])%mod);
    }
    cout<<ans<<el;
    cout<<total<<el;
    int m = modInv(total,mod);
    // ans=15;
    cout<<(ans*m)%mod<<el;
  }

  return 0;
}