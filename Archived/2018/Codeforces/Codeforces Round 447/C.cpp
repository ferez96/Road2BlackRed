/*
 * C.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin), freopen("ou","wb",stdout);
#endif
	int m;cin>>m;
	vector<int> s(m),a;
	for(int i=0;i<m;i++) cin>>s[i];
	int GCD = s[0];
	for(int i=0;i<m;i++) GCD = __gcd(GCD,s[i]);

	if (GCD != s[0]) {
		cout << -1;
	}
	else {
		cout << 3 * m << "\n";
		for (int x : s)
			cout << s[0]<<" "<<x << " "<<s[0]<<" ";
	}
	return 0;
}
