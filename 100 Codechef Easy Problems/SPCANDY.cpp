/*
 * SPCANDY.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl cout<<"\n"


void solve(){
	int t;cin>>t;
	while(t--){
		ull n,k;cin>>n>>k;
		if(k==0)
			cout<<"0 "<<n,endl;
		else
			cout<<(n/k)<<" "<<(n%k),endl;
	}
}

inline void freo(const char* a, const char* b){freopen(a,"r",stdin),freopen(b,"wb",stdout);}
int main(){
#ifndef ONLINE_JUDGE
	freo("in.txt","out.txt");
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
	cerr<< 1000*clock()/CLOCKS_PER_SEC<<".ms";
	return 0;
}
