/*
 * C.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int E = 10000;

int cal(int x) {
	int r = x;
	while (x > 0) {
		r += x % 10;
		x /= 10;
	}
	return r;
}

int main() {
	int n;
	cin >> n;

	set<int> r;
	for (int i = n; i > n - E; i--) {
		if (n == cal(i))
			r.insert(i);
	}

	cout << r.size() << "\n";
	for (int x : r) {
		cout << x << " ";
	}
	return 0;
}
