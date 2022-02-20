#include <bits/stdc++.h>
using namespace std;

const int maxm = 3000;

class Point{
public:
    int x,y,z;
    Point(){}
    Point(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void print_out(){ printf("(%d, %d, %d)\n",x,y,z); }
    bool operator< (const Point& rhs) const{
        if (this->x!=rhs.x){
            return rhs.x<this->x;
        }else if (this->y!=rhs.y){
            return rhs.y<this->y;
        }else{
            return rhs.z<this->z;
        }
    }
};

bool by_x(const Point &a,const Point &b){
    return a.x<b.x;
}
bool by_y(const Point &a,const Point &b){
    return a.y<b.y;
}
bool by_z(const Point &a,const Point &b){
    return a.z<b.z;
}

class CakePiece{
public:
    Point start, end;
    vector<Point> chocos;

    CakePiece(){}
    CakePiece(Point start, Point end, vector<Point> chocos){
        this->start = start;
        this->end = end;
        for(Point choco:chocos){
            this->chocos.push_back(choco);
        }
    }
    
    vector<CakePiece> split_x();
    vector<CakePiece> split_y();
    vector<CakePiece> split_z();

    void print_out(){
        printf("%d %d %d %d %d %d\n", start.x, start.y, start.z, end.x, end.y, end.z); 
    }
};

// variables
int a,b,c,m;
Point chocos[maxm+3];
CakePiece origin;
map<Point, CakePiece> result;

vector<CakePiece> CakePiece::split_x(){
    vector<CakePiece> result_pieces;
    Point new_piece_start;
    Point new_piece_end;
    int new_piece_x_value;
    vector<Point> new_piece_chocos;

    sort(this->chocos.begin(), this->chocos.end(), by_x);
    new_piece_start = this->start;     
    for(int i=0;i<m-1;){
        new_piece_x_value = this->chocos[i].x;        
        new_piece_chocos.push_back(this->chocos[i]);
        i++;
        while(i<m && this->chocos[i].x == new_piece_x_value){
            new_piece_chocos.push_back(this->chocos[i]);
            i++;
        }
        new_piece_end = Point(new_piece_x_value, this->end.y, this->end.z);        
        result_pieces.push_back(CakePiece(new_piece_start, new_piece_end, new_piece_chocos));
        
        // refresh
        new_piece_start = Point(new_piece_x_value+1, this->start.y, this->start.z);
        new_piece_chocos.clear();
    }
    new_piece_chocos.push_back(this->chocos[m-1]);
    result_pieces.push_back(CakePiece(new_piece_start, this->end, new_piece_chocos));
    return result_pieces;
}

vector<CakePiece> CakePiece::split_y(){
    vector<CakePiece> result_pieces;
    Point new_piece_start;
    Point new_piece_end;
    int new_piece_y_value;
    vector<Point> new_piece_chocos;

    sort(this->chocos.begin(), this->chocos.end(), by_y);
    new_piece_start = this->start;     
    for(int i=0;i<m-1;){
        new_piece_y_value = this->chocos[i].y;
        new_piece_chocos.push_back(this->chocos[i]);
        i++;
        while(i<m && this->chocos[i].y == new_piece_y_value){
            new_piece_chocos.push_back(this->chocos[i]);
            i++;
        }
        new_piece_end = Point(this->end.x, new_piece_y_value, this->end.z);        
        result_pieces.push_back(CakePiece(new_piece_start, new_piece_end, new_piece_chocos));
        
        // refresh
        new_piece_start = Point(this->start.z, new_piece_y_value+1, this->start.z);
        new_piece_chocos.clear();
    }
    new_piece_chocos.push_back(this->chocos[m-1]);
    result_pieces.push_back(CakePiece(new_piece_start, this->end, new_piece_chocos));
    return result_pieces;
}

vector<CakePiece> CakePiece::split_z(){
    vector<CakePiece> result_pieces;
    Point new_piece_start;
    Point new_piece_end;
    int new_piece_z_value;
    vector<Point> new_piece_chocos;

    sort(this->chocos.begin(), this->chocos.end(), by_z);
    new_piece_start = this->start;     
    for(int i=0;i<m-1;){
        new_piece_z_value = this->chocos[i].z;
        new_piece_chocos.push_back(this->chocos[i]);
        i++;
        while(i<m && this->chocos[i].z == new_piece_z_value){
            new_piece_chocos.push_back(this->chocos[i]);
            i++;
        }
        new_piece_end = Point(this->end.x, this->end.y, new_piece_z_value);        
        result_pieces.push_back(CakePiece(new_piece_start, new_piece_end, new_piece_chocos));
        
        // refresh
        new_piece_start = Point(this->start.z, this->start.y, new_piece_z_value+1);
        new_piece_chocos.clear();
    }
    new_piece_chocos.push_back(this->chocos[m-1]);
    result_pieces.push_back(CakePiece(new_piece_start, this->end, new_piece_chocos));
    return result_pieces;
}

void __input(int checker){
    int x,y,z;
    vector<Point> vchoco;
    a = checker;
    cin>>b>>c>>m;        
    for(int i=0;i<m;++i){        
        cin>>x>>y>>z;
        chocos[i] = Point(x,y,z);
        vchoco.push_back(chocos[i]);
    }
    origin = CakePiece(Point(1,1,1),Point(a,b,c), vchoco);
}

void __solve(){    
    cout<<"YES"<<endl;
    vector<CakePiece> new_pieces_x = origin.split_x();
    vector<CakePiece> new_pieces_y;    
    for(CakePiece piece:new_pieces_x){                
        vector<CakePiece> new_pieces = piece.split_y();
        for(CakePiece x: new_pieces){
            new_pieces_y.push_back(x);
        }
    }
    vector<CakePiece> new_pieces_z;
    for(CakePiece piece:new_pieces_y){        
        vector<CakePiece> new_pieces = piece.split_z();
        for(CakePiece x: new_pieces){
            new_pieces_z.push_back(x);
        }
    }        
    for(CakePiece piece: new_pieces_z){
        result[piece.chocos[0]] = piece;
    }
    for(int i=0;i<m;++i){        
        result[chocos[i]].print_out();
    }        
}



int main(){
    freopen("B.inp", "r", stdin);
    freopen("B.out", "w", stdout);
    int checker;
    cin>>checker;
    while(checker != -1){
        __input(checker);
        __solve();
        cin>>checker;
    }
    return 0;
}