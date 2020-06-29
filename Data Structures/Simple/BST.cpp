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

struct TreeNode{
  int val;
  struct TreeNode *left,*right;
};

void inorderTraversal(struct TreeNode *root){
  if(root){
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
  }
}

struct TreeNode *getNode(int x){
  struct TreeNode *tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  tmp->val=x;
  tmp->left=NULL;
  tmp->right=NULL;
  return tmp;
}

struct TreeNode* addNode(struct TreeNode *root,int x){
  if(root==NULL){
    return getNode(x);
  }
  else if(root->val>x){
    root->left = addNode(root->left,x);
  }
  else{
    root->right = addNode(root->right,x);
  }
  return root;
}


signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  struct TreeNode *root = NULL;
  // enter numer of nodes
  int n;
  cin>>n;
  rep(i,n){
    int val;cin>>val;
    root = addNode(root,val);
  }
  cout<<n<<el;
  inorderTraversal(root);
  cout<<el;

  return 0;
}