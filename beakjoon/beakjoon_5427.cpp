#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct _coor{
    int y, x;
}COOR;

int t, n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
char map[1003][1003];
int visit[1003][1003];
vector<int> ans;
queue<pair<int, int > >fire;

int canMove(int y, int x){

    if(map[y][x] == '.') 
        return 1;
    else 
        return 0;

}

int isSuccess(int y, int x){

    if(y > m  || y <= 0 || x > n || x <= 0)
        return 1;
    else
        return 0;
}
void print(){

    for(int i = 0; i<m+1; ++i){
        for(int j = 0; j<=n+1; ++j){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
int proc(int y, int x){

    queue<pair<COOR, int> > pos;
    pos.push(make_pair((COOR){y,x},0));
    visit[y][x] = 1;

    while(!pos.empty()){
        
        //이동 할 수 있는지 확인
        int posSize = pos.size();
        for(int i = 0; i<posSize; ++i){
            pair<COOR, int> cur = pos.front();
            pos.pop();
            if(map[cur.first.y][cur.first.x] == '*')
                continue;

            for(int j = 0; j<4; ++j){
                if(isSuccess(cur.first.y + dy[j], cur.first.x + dx[j]))
                    return cur.second+1;
            
                if(!visit[cur.first.y + dy[j]][cur.first.x + dx[j]] && canMove(cur.first.y+dy[j], cur.first.x +dx[j])){
                    pos.push(make_pair((COOR){cur.first.y+dy[j], cur.first.x+dx[j]}, cur.second + 1));
                    visit[cur.first.y + dy[j]][cur.first.x + dx[j]] = 1;
                }
            }
        }
  
            //불이 옮겨 붙는다
        
        int fsize = fire.size();
        for(int i = 0; i<fsize; ++i){
            pair<int, int> cf = fire.front();
            fire.pop();
            for(int j = 0; j<4; ++j){
                if(isSuccess(cf.first+dy[j], cf.second + dx[j])) continue;
                if(!canMove(cf.first+dy[j], cf.second + dx[j])){
                    map[cf.first+dy[j]][cf.second + dx[j]] = '*';
                    fire.push(make_pair(cf.first + dy[j], cf.second + dx[j]));
                }
            }
        }
        //print();
    }

    return -1;
}
int main(void){

    int sx, sy;

    scanf("%d", &t);
    for(int i = 0; i<t; ++i){
        memset(visit, 0, sizeof(visit));
        while(!fire.empty()) fire.pop();
        
        scanf("%d %d",&n, &m);
        for(int j = 0; j<=n+1; ++j) map[0][j] = map[m+1][j] = '.';
        for(int j = 0; j<=m+1; ++j) map[j][0] = map[j][n+1] = '.';
        for(int j = 1; j<=m; ++j){
            for(int k = 1; k<=n; ++k){
                scanf("\n%1c", &map[j][k]);
                if(map[j][k] == '@'){
                    sy = j;
                    sx = k;
                }
                if(map[j][k] == '*'){
                    fire.push(make_pair(j, k));
                }
            }
        }
        ans.push_back(proc(sy, sx));
    }
    
    for(int i = 0; i<ans.size(); ++i){
        if(ans[i] == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans[i]);
    }

    return 0;
}
