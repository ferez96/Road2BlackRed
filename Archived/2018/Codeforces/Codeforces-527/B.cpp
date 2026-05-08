#include<bits/stdc++.h>
using namespace std;

int main(){
  freopen("inp","r",stdin); freopen("out","w",stdout);

  int n;
  cin>>n;
  while(n--){
    string s;
    cin>>s;

    int len = s.length();
    int k = 0;
    for(int i=1;i<len;++i){
      if (s[i] != s[0]){
        k = i;
      }
    }

    if (k==0) cout<<-1<<"\n";
    else{
      char c = s[k];
      s[k] = s[len-1];
      s[len-1] = c;
      cout<<s<<"\n";
    }
  }

  return 0;
}
