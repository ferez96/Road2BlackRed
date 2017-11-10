/*
 * D.cpp
 *
 *  Created on: Nov 9, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll C(ll n, ll k) {
	ll res = 1;
	ll x = (n - k);
	while (n > x) {
		res *= n;
		n--;
	}
	while (k >= 1) {
		res /= k;
		k--;
	}
	return res;
}

const int A[] = { 0, 0, 1, 2, 9 };

int main() {
	int n, k;
	cin >> n >> k;

	ll sum = 1;
	for (int i = 1; i <= k; i++) {
		sum += C(n, i) * A[i];
	}

	cout << sum;


	return 0;
}
