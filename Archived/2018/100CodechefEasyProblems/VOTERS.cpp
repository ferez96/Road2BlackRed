/*
 * VOTERS.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n1,n2,n3;
	cin>>n1>>n2>>n3;
	map<int, int> list;
	for (int i = 0; i < n1; i++) {
		int temp;
		cin >> temp;
		list[temp]++;
	}

	for (int i = 0; i < n2; i++) {
		int temp;
		cin >> temp;
		list[temp]++;
	}

	for (int i = 0; i < n3; i++) {
		int temp;
		cin >> temp;
		list[temp]++;
	}

	set<int> s;
	for(auto x:list){
		if (x.second >= 2) s.insert(x.first);
	}

	cout<<s.size()<<"\n";
	for (int x : s)
		cout << x << "\n";
	return 0;
}
