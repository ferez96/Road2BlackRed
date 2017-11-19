/*
 * RIGHTRI.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: thaiminh
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

inline ll len2(ii v){return v.first*v.first + v.second*v.second;}

inline ii seg(ii A, ii B){return ii(B.first-A.first,B.second-A.second);}

inline int check(ii A, ii B, ii C) {
	ii AB = seg(A,B) ,BC = seg(B,C), AC = seg(A,C);
	return (len2(AB) == len2(BC) + len2(AC))
			|| (len2(BC) == len2(AB) + len2(AC))
			|| (len2(AC) == len2(BC) + len2(AB));
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int N;
	cin>>N;

	int c = 0;
	while(N--){
		int x1,x2,x3,y1,y2,y3;
		cin>>x1>>y1;
		cin>>x2>>y2;
		cin>>x3>>y3;

		ii A = ii(x1, y1), B = ii(x2, y2), C = ii(x3, y3);
		c += check(A,B,C);
	}

	cout << c;
	return 0;
}
