#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);
  int n;
  int a[200];
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
  }

  int ans = 1e9;
  for(int k=0;k<=100;++k){
    int sum = 0;
    for(int i=0;i<n;++i){
      sum += 2*a[i]*( abs(k-i)+k+i );
    }
    ans  = min(ans,sum);
  }

  cout<<ans;
  return 0;
}
