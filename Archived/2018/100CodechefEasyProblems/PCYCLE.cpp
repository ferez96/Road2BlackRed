/*
 * PCYCLE.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define size(x) ((int)x.size())
#define endl cout<<"\n"

const int MAXN = 1e4+7;

int par[MAXN];

void create(int x){par[x] = -1;}
int root(int x){return par[x]<0?x:root(par[x]);}
void join(int x, int y){
	int a = root(x), b = root(y);
	if(a==b){} else {
		if(par[a]>par[b]) swap(a,b);
		par[a] += par[b], par[b] = a;
	}
}

void solve(){
	int n; cin>>n;
	vector<int> a(n+1); for(int i=1; i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++) create(i);
	vector<bool> check(n+1,false);

	for(int i=1;i<=n;i++)
		if(!check[i]){
			int j = i;
			while(!check[j]) check[j]=true,join(j,a[j]),j = a[j];
		}

	set<int> cycles;
	for(int i=1;i<=n;i++)
		cycles.insert(root(i));

	cout<<size(cycles), endl;
	for(auto x:cycles){
		int y = a[x];
		cout<<x; while(y!=x) cout<<" "<<y,y=a[y]; cout<<" "<<x;
		endl;
	}

}

void freo(const char *a, const char *b){freopen(a,"r",stdin),freopen(b,"wb",stdout);};
int main(){
#ifndef ONLINE_JUDGE
	freo("in.txt","out.txt");
#endif
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	solve();
	cerr<<1000*clock()/CLOCKS_PER_SEC<<".ms";
	return 0;
}
