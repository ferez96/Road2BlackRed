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

const int MAXN = 2017;

int dp[MAXN][MAXN];

void solv(){
	int n;cin>>n;
	vi a(n+1); for(int i=1;i<=n;++i) cin>>a[i];

	int c1 = 0;
	for (int i = 1; i <= n; ++i) if (a[i] != 1) c1++;
	if(c1<n) {cout<<c1;return;}

	for(int i=1;i<=n;i++) dp[i][i] = a[i];

	for(int i=2;i<=n;++i){
		for(int j=1; j<i;++j){
			dp[j][i] = __gcd(dp[j][i-1],a[i]);
		}
	}
	 int minDif = INT32_MAX;
	 for(int i=1;i<=n;++i)
		 for(int j=1;j<=n;++j)
			if (dp[i][j] == 1) minDif = min(minDif, abs(i - j));

	if (minDif == INT32_MAX) cout << -1;
	else cout << (minDif + n - 1);
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
