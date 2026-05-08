// http://codeforces.com/contest/1217/problem/B
#include<bits/stdc++.h>
using namespace std;

int n,x;
int d[1000],h[1000];

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        cin>> n >> x;
        long long mans = 1e10, ans;
        for(int i = 1; i <= n; ++i){
            cin >> d[i] >> h[i];
        }
        int t = 0;
        for(int i = 1; i <= n; ++i){
            t = max(t,d[i]);
        }
        x -= t;
        if (x<=0) cout<<"1\n";
        else {
            for(int i = 1; i <= n; ++i){
                if (h[i] >= d[i]) ans = 1e10; else {
                    ans = x / (d[i]-h[i]);
                    if (x>ans*(d[i]-h[i])) ans++;            
                }
                mans = min(mans,ans);               
            }
            if (mans == 1e10) mans = -1; else mans++;
            cout<<mans<<"\n";
        }
    }
    return 0;
}