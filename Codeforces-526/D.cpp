#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int const maxn = 3e5;
int n;
int w[maxn+7];
map<int,int> G[maxn+1];
pll dp[maxn+1];

pll max2(pll ab, ll c){ll a = ab.first,b=ab.second; return pll(max(a,c),max(min(a,c),b));}

bool flag[maxn+7];
void dfs(int u){
  flag[u] = false;
  for(auto p:G[u]){
    int v = p.first;
    if (flag[v]){
      dfs(v);
      dp[u] = max2(dp[u], dp[v].first+w[u]-G[u][v]);
      fprintf(stderr, "v=%d -> dp[%d] = ( %l64d, %l64d)\n",v,u,dp[u].first,dp[u].second);
    }
  }
}

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;++i) cin>>w[i];
  for(int i=1;i<=n-1;++i){
    int u,v,c;
    cin>>u>>v>>c;
    G[u][v] = c;
    G[v][u] = c;
  }

  for(int i=1;i<=n;++i) dp[i] = pll(w[i],0);
  for(int i=1;i<=n;++i) flag[i] = true;
  dfs(1);

  ll ans = 0;
  for(int i=1;i<=n;++i) ans = max(ans, dp[i].first + max(dp[i].second - w[i], 0LL));
  cout<<ans;

  return 0;
}
