#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
  int TC;
  cin>>TC;
  while(TC--){
    cin>>s;
    int len = s.length();

    int n = 0;

    if (s[0] == s[len-1]) n = len -3;
    else{
      int pivot = 0;
      int ich = len-1;
      for(int i=1;i<len;++i)
        if (s[i] == s[ich]){
          n += i - pivot - 1;
          pivot = i;
          ich = len-1 - ich;
        }
      n += len - pivot - 1;
    }
    if (n%2) cout<<"Chikapu\n"; else cout<<"Bash\n";
  }
  return 0;
}
