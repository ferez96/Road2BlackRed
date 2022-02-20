/*
 * DIVIDING.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD[] = { 1000000007, 1000007, 999999997, 1000000013, 1000041,
		10000019, 9999841, 87999497, 1000029 };

#define size(x) ((int)x.size())

//inline ll fpow(ll n, ll k, int p) {
//	ll r = 1;
//	for (; k; k >>= 1) {
//		if (k & 1) r = r * n % p;
//		n = n * n % p;
//	}
//	return r;
//}
//inline int revMOD(int a, int p) {return fpow(a, p - 2, p);}

ll expect[9];
ll result[9];

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i];

	//
	for(int i=0;i<9;i++)
		expect[i] = ((1ll * n * (n + 1)) / 2) % MOD[i];

	for(int i =0; i<9;i ++){
		for(int x:a)
			result[i] = (result[i] + x) % MOD[i];
	}

	bool good = true;
	for(int i=0;i<9;i++){
//		cout << expect[i] << " - " << result[i] << "\n";
		good = good && expect[i] == result[i];
	}

	if (good) cout << "YES";
	else cout << "NO";

	return 0;
}
