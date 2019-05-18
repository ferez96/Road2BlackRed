#include <bits/stdc++.h>
using namespace std;

int const maxn = 1e3;

typedef pair<long,int> ii;

int n,k;
ii a[maxn+7],b[maxn+7],c[maxn+7];

int main(){
  cin>>n>>k;
  for(int i=1;i<=n;++i){
    long x,y,z;
    cin>>x>>y>>z;
    a[i] = ii(x,i);
    b[i] = ii(y,i);
    c[i] = ii(z,i);
  }

  sort(a+1,a+n+1);
  sort(b+1,b+n+1);
  sort(c+1,c+n+1);

  set<int> kk;

  for(int i=1;i<=k;++i){
    kk.insert(a[n-i+1].second);
    kk.insert(b[n-i+1].second);
    kk.insert(c[n-i+1].second);
  }

  cout<<kk.size();

  return 0;
}
