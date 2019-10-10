#include <bits/stdc++.h>
using namespace std;

#define ECHO(I,N,M,MAP) for(int i=I; i<=N; ++i) {for(int j=I; j<=M;++j) printf(" %4d",MAP[i][j]); cout<< "\n";} cout<<"\n";
#define x first
#define y second

typedef pair<int,int> Pos;

const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
const int _dxy[] = {0,1,2,3};

int m,n,nK;
int _map[52][52];
bool visited[52][52];
int fs[52][52][52];  // i-th key -> (x,y)
Pos S;
vector<Pos> vK; // 1-index -> keys
vector<Pos> vT; // 1-index -> doors
int __map[52][52];
set<pair<int,int>> pairs;


void init(){
    vK.clear();
    vT.clear();
    for(int i=0;i<52;++i) for(int j=0;j<52;++j) for(int k=0;k<52;++k){
        _map[i][j] = 0;
        __map[i][j] = 0;
        fs[k][i][j] = 5000;   
    }    
}

void bfs(int iK,Pos S){
    for(int i=0;i<=n+1; ++i){
        for(int j=0; j<=m+1; ++j){
            visited[i][j] = i==0 || i==n+1 || j==0 || j==m+1;
        }
    }
    queue<Pos> _q;    
    fs[iK][S.x][S.y] = 0;
    visited[S.x][S.y] = true;
    _q.push(S);
    while (!_q.empty()){
        Pos K = _q.front(); _q.pop();
        for(int i:_dxy){      
            int x = K.x+dx[i];
            int y = K.y+dy[i];
            if (!visited[x][y] && _map[x][y]!=2){
                fs[iK][x][y] = fs[iK][K.x][K.y] + 1;
                _q.push(Pos(x,y));
                visited[x][y] = true;
            }
        }
        // ECHO(0,n+1,m+1,dp[0])
    }
    // ECHO(0,n+1,m+1,dp[iK])
}

int treasurePath(vector<string> _m)
{
    init();
    vK.push_back(Pos(0,0));
    vT.push_back(Pos(0,0));
    n = _m.size();
    m = _m[0].length();
    for(int i=1;i<=m;++i){
        for(int j=1; j<=n; ++j){
            _map[i][j] = _m[i-1][j-1] - '0';
            if (!_map[i][j]) S = Pos(i,j); // Start point
            if (_map[i][j] == 3) vK.push_back(Pos(i,j));
            if (_map[i][j] == 4) vT.push_back(Pos(i,j));
        }
    }
    nK = vK.size()-1;    

    // ECHO(1,n,m,_map)
    
    bfs(0, S);
    for(int i=1;i<=nK;++i) bfs(i,vK[i]);
    for(int i=1;i<=nK;++i){
        for(int j=1;j<=nK;++j){
            __map[i][j] = fs[0][vK[i].x][vK[j].y]+fs[i][vT[j].x][vT[j].y];
        }
    }
    ECHO(1,nK,nK,__map);
    
    for(int i=1;i<=nK; ++i){ pairs.insert(make_pair(i,i));} // auto pair K[i] -> T[i]
    int max_length = 0; for(pair<int, int> item: pairs) max_length = max(max_length, __map[item.first][item.second]);
    while(true){
        pair<int,int> *opt_edge = nullptr;
        for(pair<int, int> edge: pairs) if(__map[edge.first][edge.second] == max_length) opt_edge = &edge;
        int s = opt_edge->first;
        int t = opt_edge->second;
        int bound = max_length;
        stack<int> sK, sT;        
        deque<int> path;        
        sK.push(s);
        path.push_back(s);
        for(int i=1;i<=nK;++i){
            if(__map[s][i]<bound) sT.push(i);
        }
        while(sT.top() != t){            
        }
        bool at_K_side = true;
        int prev_node = t;
        while(!path.empty()){
            s = at_K_side?path.back():prev_node;
            t = at_K_side?prev_node:path.back();
            path.pop_back();
        }
    }

    return 0;
}

int main(){
    freopen("H.out", "wb", stdout);
    cout<< treasurePath({"013","114","134"}) <<endl;
    cout<< treasurePath({"023","214","134"}) <<endl;
    return 0;
}