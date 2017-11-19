#include <bits/stdc++.h>
using namespace std;

#define fi "in.txt"
#define fo "out.txt"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


#define FOR(i,n) for(int i=0;i<n;i++)
#define FORd(i,n) for(int i=n-1;i>=0;i--)

#define mp make_pair
#define size(x) ((int)x.size())
#define endl cout<<"\n"


void solv(){
	int n;cin>>n;
	vi l(n+1);
	for(int i=1;i<=n;i++) cin>>l[i];
	int minId = n+1,c=0;
	for(int i=n;i>=1;i--){
		if (i < minId) c++;
		minId = min(minId,i-l[i]);
	}

	cout<<c;
}


inline void freo(){freopen(fi,"r",stdin),freopen(fo,"wb",stdout);}
int main(){
#ifndef ONLINE_JUDGE
	freo();
#endif
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	solv();
	cerr<< 1000*clock()/CLOCKS_PER_SEC<<".ms";
	return 0;
}
