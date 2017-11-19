/*
 * A.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define fi "in.txt"
#define fo "out.txt"


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORd(i,n) for(int i=n-1;i>=0;i--)

#define mp make_pair
#define size(x) ((int)x.size())
#define endl cout<<"\n"

void solv(){
	int n;cin>>n;
	vi a(n),b(n);
	FOR(i,n) cin>>a[i];
	FOR(i,n) cin>>b[i];

	sort(b.begin(),b.end());
	ll cap = b[n - 1] + b[n - 2];
	for(int x:a) if(cap>=0) cap-=x;
	if(cap>=0) cout<<"YES"; else cout<<"NO";
}


inline void freo(){freopen(fi,"r",stdin),freopen(fo,"wb",stdout);}
int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	solv();
	cerr<< 1000*clock()/CLOCKS_PER_SEC<<".ms";
	return 0;
}
