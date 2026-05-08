/*
 * E.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 35 + 7;

int a[maxn];
int n, m;
set<int> aX;
set<int, greater<int>> bX;

set<int> expand(vector<int> ar) {
	set<int> a, b;
	a.insert(0);
	b.insert(0);
	for (auto x : ar) {
		for (int y : a) {
			b.insert((1ll * x + y) % m);
		}
		a = b;
	}
	return a;
}

set<int, greater<int>> expandG(vector<int> ar) {
	set<int, greater<int>> a, b;
	a.insert(0);
	b.insert(0);
	for (auto x : ar) {
		for (int y : a) {
			b.insert((1ll * x + y) % m);
		}
		a = b;
	}
	return a;
}

int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n >> m;

	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
		cin >> a[i];

	aX = expand(vector<int>(a, a + 15));
	bX = expandG(vector<int>(a + 15, a + 35));

	int ma = 0;
	for (int x : aX) {
		auto y = bX.upper_bound(m - x);
		ma = max(ma, (x + *y) % m);
	}

	cout << ma;

	return 0;
}
