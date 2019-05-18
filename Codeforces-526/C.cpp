#include <bits/stdc++.h>
using namespace std;

int const M = 1e9+7;

int mmul(int a,int b){return 1ll*a*b%M;}


int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);
  string s;
  cin>>s;
  int n = s.length();
  //
  vector<int> a;
  int i =0;
  while(i<n){
    int cnt = 0;
    while(i<n && s[i]!='a') i++;
    if (i>=n) break;
    cnt++; i++;
    while(i<n && s[i]!='b'){
      if (s[i]=='a') cnt++;
      i++;
    }
    if (cnt) a.push_back(cnt);
    if (i>=n) break;
    i++;
  }

  int ans = 1;
  for(int x:a){
    ans = mmul(ans,x+1);
  }
  cout<<ans-1;
  return 0;
}
