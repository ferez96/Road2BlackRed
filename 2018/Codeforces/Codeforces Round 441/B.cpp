/*
 * B.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxm = 1e5 + 7;

int n, m, k;
int c[maxm];

int main() {
	cin >> n >> k >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	memset(c, 0, sizeof(c));
	//
	for (int i = 0; i < n; i++)
		c[a[i] % m]++;
	for (int j = 0; j < m; j++) {
		if (c[j] >= k) {
			cout << "Yes\n";
			for (int i = 0; i < n; i++) {
				if (a[i] % m == j && k > 0) {
					cout << a[i] << " ";
					k--;
				}
			}
			return 0;
		}
	}

	cout << "No";
	return 0;
}
