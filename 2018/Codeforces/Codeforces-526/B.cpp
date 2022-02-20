#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll s;
int a[1007];

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);

  cin>>n>>s;
  for(int i=1;i<=n;++i) cin>>a[i];


  //
  ll sum = 0;
  for(int i=1;i<=n;++i) sum+=a[i];
  if (sum<s){
    cout<<-1;
    return 0;
  }


  //
  int min_keg = 1e9+1;
  for(int i=1;i<=n;++i) min_keg= min(min_keg,a[i]);

  ll available = 0;
  for(int i=1;i<=n;++i) available += a[i]-min_keg;

  if (available < s){
    ll req = s - available;
    int x = req/n + (req%n==0?0:1);
    min_keg -=x;
  }

  cout<<min_keg;

  return 0;
}
