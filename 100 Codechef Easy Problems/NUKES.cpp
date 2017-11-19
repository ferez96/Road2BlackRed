/*
 * NUKES.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, n, k;
	cin >> a >> n >> k;

	vector<int> b;
	if (n != 0) {
		n++;
		while (a > 0) {
			int x = a % n;
			b.push_back(x);
			a /= n;
		}
	}

	while ((int) b.size() < k)
		b.push_back(0);

	for (int i = 0; i < k; i++) {
		cout << b[i] << " ";
	}
	return 0;
}
