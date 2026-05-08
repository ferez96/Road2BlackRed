/*
 * A.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<int> a, b, c;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.insert(t);
	}
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		b.insert(t);
	}

	for (int x : a) {
		for (int y : b) {
			if (x == y)
				c.insert(x);
			c.insert(x * 10 + y);
			c.insert(y * 10 + x);
		}
	}

	cout << (*c.begin());
	return 0;
}
