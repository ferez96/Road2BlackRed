/*
 * C.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	if (n == 6)
		return 1;
	if (n == 9)
		return 1;
	if (n < 4)
		return -1;
	if (n % 2 == 1) {
		int x = f(n - 9);
		if (x == -1)
			return -1;
		else
			return x + 1;
	} else {
		if (n % 4 == 0) {
			return n / 4;
		} else {
			int x = f(n - 6);
			if (x == -1)
				return -1;
			else
				return x + 1;
		}
	}

}

int main() {
	int q;
	cin >> q;
	while (q-- > 0) {
		int n;
		cin >> n;
		cout << f(n) << "\n";
	}

	return 0;
}
