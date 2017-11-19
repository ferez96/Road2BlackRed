/*
 * TOTR.cpp
 *
 *  Created on: Nov 18, 2017
 *      Author: thaiminh
 */
#include <bits/stdc++.h>
using namespace std;

#define size(x) ((int)x.size())

inline char ch(int x){return x+'a';}
inline char CH(int x){return x+'A';}

void solv(){
	int t; cin>>t;
	string m; cin>>m;
	vector<string> s(t);
	for(int i=0;i<t;++i) cin>>s[i];

	map<char, char> dict;
	for(int i=0;i<255;i++) dict[(char) i] = (char) i;
	dict['_'] = ' ';
	for(int i=0;i<size(m);++i)
		dict[ch(i)] = m[i], dict[CH(i)] = toupper(m[i]);

	for(string st:s){
		for(char c:st) cout<<dict[c];
		cout<<"\n";
	}

}
inline void freo()
	{freopen("in.txt","r",stdin),freopen("out.txt","wb",stdout);}

int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solv();
	cerr<<1000*clock()/CLOCKS_PER_SEC <<".ms";
	return 0;
}

