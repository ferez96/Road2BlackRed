/*
 * AMSGAME1.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t; cin>>t;
	while(t--){
		int n; cin>> n;
		vector<int> a(n);
		for(int i=0;i<n;i++)cin>>a[i];

		int g=a[0];
		for(int i=1;i<n;i++) g = __gcd(g,a[i]);
		cout << g << "\n";
	}
	return 0;
}
