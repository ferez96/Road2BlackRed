/*
 * A.cpp
 *
 *  Created on: Nov 12, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> a(6);
	for (int i = 0; i < 6; i++)
		cin >> a[i];

	int sum = 0;
	for (int x : a)
		sum += x;

	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			for (int k = j + 1; k < 6; k++)
				if (a[i] + a[j] + a[k] == sum - (a[i] + a[j] + a[k])) {
					cout << "YES";
					return 0;
				}

	cout << "NO";
	return 0;
}
