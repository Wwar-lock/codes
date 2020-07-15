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

// updation complexity is : O(log(n))
// query complexity is : O(log(n))

int getMid(int i,int j){
  return i+(j-i)/2;
}

int constructUtilFunction(vi v,int ss,int se,int *st,int si){
  if(v[ss]==v[se]){
    st[si]=v[ss];
    return v[ss];
  }
  int mid = getMid(ss,se);
  st[si] = constructUtilFunction(v,ss,mid,st,2*si+1)+constructUtilFunction(v,mid+1,se,st,2*si+2);
  return st[si];
}

int *contructSegmentTree(vi v){
  int h = (int)(ceil(log2(v.size())));
  int mx_size  = 2*pow(2,h)-1;
  int *st = new int[mx_size];
  constructUtilFunction(v,0,v.size()-1,st,0);
  return st;
}

void updateUtilFunction(int *st,int ss,int se,int id,int diff,int si){
  if(id<ss||id>se){
    return;
  }
  st[si]+=diff;
  if(ss!=se){
    int mid = getMid(ss,se);
    updateUtilFunction(st,ss,mid,id,diff,2*si+1);
    updateUtilFunction(st,ss,mid,id,diff,2*si+2);
  }
}

void updateValue(vi v,int *st,int size,int id,int val){
  if(id<0||id>size-1){
    cout<<"Invalid";
    return;
  }
  int diff = val-v[id];
  v[id] = val;
  updateUtilFunction(st,0,size-1,id,diff,0);
}

int getSumUtil(int *st,int ss,int se,int qs,int qe,int si){
  if(qs<=ss&&qe>=se){
    return st[si];
  }
  if(se<qs||ss>qe){
    return 0;
  }
  int mid = getMid(ss,se);
  return getSumUtil(st,ss,mid,qs,qe,2*si+1)+getSumUtil(st,mid+1,se,qs,qe,2*si+2);
}

int getSum(int *st,int qs,int qe,int n){
  if(qs<0||qs>n-1||qe<0||qe>n-1){
    return -1e7;
  }
  return getSumUtil(st,0,n-1,qs,qe,0);
}

signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  // vi v;
  int n;
  cin>>n;
  vi v(n);
  rep(i,n){
    cin>>v[i];
  }

  int *st = contructSegmentTree(v);

  int sum = getSum(st,2,4,v.size());
  cout<<"sum (2,4): "<<sum<<el;

  updateValue(v,st,v.size(),2,9);
  cout<<getSum(st,2,4,v.size())<<el;

  return 0;
}