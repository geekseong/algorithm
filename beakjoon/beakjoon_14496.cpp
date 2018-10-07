#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int * visit;
int min(int a, int b){

    return a > b ? b : a;
}
int proc(vector<vector<int> >, int from , int to, int n){

    if(from == to){
        return 0;
    }

    int ret = 9999;
    for(int i = 0; i<(int)g[from].size(); ++i){
        if(vi
        ret = min(ret, proc(g, g[from][i], to, n) +1);
    }

}
int main(void){

    int from, to;
    int n, m, a ,b;
    
    scanf("%d %d %d %d", &from ,&to, &n, &m);
    vector<vector <int> > g;
    g.assign(n, vector<int>() );
    visit = (int*)mallco(sizeof(int)*n+1);
    memset(visit, 0, sizeof(visit);

    for(int i = 0; i<m; ++i){
        scanf("%d %d", &a, &b);
        g[b].push_back(a);
    }   

    proc(g, from, to, n);
    return 0;
}
