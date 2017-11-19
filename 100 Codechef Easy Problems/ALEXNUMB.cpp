/*
 * ALEXNUMB.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;++i) cin>>a[i];
		sort(a.begin(), a.end());
		long long ans = 1ll*n*(n-1)/2;

		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				int start = i-1;
				while (i < n && a[i] == a[i - 1]) ++i;
				ans -= 1ll * (i - start) * (i - start - 1) / 2;
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}
