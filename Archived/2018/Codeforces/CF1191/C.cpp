#include <bits/stdc++.h>
using namespace std;

const int maxm = 1e5;
typedef long long int ll;

ll n,m,k;
ll p[maxm+7];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) cin>>p[i];
	p[m+1] = 1e18+1; // bordering

	ll page_start_index = 1;
	int deleted_item_count = 0;
	int next_delete_count = 0;
	int step_count = 0;
	for(int i=1;i<=m;++i){
		if (p[i] - deleted_item_count - page_start_index >= k){
			page_start_index = p[i] - (p[i] % k);
			next_delete_count++;
		}
		// next special number is on the other page
		if (p[i+1] - deleted_item_count - page_start_index >= k){
			deleted_item_count += next_delete_count;
			next_delete_count = 0;
			step_count++;
		}
	}

	cout<<step_count;
}