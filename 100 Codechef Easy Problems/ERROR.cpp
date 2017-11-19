/*
 * ERROR.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define size(x) ((int)x.size())

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int T;
	cin>>T;
	cin.ignore(1, '\n');
	while(T--){
		string s;
		getline(cin, s);

		bool good = false;
		for(int i=0;i<size(s)-2;i++){
			if(s[i]==s[i+2]&&s[i+1]!=s[i]){
				good = true;
				break;
			}
		}

		if (good) cout<<"Good"; else cout<<"Bad";
		cout << "\n";
	}

	return 0;
}
