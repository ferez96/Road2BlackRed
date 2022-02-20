#include <bits/stdc++.h>
using namespace std;


bool isLucky(int n) {
    vector<int> a;
    while(n>0){
        a.push_back(n%10);
        n/=10;
    }
    // for(int x:a) cout<<x<<"\n";
    int sum1 = 0, sum2 = 0;
    for(int i=0;i<a.size()/2;++i) sum1+=a[i],sum2+=a[n-1-i];
    return sum1 == sum2;
}

int main(){
    cout<<isLucky(239017);
    return 0;
}