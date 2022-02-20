#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxn = 300;

int C[maxn+1],J[maxn+1];
int n;

void __input(){
    cin>>n;
    for(int i=0;i<n;++i) cin>>C[i]>>J[i];
}

int gcd(int a, int b){
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

ii make_ii(int a,int b){    
    int g = gcd(abs(a),abs(b));
    if (a<0&&b<0) g = -g;
    return ii(a/g,b/g);
}

void __solv(int testcase){
    set<ii> x;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if (C[j]!=C[i]){
                ii t = make_ii(J[i]-J[j],C[j]-C[i]);
                if (1LL*t.first*t.second>0) x.insert(t);
                // cerr<<i<<" "<<j<<" "<<t.first<<" "<<t.second<<"\n";
            }
        }
    }
    printf("Case #%d: %d\n",testcase,x.size()+1);
}

int main(){
    // freopen("a.inp","r",stdin);
    int TC;
    cin>>TC;
    for(int testcase=1;testcase<=TC;++testcase){        
        __input();
        __solv(testcase);
    }
    return 0;
}