#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

const int maxn = 1e6;


  
int gcdExtended(int a, int b, int *x, int *y) 
{  
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1;  
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}

int modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        return (x%m + m) % m; 
    } 
} 
 

int FACT[maxn+1];
int RFACT[maxn+1];

int main(){
	int n; cin>>n;

	FACT[1] = RFACT[1] = 1;
	for(int i=2;i<=n;++i){
		FACT[i] = 1ll*FACT[i-1]*i % M;
		RFACT[i] = 1ll*RFACT[i-1]*modInverse(i,M) %M;
	}

	int ans = (1ll*n*FACT[n])%M;
	for(int i=1;i<=n;++i){
		ans = (ans + M - (1ll*FACT[n]*RFACT[i])%M)%M;
	}

	cout<<ans+1;

	return 0;
}