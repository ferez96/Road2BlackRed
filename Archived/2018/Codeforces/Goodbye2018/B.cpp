#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int,int> Point;

const int maxn = 1e3;

int n;
Point obe[maxn+1],clue[maxn+1];

bool explore(Point T){
	map<Point,bool> expectedClues;
	for(int i = 1;i<=n;++i){
		Point p = obe[i];
		expectedClues[Point(T.x-p.x,T.y-p.y)] = true;
	}
	for(int i = 1;  i<=n; ++i){
		Point c = clue[i];
		if (!expectedClues[c]){
			return false;
		}
	}
	return true;
}

int main(){
	cin>>n;
	for(int i = 1;i<=n; ++i){
		int x,y;
		cin>>x>>y;
		obe[i] = Point(x,y);
	}
	for(int i = 1;i<=n; ++i){
		int x,y;
		cin>>x>>y;
		clue[i] = Point(x,y);
	}

	for(int i=1;i<=n; ++i){
		Point treasure = Point(obe[1].x+clue[i].x, obe[1].y+clue[i].y);
		if (explore(treasure)){
			cout<<treasure.x<<" "<<treasure.y;
			return 0;
		}
	}
	return 0;
}