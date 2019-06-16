/*
 * LEBOMBS.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int t; cin>> t;
	while(t--){

		int n; cin>>n;
		cin.ignore(1,'\n');
		string s; getline(cin,s);
		int c=0;
		for(int i=0;i<n;i++){
			char l = i==0?'0':s[i-1];
			char r = i==n-1?'0':s[i+1];

			if (s[i] == '0' && l == r && l == '0') c++;
		}

		cout << c<<"\n";
	}
	return 0;
}
