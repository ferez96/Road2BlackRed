#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct DisjoinSet{
  vector<ll> sum;
  vector<int> par;
  void init(int n,vector<int> a){
    for(int i=0;i<=n;++i) this->sum.push_back(1LL*a[i]);
    for(int i=0;i<=n;++i) this->par.push_back(-1);
  }
  int root(int x){return (par[x]<0) ? x: root(par[x]);}
  void join(int x, int y){
    y = root(y);x = root(x);
    this->par[y] += this->par[x];
    this->sum[y] += this->sum[x];
    this->par[x] = y;
  }
};

int main(){
  freopen("inp","r",stdin);freopen("out","w",stdout);
  int n; cin>>n;
  vector<int> a(n+4);
  for(int i=1;i<=n;++i) cin>>a[i];
  DisjoinSet Set;
  Set.init(n,a);
  for(int i=1;i<=n-1;++i){
    int x,y;
    cin>>x>>y;
    if (a[x]>=0 && a[y]>=0){
      Set.join(x,y);
    }
  }

  // cacl
  vector<bool> flag(n);
  for(int i=1;i<=n;++i){
    flag[i] = false;
  }
  vector<int> res;
  for(int i=1;i<=n;++i){
    if(Set.par[i]<0) res.push_back(Set.sum[i]);
  }
  int Max = -1e9-1;for(int x:res){Max = max(Max,x);}
  int cnt = 0;for(int x:res){cnt += Max==x;}

  cout<<1ll*cnt*Max<<" "<<cnt;

  return 0;
}
