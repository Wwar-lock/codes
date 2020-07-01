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

void printMatrix(vector<vector<int>>v){
  for(int i=0;i<v.size();i++){
    for(int j=0;j<v[0].size();j++){
      cout<<v[i][j]<<" ";
    }
    cout<<el;
  }
}

void printList(list<pair<int,int>>*adj,int n){
  for(int i=0;i<n;i++){
    for(auto it = adj[i].begin();it!=adj[i].end();it++){
      cout<<(*it).ss<<" ";
    }
    cout<<el;
  }
}

void dijkstra(list<pair<int,int>> *adj,int source,int n){
  // printMatrix(adj);
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
  vector<int>dist(n,MAX);
  dist[source]=0;
  pq.push({0,source});
  while(!pq.empty()){
    int u = pq.top().ss;
    pq.pop();
    for(auto it=adj[u].begin();it!=adj[u].end();it++){
      int v = (*it).ff;
      int w = (*it).ss;
      if(dist[v]>w+dist[u]){
        dist[v]=w+dist[u];
        pq.push({dist[v],v});
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<dist[i]<<" ";
  }
  cout<<el;
}

bool safe(int x,int y,int n){
  return (x>=0&&x<n&&y>=0&&y<n);
}

bool whetherPathExists(vector<vector<int>>v){
  bool f = false;
  int n = v.size();
  set<pair<int,int>>st;
  queue<pair<int,int>>q;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(v[i][j]==1){
        q.push({i,j});
      }
    }
  }
  pair<int,int>t = q.front();
  // cout<<t.ff<<" "<<t.ss<<" "<<v[t.ff][t.ss]<<el;
  st.insert(t);
  vector<int>dx{-1,0,1,0};
  vector<int>dy{0,1,0,-1};
  while(!q.empty()){
    if(f){break;}
    pair<int,int>p = q.front();
    q.pop();
    int x = p.ff;
    int y = p.ss;
    for(int i=0;i<4;i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(safe(nx,ny,n)){
        if(v[nx][ny]==2){
          // cout<<nx<<" "<<ny<<" "<<v[nx][ny]<<el;
          f=true;
          break;
        }
        if(v[nx][ny]==3&&st.find({nx,ny})==st.end()){
          // cout<<nx<<" "<<ny<<" "<<v[nx][ny]<<el;
          q.push({nx,ny});
          st.insert({nx,ny});
        }
      }
    }
  }
  return f;
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

  // whether path exist or not ;
  vector<vector<int>>v(n,vector<int>(n,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int num;
      cin>>num;
      v[i][j]=num;
    }
  }
  // 3 0 0 0
  // 0 3 3 0
  // 0 1 0 3
  // 0 2 3 3
  if(whetherPathExists(v)){
    cout<<"Yes\n";
  }
  else{
    cout<<"No\n";
  }
  // vector<vector<int>>adj(n,vector<int>(n,0));
  // list<pair<int,int>>*adj;
  // adj = new list<pair<int,int>>[n];
  // memset(adj,0,sizeof(adj));
  // int m;
  // cin>>m;
  // rep(i,m){
  //   int a,b,w;
  //   cin>>a>>b>>w;
  //   adj[a].pb({b,w});
  //   adj[b].pb({a,w});
  // }
  // printMatrix(adj);
  // by using adjacency matrix complexity is much hiher
  // so we use list instead of 2d matrix
  // printList(adj,n);
  // implementing dijkstra Algo
  // dijkstra(adj,0,n);

  return 0;
}