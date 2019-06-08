/*
 * B.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (k == 1) {
		sort(a.begin(), a.end());
		cout << (a[0]);
	} else if (k == 2) {
		int x = a[0];
		int y = a[n - 1];
		for (int i = 0; i < n - 1; i++)
			x = min(x, a[i]);
		for (int i = 1; i < n; i++)
			y = min(y, a[i]);

		x = max(a[n - 1], x);
		y = max(a[0], y);
		cout << max(x, y);
	} else {
		sort(a.begin(), a.end());
		cout << a[n - 1];
	}
	return 0;
}
