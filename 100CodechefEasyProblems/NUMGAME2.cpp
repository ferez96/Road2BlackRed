/*
 * NUMGAME2.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>> n;
		if(n<=0) cout<<"ALICE";
		else if (n % 4 == 1) cout << "ALICE";
		else cout << "BOB";

		cout << "\n";
	}
	return 0;
}
