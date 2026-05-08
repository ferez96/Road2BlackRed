/*
 * B.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: thaiminh
 */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int MOD = 1e9+7;

unsigned long long fpow(unsigned long long x, unsigned long long e) {
	if (e == 0) return 1;
	if (e == 1) return x;

	unsigned long long t = fpow(x, e / 2);
	if (e % 2 == 1) {
		return ((t * t) % MOD * x) % MOD;
	}
	else return (t * t) % MOD;
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("ou","wb",stdout);
#endif
	unsigned long long m, n,k;
	cin>>n>>m>>k;
	if(k==-1&&n%2!=m%2)
	{
		cout<<0;
		return 0;
	}
	cout << fpow(fpow(2,m-1),n-1);

	cerr<<1000*clock()/CLOCKS_PER_SEC;
	return 0;
}
