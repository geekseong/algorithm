#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef struct _coor{
    int y;
    int x;
}COOR;

int divcheck[301][301];
int sea[301][301];
int visit[301][301];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<COOR> ice;

void print(){

    printf("\n");
    for(int i = 0 ;i <n; ++i){
        for(int j = 0; j< m; ++j){
            printf("%d ",sea[i][j]); 
        }
        printf("\n");
    }
};
void input(){

    scanf("%d %d", &n, &m);
    for(int i = 0; i<n; ++i){
        for(int j = 0 ; j<m; ++j){
            scanf("\n%d", &sea[i][j]);
            if(sea[i][j])
                ice.push_back((COOR){i, j});
        }
    }
}
int inside(int y, int x){
    if( y>=0 && y<n && x >=0 && x<m)
        return 1;
    else 
        return 0;
}
void divSearch(int y, int x){


    int yy, xx;
    int cnt = 0;

    for(int i = 0; i<4; ++i){
        yy = y + dy[i];
        xx = x + dx[i];
        if(inside(yy,xx) && sea[yy][xx] == 0){
            ++cnt;
        }
    }

    visit[y][x] = cnt;
    for(int i = 0; i<4; ++i){
        yy = y + dy[i];
        xx = x + dx[i];
        if(inside(yy,xx) && visit[yy][xx] == -1 && sea[yy][xx]){
            divSearch(yy,xx);
        }
    }
}
int melting(){

    int cnt = 0;
    int sum = 0;
    memset(visit, -1, sizeof(visit));
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            sum += sea[i][j];
            if(sea[i][j] && visit[i][j] == -1){
                //printf("cnt %d, %d %d\n", cnt, i, j);
                if(++cnt >= 2){
                    return 0;
                }
                divSearch(i, j);                
                //print();
            }
        }
    }
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(visit[i][j] == -1)
                continue;
            if(sea[i][j] < visit[i][j])
                sea[i][j] = 0;
            else
                sea[i][j] -= visit[i][j];
        }
    }   
    if(sum == 0)
        return -1;
    else
        return 1;
}
void proc(){

    int ans = 0;
    int ret;
    while(1){
        ret = melting();
        if(ret == -1 || ret == 0)
            break;
        ++ans;
    }

    if(ret == 0)
        printf("%d", ans);
    else 
        printf("0");
}
int main(void){

    input(); 
    proc();
    return 0;
}
