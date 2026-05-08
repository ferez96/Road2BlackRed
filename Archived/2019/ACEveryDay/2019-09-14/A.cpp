// http://codeforces.com/contest/1209/problem/A
#include <bits/stdc++.h>
using namespace std;


void __solve(){
    int n;
    cin >> n;
    vector<int> a = vector<int>(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    set<int> roots;
    for(int x:a){
        bool isRoot = true;
        queue<int> removeQ;
        for(int root:roots){
            if (x==root) {
                isRoot = false;
            }else{
                if (x % root == 0){
                    isRoot = false;
                }else if (root % x == 0){
                    removeQ.push(root);                    
                }
            }
        }
        for(;!removeQ.empty();){
            roots.erase(removeQ.front());
            removeQ.pop();
        }
        if (isRoot) {
            roots.insert(x);
        }
        // for(int i:roots) cerr<<i<<" ";
        // cerr<<"\n";
    }

    cout << roots.size();
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    __solve();
    return 0;
}