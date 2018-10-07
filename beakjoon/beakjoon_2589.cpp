#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct _coor{
    int y;
    int x;
}COOR;

int n, m;
char map[51][51];
bool visit[51][51];
vector<int> ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void print(){

    for(int i = 0; i<n ; ++i){
        for(int j = 0; j<m; ++j){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
int inside(int y, int x){

    if(y>=0 && y<n && x>=0 && x<m)
        return 1;
    else 
        return 0;
}
COOR searchPos(int y, int x){

    bool visit[n+1][m+1];
    memset(visit, 0, sizeof(visit));
    queue<COOR> q;
    q.push((COOR){y,x});
    visit[y][x] = 1;
    int mx = x, my = y;
    
    while(!q.empty()){

        int qsize = q.size();
        for(int i = 0; i<qsize; ++i){
            COOR c = q.front();
            q.pop();
            mx = c.x; my = c.y;
            
            for(int j = 0; j<4; ++j){
                int xx = c.x + dx[j];
                int yy = c.y + dy[j];
                //printf("inside(%d %d) : %d\n", yy, xx, inside(yy,xx) );
                if(inside(yy,xx) && !visit[yy][xx] && map[yy][xx] == 'L'){
                    q.push((COOR){yy,xx});
                    visit[yy][xx] =  1;
                }
            }
        }
    }
    //printf("%d %d\n", my, mx);
    return (COOR){my, mx};
}
int searchStart(int y, int x){

    int ans = 0;
    queue<COOR> q;
    q.push((COOR){y, x});
    memset(visit, false, sizeof(visit));
    visit[y][x] = 1;

    while(!q.empty()){

        int qsize = q.size();
        for(int i = 0; i<qsize; ++i){
            COOR c = q.front();
            q.pop();
            
            for(int j = 0; j<4; ++j){
                int yy = c.y + dy[j];
                int xx = c.x + dx[j];

                if( inside(yy, xx) && !visit[yy][xx] &&map[yy][xx] == 'L' ){
                    q.push((COOR){yy,xx});
                    visit[yy][xx] = 1;
                }
            }
        }

        if(!q.empty())
            ++ans;
    }
    
    //printf("%d\n",ans );
    return ans;
};

void proc(){

    for(int i = 0; i<n ; ++i){
        for(int j = 0; j<m; ++j){
            if(map[i][j] == 'L'){
                ans.push_back(searchStart(i,j));
            }
        }
    }

    sort(ans.begin(), ans.end());
    printf("%d", ans[ans.size()-1]);
}

int main(void){


    scanf("%d %d", &n, &m);
    for(int i = 0; i<n ; ++i){
        for(int j = 0; j<m; ++j){
            scanf("\n%1c",&map[i][j] );
        }
    }

    proc();
    return 0;
}
