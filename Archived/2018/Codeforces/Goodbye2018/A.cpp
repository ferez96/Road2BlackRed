#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	b-=1,c-=2;
	int ans = min(a,min(b,c));
	cout<<3*ans+3;
	return 0;
}