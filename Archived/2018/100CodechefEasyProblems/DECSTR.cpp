/*
 * DECSTR.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define endl cout<<"\n"

inline char ch(int x){return x+'a';}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int t;cin>>t;
	string S = "";
	for(int i=0;i<26;++i) S = ch(i)+S;
	while(t--){
		string s;
		int k;cin>>k;
		while(k>=25){
			s= S+s;
			k-=25;
		}
		if (k > 0) {
			s = 'a' + s;
			for (int i = 0; i < k; i++)
				s = ch(i + 1) + s;
		}
		cout<<s,endl;
	}
	return 0;
}
