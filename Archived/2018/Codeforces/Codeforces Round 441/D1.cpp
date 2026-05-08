/*
 * D1.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 7;

int l[maxn], r[maxn];

int main() {
	int n, x, re;
	set<int> a;
	cin >> n;
	for (int i = 1; i <= n + 1; i++) {
		l[i] = i;
		r[i] = i;
	}

	cout << 1 << " ";
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (a.find(x) == a.end()) {
			a.insert(x);
//			printf("%d ->", x);
			if (l[r[x + 1]] == x) {
				l[r[x + 1]] = l[x - 1];
				r[l[x - 1] + 1] = r[x + 1];
				l[x] = l[x - 1];
				r[x] = r[x + 1];
			} else {
				l[x] = l[x - 1];
				r[l[x - 1] + 1] = r[x];
			}

//			for (int i = 1; i <= n; i++)
//				cout << r[i] << " ";
//			cout << "- " << nr << "\n";
		}
		re = a.size() - (n - l[n]) + 1;
		printf("%d ", re);
	}
	return 0;
}
