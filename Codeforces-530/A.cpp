#include <bits/stdc++.h>

using namespace std;

int main(){
  int w,h;
  int a,b,c,d;
  cin>>w>>h;
  cin>>a>>b>>c>>d;

  for(int i=h; i>= 0;i--){
    w+=i;
    if (i==b) w = max(0, w-a);
    if (i==d) w = max(0, w-b);
  }

  cout<<w;
  return 0;
}
