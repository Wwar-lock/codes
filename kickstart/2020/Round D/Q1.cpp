#include<bits/stdc++.h>
using namespace std;
int main(){
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r", stdin);
//   freopen("output.txt","w", stdout);
// #endif
  int t;
  cin>>t;
  for(int k=1;k<=t;k++){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    int cnt=0;
    int mx=-1;
    for(int i=0;i<n;i++){
      if(v[i]>mx&&i==n-1){
        cnt++;
      }
      else if(v[i]>mx&&i!=n-1){
        if(v[i]>v[i+1]){
          cnt++;
        }
      }
      mx=max(mx,v[i]);
    }
    cout<<"Case #"<<k<<": "<<cnt<<endl;
  }
}