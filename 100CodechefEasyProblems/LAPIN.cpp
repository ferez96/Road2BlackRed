/*
 * LAPIN.cpp
 *
 *  Created on: Nov 14, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TC;
	cin >> TC;
	while (TC--) {
		string s;
		cin >> s;
		int n = s.length();
		vector<int> c(30, 0);
		for (int i = 0; i < n / 2; i++) {
			c[s[i] - 'a']++;
		}

		for (int i = (n / 2 + n % 2); i < n; i++) {
			c[s[i] - 'a']--;
		}

		bool ch = true;
		for (int x : c) {
			ch = ch && x == 0;
		}

		if (ch)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}
