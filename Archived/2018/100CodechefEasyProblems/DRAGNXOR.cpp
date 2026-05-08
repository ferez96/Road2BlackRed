/*
 * DRAGNXOR.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define endl cout<<"\n"
inline int bit(unsigned int a, int i){return a>>i&1;}

void solv(){
	int t;cin>>t;
	while(t--){
		unsigned n,a,b;cin>>n>>a>>b;

		int ca=0,cb=0;
		for(unsigned int i=0;i<n;i++) if(bit(a,i)==1) ca++;
		for(unsigned int i=0;i<n;i++) if(bit(b,i)==1) cb++;

		if(ca+cb<=n){
			int res =0;
			for(unsigned int i=0;i<n;++i)
				if(i<ca+cb) res = res<<1|1; else res = res<<1;
			cout<<res,endl;
		}else{
			int res = 0;
			for (unsigned int i = 0; i < n; ++i)
				if (i < 2*n - ca - cb) res = res << 1 | 1; else res = res << 1;
			cout << res, endl;
		}
	}
}
inline void freo(){freopen("in.txt","r",stdin), freopen("out.txt","wb",stdout);}
int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solv();
	cerr<<1000*clock()/CLOCKS_PER_SEC<<".ms";
	return 0;
}
