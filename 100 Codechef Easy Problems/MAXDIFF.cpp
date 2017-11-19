/*
 * MAXDIFF.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];

		sort(a.begin(), a.end());
		vector<int> sum(n+1);
		sum[0] = 0;
		for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];

		int sum1 = sum[k];
		int sum2 = sum[n] - sum1;
		int sum3 = sum[n-k];
		int sum4 = sum[n] - sum3;

		cout << max(abs(sum1-sum2),abs(sum3-sum4))<<"\n";
	}
	return 0;
}
