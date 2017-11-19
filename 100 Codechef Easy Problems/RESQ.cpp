/*
 * RESQ.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;


void solve(){
	int t;cin>>t;
	while (t--) {
		int n;cin>>n;
		int m = INT32_MAX;
		for(int x=1;x<=sqrt(n);x++){
			if(n%x==0){
				int y = n/x;
				m = min(m, abs(x-y));
			}
		}
		cout << m << "\n";
	}

}

void freo(){
	freopen("in.txt","r", stdin);
	freopen("out.txt","wb",stdout);
}

int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
	cerr << 1000 * clock() / CLOCKS_PER_SEC << ".ms\n";
	return 0;
}
