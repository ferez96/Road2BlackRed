#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int arr[N+7];

int Answer;
int n1, n2;

int f(int n){	
	if (n == 1 || arr[n] != 0) return arr[n];
	if (n%2 == 0) arr[n] = 1 + arr[n/2];
	if (n%2 == 1) arr[n] = 2 + arr[(n+1)/2];
	return arr[n];
}


int main(int argc, char** argv)
{
	int T, test_case;	

	freopen("A.inp", "r", stdin);
	freopen("A.out", "w", stdout);

	for(int i=1;i<=N; ++i){
		arr[i] = f(i);
	}
	for(int i=1;i<=N; ++i){
		arr[i] += arr[i-1];
	}

	for(int i=N-10;i<=N;++i) cerr<<arr[i]<<" ";

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{		
		cin>>n1>>n2;
		cout << "Case #" << test_case+1 << "\n";
		cout << arr[n2] - arr[n1-1] << "\n";
	}

	return 0;//Your program should return 0 on normal termination.
}