#include <bits/stdc++.h>
using namespace std;

const char* fi = "A.inp";
const char* fo = "A.out";



unsigned long long int n,k;

int main(){
	// freopen(fi,"r", stdin), freopen(fo,"w", stdout);

	int TC;
	cin>>TC;	
	for(int test = 1;test<=TC;++test){
		cin>>n>>k;				
		unsigned long long int cnt = 0;
		while(n>0){
			if (n%k!=0){
				cnt += n%k;
				n -= n%k;
			}else{				
				cnt ++;
				n /= k;	
			}		
		}

		cout <<cnt<<endl;
	}
	return 0;
}