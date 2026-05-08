#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6;

int n, k;
int a[maxn+1];
int lo_b, up_b;
int cur_max;

int main(int argc, char** argv)
{
	int T, test_case;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		
		cin>>n>>k;
		for( int i = 1; i <= n; ++i ){
		    cin>>a[i];
		}

		sort(a,a+n);
		lo_b = 1, up_b = 1;
		for(int i=1;i<=n;++i){
			up_b = i;
			while (a[up_b]-a[lo_b]>k) lo_b++;
			cur_max = max(cur_max, up_b-lo_b+1);
		}
		
		cout << "Case #" << test_case+1 << endl;
		cout << cur_max << endl;
	}

	return 0;
}