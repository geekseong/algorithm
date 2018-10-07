#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef struct _army{
    int pos;
    int rad;
}ARMY;
int n;
int map[5001][5001];
vector<ARMY> army(3001);
vector<vector<int> > link(3001);
int visit[3001];

void init(){

    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    army.clear();
    for(int i = 0; i<=3000; link[i++].clear());
   
}
int inside(int y, int x){

    return (y>=0 && y<=5000 && x>=0 && x<=5000);
}
void fillArea(int y, int x, int r, int idx){

    for(int i = y; i < y+r; ++i){
        for(int j = x; j<x+r; ++j){
            if(!inside(i, j))
                continue;
       
            if(!map[i][j]){
                link[map[i][j]].push_back(idx);
                link[idx].push_back(map[i][j]);
            }
            else{
                map[i][j] = idx;
            }
        }
    }
}
void areaCheck(){

    for(int i = 0; i<n; ++i){
        int y = army[i].pos/5001;
        int x = army[i].pos%5001;
        int rad = army[i].rad;

        fillArea(y, x, rad, i);
    }
}
void dfs(int node){

    visit[node] = 1;

    for(int i = 0; i<link[node].size(); ++i){
        if(!visit[link[node][i]]){
            dfs(link[node][i]);
        }
    }
}
void search(){

    int ans = 0;
    for(int i = 0; i<n; ++i){
        printf("node(%d) : ", i);
        for(int j = 0; j<link[i].size(); ++j){
            if(!visit[link[i][j]]){
                ++ans;
                visit[i] = 1;
                dfs(link[i][j]);
            }
            printf("%d ", link[i][j]);
        }
        printf("\n");
    }
    printf("%d", ans);
}
int main(void){

    int t;
    int x, y, r;

    scanf("%d",&t);
    for(int i = 0; i<t; ++i){
        init();
        scanf("%d", &n);
        for(int j = 0; j<n; ++j){
            scanf("%d %d %d", &x, &y, &r );
            army.push_back((ARMY){y*5001 +x,r});
        }
        areaCheck();
        search();
    }
}
