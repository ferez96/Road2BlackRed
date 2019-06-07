#include <bits/stdc++.h>
using namespace std;

const char* fi = "C.inp";
const char* fo = "C.out";

int n, k;
int a[100'000];
int result[100'000];
int main(){
	freopen(fi,"r", stdin), freopen(fo,"w", stdout);

	int TC; cin>>TC;
	for(int tes=1;tes<=TC;++tes){
		cin>>n>>k;
		for(int i=0;i<n;++i) cin>>a[i];

		sort(a,a+n);
		
		for(int i=0;i<n-k;++i){
			result[i] = abs(a[i]-a[i+k])/2;
		}

		int m = 0;
		for(int i=0;i<n-k;++i){
			if (result[i]<result[m]){
				m = i;
			}
		}

		cout<<a[m]+result[m]<<"\n";
	}

	return 0;
}