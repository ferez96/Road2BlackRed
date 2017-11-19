#include <bits/stdc++.h>
using namespace std;

string f(int x) {
	if (x == 1)
		return "2(0)";
	if (x == 2)
		return "2";
	int y = log(x) / log(2);
	int z = x - (1 << y);
	if (y == 1) {
		return z == 0 ? "2" : "2+" + f(z);
	} else {
		return z == 0 ? "2(" + f(y) + ")" : "2(" + f(y) + ")+" + f(z);
	}
}

int main() {
	int a[] = { 137, 1315, 73, 136, 255, 1384, 16385 };
	for (int x : a) {
		printf("%d=%s\n", x, f(x).c_str());
	}
	return 0;
}
