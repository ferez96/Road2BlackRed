/*
 * ANUDTC.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define endl cout<<"\n"

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin), freopen("out.txt","wb",stdout);
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int t;cin>>t;
	while(t--){
		int n;cin>>n;

		bool r1 = 360 % n == 0,
				r2 = 360>=n,
				r3 = 360>=(n*(n+1)/2);

		cout<<(r1?"y":"n")<<' '<<(r2?"y":"n")<<' '<<(r3?"y":"n"),endl;
	}

	cerr<<1000*clock()/CLOCKS_PER_SEC<<"\n";
	return 0;
}
