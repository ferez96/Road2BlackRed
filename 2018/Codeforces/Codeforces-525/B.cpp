#include<bits/stdc++.h>
using namespace std;

int const maxn=1e5;

int main(){
  int n,k;
  freopen("inp","r",stdin);freopen("out","w",stdout);
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;++i)cin>>a[i];

  sort(a.begin(),a.end());
  vector<int> b(n);
  b[0] = a[0];
  for(int i=1;i<n;++i) b[i] = a[i] - a[i-1];
  int i=0;
  while(k-->0&&n>i){
    cout<<b[i++]<<"\n";
    while(!b[i]) i++;
  }
  k++;while(k-->0)cout<<0<<"\n";

  return 0;
}
