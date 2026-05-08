/*
 * C.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 7;

bool c[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int s = 1;
	for (int x : a)
		if (c[x])
			s++;
		else
			c[x] = true;

	cout << s;

	return 0;
}
