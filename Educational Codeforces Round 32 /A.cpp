/*
 * A.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int c = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1)
			;
		else if (((a[i] > a[i - 1] && a[i] > a[i + 1])
				|| (a[i] < a[i - 1] && a[i] < a[i + 1])))
			c++;
	}

	cout << c;
	return 0;
}
