#include <cstdio>
#include <cstring>

int memo[501][501];
int map[501][501];
int visit[501][501];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void input(){

    memset(memo, -1, sizeof(memo));

    scanf("%d %d", &n, &m);
    for(int i = 0 ; i<n; ++i){
        for(int j = 0; j<m; ++j){
            scanf("%d", &map[i][j]);  
        }
    }
}
int inside(int y, int x){

    return (y>=0 && y<n && x>=0 && x<m);
}
int proc(int y, int x){

    if(y == 0 && x == 0){
        return memo[y][x] = 1;
    }

    if(memo[y][x] == -1){

        memo[y][x] = 0;
        for(int i = 0; i<4;++i){
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(inside(yy, xx ) && !visit[yy][xx] && map[yy][xx] > map[y][x]){
                visit[y][x] = 1;
                memo[y][x] += proc(yy,xx);
                visit[y][x] = 0;
            }
        }
    }

    return memo[y][x];
}
int main(void){

    input();
    printf("%d", proc(n-1, m-1));
    return 0;
}
