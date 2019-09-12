// http://codeforces.com/contest/1217/problem/A
#include <bits/stdc++.h>
using namespace std;


int main(){
    std::ios_base::sync_with_stdio(false), cin.tie(0);
    int s, i, e;
    int TC;
    cin >> TC;
    for(int tc = 1; tc <= TC; ++tc){
        cin >> s >> i >> e;
        int sum = s + i + e;
        int mins = max( sum / 2 + 1 , s);
        int maxs = s + e;        
        if ( maxs < mins ){
            cout << "0" << endl;            
        }else {
            cout << (maxs - mins + 1) << endl;
        }
    }
    return 0;
}