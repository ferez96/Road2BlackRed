/*
 * A.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;cin>>s;
	int n = s.size();

	vector<int> QL(n,0),QR(n,0);
	QL[0] = s[0]=='Q'?1:0;
	QR[n-1] = s[n-1]=='Q'?1:0;

	for(int i=1;i<n;i++) QL[i] = QL[i-1]+(s[i]=='Q'?1:0);
	for(int i=n-2;i>=0;i--) QR[i] = QR[i+1]+(s[i]=='Q'?1:0);
	long long c =0;

	for(int i=1;i<n-1;i++)
		if(s[i] =='A') c+=QL[i-1]*QR[i+1];

	cout<<c;

	return 0;
}
