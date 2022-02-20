/*GCD2
 * Created on: Nov 16, 2017
 *     Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define length(x) ((int)x.length())
#define size(x) ((int)x.size)

inline char ch(int x) { return x + '0'; }
inline int num(char x) {return x - '0';}

string add(string a, string b) {
	string re =  "";
	int mem = 0, x, y, val, next;
	int n = max(length(a), length(b));
	for (int i = 0; i < n; i++) {
		x = length(a) <= i ? 0 : num(a[length(a) - 1 - i]);
		y = length(b) <= i ? 0 : num(b[length(b) - 1 - i]);

		val = x + y + mem;
		next = val % 10;
		mem = val / 10;
		re = ch(next) + re;
	}
	return re;
}

string sub(string a, string b) {
	string re = "";
	int mem = 0, x, y, val, next;
	int n = max(length(a), length(b));
	for (int i = 0; i < n; i++) {
		x = length(a) <= i ? 0 : num(a[length(a) - 1 - i]);
		y = length(b) <= i ? 0 : num(b[length(b) - 1 - i]);

		val = x - y - mem;
		next = val < 0 ? val + 10 : val;
		mem = val < 0 ? 1 : 0;

		re = ch(next) + re;

	}
	return re;
}

string mul(string a, string b){
	string re = "";
	string term;
	if(length(a)<length(b)) swap(a,b);
	int na = length(a), nb = length(b);
	for (int i = nb - 1; i >= 0; i--) {
		term = "";
		int val, next, mem = 0;
		for (int j = na - 1; j >= 0; j--) {
			int val = num(a[j]) * num(b[i]) + mem;
			next = val%10;
			mem = val /10;
		}
	}
	return re;
}



string div(string a, string b) {
	string re = "";

	return re;
}

int main() {
	cout<<sub("6234","4567");
	return 0;
}
