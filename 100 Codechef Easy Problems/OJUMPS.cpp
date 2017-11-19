/*
 * OJUMPS.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll a; cin>> a;
	if (a % 6 == 0 || a % 6 == 3 || a % 6 == 1) cout << "yes";
	else cout << "no";
	return 0;
}
