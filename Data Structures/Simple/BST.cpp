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

void preTraversal(struct TreeNode *root){
  if(root){
    cout<<root->val<<" ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
  }
}

void postTraversal(struct TreeNode *root){
  if(root){
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout<<root->val<<" ";
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

int getMin(struct TreeNode *root){
  struct TreeNode *t = root;
  while(t->left!=NULL){
    t=t->left;
  }
  return t->val;
}

void getLeafSum(struct TreeNode *root,int *sum){
  if(!root){
    return;
  }
  if(!root->left&&!root->right){
    *sum += root->val;
  }
  getLeafSum(root->left,sum);
  getLeafSum(root->right,sum);
}

struct TreeNode *searchVal(struct TreeNode *root,int x){
  if(root==NULL||root->val==x){
    return root;
  }
  if(root->val>x){
    return searchVal(root->left,x);
  }
  else{
    return searchVal(root->right,x);
  }
}

struct TreeNode *LCA(struct TreeNode *root,int x,int y){
  // it is assumed that both x and y values are present in tree
  if(!root){
    return NULL;
  }
  if(root->val>x&&root->val>y){
    return LCA(root->left,x,y);
  }
  if(root->val<x&&root->val<y){
    return LCA(root->left,x,y);
  }
  return root;
}

void countNodesInGivenRange(struct TreeNode *root,int l,int r,int *count){
  if(!root){
    return;
  }
  if(root->val>=l&&root->val<=r){
    *count+=1;
  }
  countNodesInGivenRange(root->left,l,r,count);
  countNodesInGivenRange(root->right,l,r,count);
}

void getKthSmallest(struct TreeNode *root,int *count,int *ans,int k){
  if(root){
    getKthSmallest(root->left,count,ans,k);
    *count+=1;
    if(*count==k){
      *ans=root->val;
      return;
    }
    getKthSmallest(root->right,count,ans,k);
  }
}

void getKthLargest(struct TreeNode *root,int *count,int *ans,int k){
  if(root){
    getKthLargest(root->left,count,ans,k);
    if(*count==k){
      *ans=root->val;
      return;
    }
    *count-=1;
    getKthLargest(root->right,count,ans,k);
  }
}
//   3
//  /  \
// 1    4
//  \    \
//   2    5

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

  cout<<"Minimum: "<<getMin(root)<<el;
  int sum=0;
  getLeafSum(root,&sum);
  cout<<"Leaf Nodes Sum: "<<sum<<el;
  int count=0;
  countNodesInGivenRange(root,2,4,&count);
  cout<<"Number  of Nodes in range 2,4 are: "<<count<<el;

  int ans;
  count=0;
  getKthSmallest(root,&count,&ans,3);
  cout<<"3rd Smallest value: "<<ans<<el;

  count=n;
  getKthLargest(root,&count,&ans,2);
  cout<<"2nd Largest value: "<<ans<<el;

  return 0;
}