#include <bits/stdc++.h>
using namespace std;

int const maxn = 2e5;

typedef long long ll;

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);

  int n;
  cin>>n;
  ll b[maxn+3];
  for(int i=1;i<=n/2;++i) cin>>b[i];

  stack<ll> S;
  S.push(b[1]);
  b[1] = 0;
  for(int i=2;i<=n/2;++i){
    ll x,y;
    if (S.top()+b[i-1]<=b[i]){
      x = max(b[i] - S.top(),b[i-1]); // >= b[i-1]
      y = b[i] - x; // <= S.top()
    }else{
      y = min(b[i] - b[i-1],S.top());
      x = b[i] - y;
    }
    b[i] = x;
    S.push(y);
  }


  for(int i=1;i<=n/2;++i) cout<<b[i]<<" ";
  while(!S.empty()){
    cout<<S.top()<<" ";
    S.pop();
  }

  return 0;
}
