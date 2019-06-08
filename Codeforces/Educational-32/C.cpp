/*
 * C.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const int maxal = 26;

int maxSpace[maxal];

int main() {
	string s;
	cin >> s;
	int n = s.length();
	for (int i = 0; i < maxal; i++) {
		int prev = -1;
		maxSpace[i] = -1;
		for (int j = 0; j < n; j++) {
			if (s[j] == (char) (i + 'a')) {
				maxSpace[i] = max(maxSpace[i], j - prev);
				prev = j;
			}
		}
		maxSpace[i] = max(maxSpace[i], n - prev);
	}

	int m = n;
	for (int i = 0; i < maxal; i++) {
//		printf("%d\n", maxSpace[i]);
		m = min(m, maxSpace[i]);
	}

	cout << m;
	return 0;
}
