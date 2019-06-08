/*D.cpp
 * Created on: Nov 12, 2017
 *     Author: thaiminh
 */

#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 7;

int n;
int p0[maxn];
int b0[maxn];
int d[maxn][maxn];

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		printf("? %d %d\n", i, 0);
		fflush(stdout);
		scanf("%d", &b0[i]);
		;
	}

	for (int j = 0; j < n; j++) {
		printf("? %d %d\n", 0, j);
		fflush(stdout);
		scanf("%d", &p0[j]);
	}

	//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			d[i][j] = b0[i] ^ p0[0] ^ p0[j];

	vector<int> a;
	for (int t = 0; t < n; t++) {
		bool check = true;
		int u = -1;
		for (int i = 0; i < n; i++)
			if (d[i][t] == 0)
				u = i;

		for (int i = 0; i < n; i++) {
			check = check && (d[u][i] < n) && (d[u][i] >= 0)
					&& (d[d[u][i]][t] == i);
		}

		if (check) {
			a.push_back(t);
		}
	}

	int as = a.size();
	printf("!\n%d\n", as);
	if (as > 0) {
		int x = a[0];
		for (int i = 0; i < n; i++)
			printf("%d ", d[i][x]);
	}
	fflush(stdout);
	return 0;
}
