#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int par[maxn+10];
void init(int n){
    for(int i=0;i<n;++i) par[i] -1;
}
int root(int x){
    if (par[x]<0) return x; else return root(par[x]);
}
int join(int x, int y){
    x = root(x);
    y = root(y);    
    if (par[x]>par[y]) swap(x,y);
    par[y] += par[x];
    par[x] = y;
}

map<string, int> mapping;
int cost[maxn+10];


int cinemasBuildingCost(std::vector<std::string> citiesList, std::vector<std::string> roads)
{
    return 0;
}



int main(){

    return 0;
}