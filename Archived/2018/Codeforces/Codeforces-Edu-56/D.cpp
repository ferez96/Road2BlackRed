#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int maxn = 3e5;
const int M = 998244353;

typedef long long ll;
typedef pair<int,int> ii;


int mpow2(int n){
	if (n==0) return 1;
	int ans = 2, i = 1;
	while(2*i<=n){
		ans*=ans, ans%=M;
		i*=2;
	}
	return ans*mpow2(n-i);
}

int m,n;
vector<int> G[maxn+1];
int flag[maxn+1];

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) G[i].clear();
	for(int i=1;i<=n;++i) flag[i] = 0;
	for(int i = 1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int cnt = 1;
	for(int i=1;i<=n;++i){
		if (!flag[i]){
			// cout<<"Process vertex "<<i<<" as "<<cnt<<"\n";
			flag[i] = cnt;
			queue<int> Queue;
			Queue.push(i);
			while(!Queue.empty()){
				int u = Queue.front();
				Queue.pop();

				// cout<<u<<":\n";
				for(int v:G[u]){
					// cout<<"\t"<<v<<": ";
					// for(int i=1;i<=n;++i) printf("%3d ",flag[i]); cout<<"\n";

					if (!flag[v]){
						flag[v] = -flag[u];
						Queue.push(v);
					}else if (flag[u]*flag[v]>0){
						cout<<"0\n";
						return;
					}
				}
			}
			cnt++;
		}
	}

	// for(int i=1;i<=n;++i) printf("%3d ",flag[i]); cout<<"\n";

	map<int,int> countMap;
	for(int i=1; i<=n; ++i){
		countMap[flag[i]]++;
	}

	vector<int> anss;
	for(int i=1;i<cnt;++i){
		anss.push_back((mpow2(countMap[i]) + mpow2(countMap[-i]))%M);
	}
	int ans = 1;
	for(int x:anss){
		ans = (1ll*ans*x)%M;
	}
	cout<<ans<<"\n";
}

int main(){
	int TC; cin>>TC;
	while(TC--){
		solve();
	}
	return 0;
}