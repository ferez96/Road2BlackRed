/*
 * B.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxa = 2e5 + 7;

int c[maxa];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		c[x] = i;
	}

	c[maxa - 1] = n + 1;
	int m = maxa - 1;
	for (int i = 0; i < maxa; i++)
		if (c[i] != 0 && c[i] < c[m])
			m = i;

	cout << m;
	return 0;
}
