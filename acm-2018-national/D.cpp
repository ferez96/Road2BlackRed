#include <bits/stdc++.h>
using namespace std;

int main(){
  int TC; cin>>TC;
  while(TC--){
    cin.ignore();
    string s;
    getline(cin,s);
    for(int i=0; i<s.length(); i++)
      while(s[i] == ' ') s.erase(i,1);
    cout<<s<<"\n";
  }
}
