/*
 * A.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c;

int main() {
	cin >> n >> a >> b >> c;

	int x = min(a, min(b, c));
	if (n == 1)
		cout << 0;
	else {
		if (x == a || x == b) {
			cout << (n - 1) * x;
		} else {
			cout << min(a, b) + max((n - 2), 0) * x;
		}
	}

	return 0;
}
