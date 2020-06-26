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

// STACK IMPLEMENTATION ---------------------

void printStack(stack<int>stk){
  while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
  }
  cout<<el;
}

void reverseString(string s){
  stack<char>stk;
  rep(i,s.size()){
    stk.push(s[i]);
  }
  string ans = "";
  while(!stk.empty()){
    ans+=stk.top();
    stk.pop();
  }
  cout<<ans<<el;
}

void printReverseStack(stack<int>stk){
  stack<int>tmp;
  while(!stk.empty()){
    tmp.push(stk.top());
    stk.pop();
  }
  printStack(tmp);
}

void printBracketNumber(string s){
  stack<int>stk;
  int cnt=0;
  int adder=1;
  rep(i,s.size()){
    if(s[i]=='('){
      cnt+=1;
      cout<<cnt<<" ";
      stk.push(cnt);
    }
    if(s[i]==')'){
      cout<<stk.top()<<" ";
      stk.pop();
    }
  }
}

void sortStack(stack<int>&stk){
  stack<int>tmp;
  while(!stk.empty()){
    int num = stk.top();
    stk.pop();
    while(!tmp.empty()&&tmp.top()>num){
      stk.push(tmp.top());
      tmp.pop();
    }
    tmp.push(num);
  }
  printStack(tmp);
}

// END STACK IMPLEMENTATION --------------------------

signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  string s;
  cin>>s;
  printBracketNumber(s);

  // srand(time(0));

  // int n=5;
  // stack<int>stk;
  // rep(i,n){
  //   stk.push(rand()%10);
  // }

  // printStack(stk);
  // sortStack(stk);
  // printStack(stk);

  return 0;
}