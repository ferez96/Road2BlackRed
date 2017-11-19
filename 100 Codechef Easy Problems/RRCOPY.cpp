/*
 * RRCOPY.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

void solv(){

	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];
		set<int> s(a.begin(),a.end());
		cout<<s.size()<<"\n";
	}
}

inline void freo(const char* i, const char* o)
	{freopen(i,"r",stdin),freopen(o,"wb",stdout);}
int main(){
#ifndef ONLINE_JUDGE
	freo("in.txt","out.txt");
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solv();
	cerr<<1000*clock()/CLOCKS_PER_SEC <<".ms";
	return 0;
}
