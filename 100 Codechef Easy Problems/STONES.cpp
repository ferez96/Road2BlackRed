/*
 * STONES.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		string j, s;
		cin >> j >> s;

		set<char> jew;
		for (char x : j)
			jew.insert(x);

		int c = 0;
		for (char x : s)
			c += (jew.find(x) != jew.end());

		cout << c << "\n";

	}
	return 0;
}
