/*
 * B.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<char> ch(n);
	for (int i = 0; i < n; i++)
		cin >> ch[i];

	int x = 0, y = 0;

	for (int i = 0; i < n; i++) {
		switch (ch[i]) {
		case 'U':
			y++;
			break;
		case 'D':
			y--;
			break;
		case 'L':
			x--;
			break;
		case 'R':
			x++;
			break;
		}
	}

	cout << n - abs(x) - abs(y);
	return 0;
}
