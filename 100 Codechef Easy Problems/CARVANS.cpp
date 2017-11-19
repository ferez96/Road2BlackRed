/*
 * CARVANS.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<int> a(N);
		for (int i = 0; i < N; i++)
			cin >> a[i];

		int c = 1;
		int curSeg = a[0];
		for (int i = 1; i < N; i++)

			if (a[i] < curSeg) {
				c++;
				curSeg = a[i];
			}

		cout << c << "\n";
	}

	return 0;
}
