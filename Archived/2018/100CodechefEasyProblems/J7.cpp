/*
 * J7.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

const double ESP = 1e-5;

int p, s;
inline double f(double h, int p, int s) {
	return h * h * h - p * h * h / 4 + s * h / 2;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> p >> s;

		double a = 3, b = -p / 2, c = s / 2;
		double delta = b * b - 4 * a * c;
		double h1 = (-b + sqrt(delta)) / (2 * a), h2 = (-b - sqrt(delta))
				/ (2 * a);

		cout << fixed << setprecision(2) << max(f(h1, p, s), f(h2, p, s))
				<< "\n";
	}
	return 0;
}
