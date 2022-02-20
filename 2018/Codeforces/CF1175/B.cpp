#include <bits/stdc++.h>
using namespace std;

const char* fi = "B.inp";
const char* fo = "B.out";


typedef unsigned long long int ull;

const ull maxn = 1<<31 -1;


stack<ull> base;

void overflow();

void add(unsigned long long int &x, unsigned long long int y){
	ull _x = x;
	x = x+y;	
	if (x <= _x || x>maxn || y>maxn) overflow();
}

void push_for(ull y){	
	ull _b = base.top();	
	y = y*_b;
	if (y<_b || y>maxn) y=-1;
	base.push(y);
}

void pop_for(){base.pop();}

void overflow(){
	cout<<"OVERFLOW!!";
	exit(0);
}
int main(){
	freopen(fi,"r", stdin), freopen(fo,"w", stdout);

	int n; cin>>n;
	base.push(1);	
	unsigned long long int x = 0,y;	
	for(int i=0;i<n;++i){
		string str;
		cin >> str;
		switch(str[0]){
			case 'a':				
				add(x, base.top());
				break;
			case 'f':
				cin >> y;
				push_for(y);
				break;
			case 'e':
				pop_for();
				break;
		}
	}

	cout<<x;

	return 0;
}