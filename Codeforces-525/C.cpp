#include <bits/stdc++.h>
using namespace std;

int const maxn = 2000;

int a[maxn+4];

int main(){
  freopen("inp","r",stdin);freopen("out","w",stdout);
  int n; cin>>n;
  for(int i=1;i<=n;++i){cin>>a[i];}

  cout<<n+1<<"\n";
  for(int i=n;i>=1;--i){
    int x = i - a[i];
    while(x<0) x+=n+1;
    cout<<"1 "<<i<<" "<<x<<"\n";
    for(int j = 1; j<=i;++j){
      a[j] += x;
    }
  }

  cout<<"2 "<<n<<" "<<n+1<<"\n";
  return 0;
}
