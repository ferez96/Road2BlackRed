#include <bits/stdc++.h>
using namespace std;

int f(int n){
	if (n==1) return 0;
	if (n%2 == 1) return 1+f(n+1);
	if (n%2 == 0) return 1+f(n/2);
}

int main(){

	freopen("genA.txt","w",stdout);

	cout<<"long long int arr[]={";
	for(int i=1; i<=20;++i){
		cout<<f(i)<<", ";
	}

	return 0;
}