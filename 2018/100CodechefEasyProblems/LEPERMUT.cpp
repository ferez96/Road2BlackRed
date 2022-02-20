/*
 * LEPERMUT.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;

		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		a.push_back(INT32_MAX);

		int c1 = 0, c2 = 0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(a[i]>a[j]) c1++;

		for(int i=0;i<n;i++)
			if (a[i] > a[i + 1]) c2++;

		cout << (c1 == c2 ? "YES" : "NO");
		cout << "\n";
	}
	return 0;
}
