#include <bits/stdc++.h>
using namespace std;

int const maxn = 3e5;
int const M = 998244353;

typedef long long ll;
typedef pair<int,int> ii;

int m,n;
int TC;

int madd(int a, int b){ return (a+b)%M;}
int exp2(int n){
  int ans = 1;
  while(n--){
    ans = 2LL*ans%M;
  }
  return ans;
}
void swap(int &a, int &b){int t=a;a=b;b=t;}

int par[maxn+1];
void init(int n){for(int i=1;i<=n;++i) par[i] = -1;}
int root(int u){return par[u]<0?u:root(par[u]);}
void join(int u, int v){
  u = root(u), v = root(v);
  if (u!=v){
    if (par[u]>par[v]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
  }
}

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);
  cin>>TC;
  while(TC--){
    cin>>n>>m;
    vector<ii> V;
    for(int i=1;i<=m;++i){
      int u,v;
      cin>>u>>v;
      V.push_back(ii(u,v));
    }

    init(n);
    for(ii p:V) join(p.first,p.second);

    map<int,set<int>> components;
    for(int i=1;i<=n;++i)
      components(root(i)).insert(i);

    for(auto component: components){
      int u = component.first;
      bfs(u);
    }

  }

  return 0;
}
