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

// LINKED LIST FUNCTIONS ---------------------

struct ListNode{
  int val;
  struct ListNode *next;
};

void printListNode(struct ListNode *head){
  while(head){
    cout<<head->val<<" ";
    head=head->next;
  }
  cout<<el;
  return;
}

struct ListNode* lnode(int x){
  struct ListNode*tmp;
  tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
  tmp->val = x;
  tmp->next = NULL;
  return tmp;
}

void addListNode(struct ListNode ** head,int x){
  struct ListNode *newNode = lnode(x);
  if(*head==NULL){
    *head=newNode;
    return;
  }
  struct ListNode *tr = *head;
  while(tr->next){
    tr = tr->next;
  }
  tr->next = newNode;
  return;
}

int getMiddleListElement(struct ListNode* head){
  struct ListNode *slow,*fast;
  slow = head;
  fast=head;
  while(fast&&fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->val;
}

void reverseLinkedList(struct ListNode **head){
  struct ListNode *nxt,*prev,*curr=*head;
  nxt=NULL;
  prev=NULL;
  while(curr){
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  *head = prev;
}

struct ListNode *reverseLinkedListInGroups(struct ListNode *head,int k){
  int cnt=0;
  struct ListNode *curr = head,*nxt,*prev;
  nxt = prev = NULL;
  while(cnt<k&&curr){
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
    cnt++;
  }
  if(nxt){
    head->next = reverseLinkedListInGroups(nxt,k);
  }
  return prev;
}

void mergeTwoSortedList(struct ListNode *head1,struct ListNode* head2){
  struct ListNode *ans = NULL;
  while(head1&&head2){
    if(head1->val<head2->val){
      addListNode(&ans,head1->val);
      head1 = head1->next;
    }
    else{
      addListNode(&ans,head2->val);
      head2 = head2->next;
    }
  }
  while(head1){
    addListNode(&ans,head1->val);
    head1 = head1->next;
  }
  while(head2){
    addListNode(&ans,head2->val);
    head2 = head2->next;
  }
  printListNode(ans);
}

bool checkCircular(struct ListNode *head){
  struct ListNode *slow,*fast;
  slow=fast=head;
  while(slow&&fast&&fast->next){
    if(slow==fast){
      return true;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  return false;
}

void removeLoopInLinkedList(struct ListNode **head){
  struct ListNode *tmp = *head;
  struct ListNode *slow,*fast;
  slow=fast=tmp;
  while(slow&&fast&&fast->next){
    if(slow==fast){
      break;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  if(slow==fast){
    slow=tmp;
    while(slow->next!=fast->next){
      slow=slow->next;
      fast=fast->next;
    }
    fast->next=NULL;
  }
}

int decimalVal(struct ListNode *head){
  reverseLinkedList(&head);
  int base=1;
  int ans=0;
  while(head){
    if(head->val==1){
      ans+=(base);
    }
    base*=2;
    head=head->next;
  }
  return ans;
}

void addTwoLinkedList(struct ListNode *head1, ListNode *head2){
  reverseLinkedList(&head1);
  reverseLinkedList(&head2);
  printListNode(head1);
  printListNode(head2);
  struct ListNode *ans = NULL;
  int carry=0;
  while(head1&&head2){
    int sum = head1->val + head2->val + carry;
    carry = sum/10;
    addListNode(&ans,sum%10);
    head1 = head1->next;
    head2 = head2->next;
  }
  while(head1){
    int sum = head1->val+carry;
    carry = sum/10;
    addListNode(&ans,sum%10);
    head1 = head1->next;
  }
  while(head2){
    int sum = head2->val+carry;
    carry = sum/10;
    addListNode(&ans,sum%10);
    head2 = head2->next;
  }
  reverseLinkedList(&ans);
  printListNode(ans);
}

void rotateLinkedList(struct ListNode **head,int k){
  if(*head==NULL){
    return;
  }
  struct ListNode *tmp = *head;
  while(tmp->next){
    tmp=tmp->next;
  }
  struct ListNode *tmp1 = *head,*pre;
  int cnt=0;
  while(cnt<k){
    cnt++;
    pre=tmp1;
    tmp1=tmp1->next;
  }
  tmp->next = *head;
  *head=tmp1;
  pre->next = NULL;
}

int convertToNumber(struct ListNode *head){
  reverseLinkedList(&head);
  int base=1;
  int ans=0;
  while(head){
    ans += base*head->val;
    base *= 10;
    head = head->next;
  }
  return ans;
}

void multiplyTwoLinkedList(struct ListNode *head1,struct ListNode *head2){
  struct ListNode *ans = NULL;
  int carry=0,mul,num;
  int b = convertToNumber(head2);
  reverseLinkedList(&head1);
  while(head1){
    num = head1->val;
    mul = num * b + carry;
    carry = mul/10;
    addListNode(&ans,mul%10);
    head1 = head1->next;
  }
  if(carry!=0){
    addListNode(&ans,carry);
  }
  reverseLinkedList(&ans);
  printListNode(ans);
}

void subtractTwoLinkedList(struct ListNode *head1,struct ListNode *head2){
  // assumption: value in head1>=head2
  if(!head1 || !head2){return;}
  reverseLinkedList(&head1);
  reverseLinkedList(&head2);
  // printListNode(head1);
  // printListNode(head2);
  struct ListNode *ans = NULL;
  bool carry=false;
  while(head2){
    int v2 = head2->val;
    int v1 = head1->val;
    if(carry){
      v1-=1;
    }
    if(v1>=v2){
      carry=false;
      addListNode(&ans,v1-v2);
    }
    else{
      carry=true;
      v1=v1+10;
      addListNode(&ans,v1-v2);
    }
    head2=head2->next;
    head1=head1->next;
  }
  while(head1){
    if(carry&&head1->val!=0){
      carry=false;
      addListNode(&ans,head1->val-1);
    }
    else if(carry&&head1->val==0){
      addListNode(&ans,9);
    }
    else{
      addListNode(&ans,head1->val);
    }
    head1 = head1->next;
  }
  reverseLinkedList(&ans);
  printListNode(ans);
}

void deleteNode(struct ListNode **head,int n){
  if(*head==NULL){
    return;
  }
  struct ListNode *tmp = *head,*pre=NULL;
  while(tmp){
    if(tmp->val==n){
      break;
    }
    pre=tmp;
    tmp=tmp->next;
  }
  if(pre==NULL){
    *head=tmp->next;
    return;
  }
  pre->next = tmp->next;
  tmp->next=NULL;
  free(tmp);
}

void splitList(struct ListNode *head,struct ListNode **a,struct ListNode **b){
  // assumed that initial list doesnot contain any cycles :)
  struct ListNode *slow,*fast;
  slow = head;
  fast = head->next;
  while(fast){
    fast = fast->next;
    if(fast){
      slow=slow->next;
      fast=fast->next;
    }
  }
  *a = head;
  *b = slow->next;
  slow->next=NULL;
}

struct ListNode *addSortedLists(struct ListNode *a,struct ListNode *b){
  if(a==NULL){return b;}
  if(b==NULL){return a;}
  struct ListNode *res = NULL;
  if(a->val<=b->val){
    res = a;
    res->next = addSortedLists(a->next,b);
  }
  else{
    res = b;
    res->next = addSortedLists(a,b->next);
  }
  return res;
}

void mergeSortLinkedList(struct ListNode **head1){
  struct ListNode *head = *head1;
  if(head==NULL||head->next==NULL){
    return;
  }
  struct ListNode *a,*b;
  splitList(head,&a,&b);
  mergeSortLinkedList(&a);
  mergeSortLinkedList(&b);
  *head1 = addSortedLists(a,b);
}

void  printInReverse(struct ListNode *head){
  reverseLinkedList(&head);
  printListNode(head);
}
// END LINKED LIST ---------------------


signed main(){
#ifndef ONLINE_JUDGE
  freopen("input.txt","r", stdin);
  freopen("output.txt","w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  int n;
  cin>>n;
  
  struct ListNode *head1 = NULL;

  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    addListNode(&head1,num);
  }
  // rotateLinkedList(&head1,3);
  // cout<<decimalVal(head1);
  // printListNode(head1);
  // int val=1;
  // deleteNode(&head1,val);
  mergeSortLinkedList(&head1);
  printListNode(head1);

  // struct ListNode *ans = reverseLinkedListInGroups(head1,2);
  // printListNode(ans);

  // int m;
  // cin>>m;

  // struct ListNode *head2 = NULL;

  // for(int i=0;i<m;i++){
  //   int num;
  //   cin>>num;
  //   addListNode(&head2,num);
  // }

  // subtractTwoLinkedList(head1,head2);
  // multiplyTwoLinkedList(head1,head2);

  // mergeTwoSortedList(head1,head2);

  // reverseLinkedList(&head1);
  // addTwoLinkedList(head1,head2);

  // printListNode(head1);
  // printListNode(head2);

  return 0;
}