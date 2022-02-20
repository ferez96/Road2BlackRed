/*
 * NAME2.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define size(x) ((int) x.size())

bool check(string a, string b){
	int i =0, j=0;
	while(i<size(a)&&j<size(b))
		if (a[i] == b[j]) i++, j++; else j++;

	return i==size(a);
}

void solve(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		bool c = check(a,b) || check(b,a);

		if(c) cout<<"YES\n"; else cout<<"NO\n";
	}
}

void freo(){
	freopen("in.txt","r",stdin);
	freopen("out.txt", "wb", stdout);
}


int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	solve();

	return 0;
}
