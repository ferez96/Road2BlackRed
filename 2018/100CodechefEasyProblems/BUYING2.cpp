/*
 * BUYING2.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int m = INT32_MAX;
		for (int x : a)
			m = min(m, x);

		int s = 0;
		for (int x : a)
			s += x;

		int c = s / x;
		if (s - m >= c * x)
			printf("-1\n");
		else
			cout << c << "\n";
	}

	return 0;
}
