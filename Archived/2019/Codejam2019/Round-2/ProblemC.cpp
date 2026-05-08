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

inline int max(int x, int y){return x<y?y:x;}

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

bool check(int x, int y){
    // fprintf(stderr,"%d %d\n",x,y);
    int cur = 0;
    int next;
    for(int i=0;i<n;++i){
        next = C[i]*x+J[i]*y;
        // cerr<<" "<<next;
        if (next<=cur) return false;
        cur = next;
    }
    // cerr<<"\n";
    return true;
}


void __solv(int testcase){
    set<ii> x;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if (C[j]!=C[i]){
                ii t = make_ii(J[i]-J[j],C[j]-C[i]);
                if (1LL*t.first*t.second>0) x.insert(t);                
            }
        }
    }

    if (x.size()==0){
        printf("Case #%d: 1 1\n",testcase);    
        return;
    }

    int result = 1e9+7;
    int resulty,resultd;
    for(int i=0;i<x.size()+1;++i){
        int xx,yy;
        xx = max(x[i].first-1,1), yy=x[i].second;
        if (check(xx,yy) && xx<result) result = xx, resulty = i, resultd=-1;        
        xx = x[i].first+1, yy=x[i].second;
        if (check(xx,yy) && xx<result) result = xx, resulty = i, resultd=1;        
    }

    if (result==1e9+7){
        printf("Case #%d: IMPOSSIBLE\n",testcase);
    }else{
        if (resulty==0&&resultd==-1) {
            int a = x[0].first, b = x[0].second;                   
            printf("Case #%d: %d %d\n",testcase,1,floor(1.0*b/a)+1);
            return;
        }
        if (resulty==n-1&&resultd==+1) {
            int c = x[n-1].first, d = x[n-1].second;                   
            printf("Case #%d: %d %d\n",testcase,1,ceil(1.0*d/c)-1);
            return;
        }

        int a,b,c,d;
        if (resultd==-1){
            a = x[resulty-1].first,b = x[resulty-1].second;
            c = x[resulty].first,d = x[resulty].second;
        }else{
            a = x[resulty].first,b = x[resulty].second;
            c = x[resulty+1].first,d = x[resulty+1].second;
        }
    }
}

int main(){
    freopen("c.inp","r",stdin);
    int TC;
    cin>>TC;
    for(int testcase=1;testcase<=TC;++testcase){        
        __input();
        __solv(testcase);
    }
    return 0;
}