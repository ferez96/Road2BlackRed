/*
 * POTATOES.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

inline bool prime(int x){bool c = x%2; for(int i=3;i<=sqrt(x);i+=2) c=c&&x%i; return c;}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int n = x + y + 1;
		while(!prime(n)){
			n++;
		}

		cout << n - x - y << "\n";
	}


	return 0;
}
