// C_test.cpp
#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
	cin>>n;

	set<int> divisor;
	for(int i=1;i<=sqrt(n);++i){
		if (n%i==0) {
			divisor.insert(i);
			divisor.insert(n/i);
		}
	}

	set<long long> ans;
	for(int k:divisor){
		int x = n/k;
		long long sum = 1ll*x+1ll*n*(x-1)/2;
		ans.insert(sum);
	}

	for(long long x: ans){
		cout<<x<<" ";
	}
	return 0;
}
