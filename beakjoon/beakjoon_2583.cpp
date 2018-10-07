#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;
int map[102][102];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void print(){

    printf("\n");
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int inside(int y, int x){

    if(y >=0 && y<n && x >= 0 && x < m) 
        return 1;
    else
        return 0;

}
int fillmap(int y, int x){
    
    int cnt = 1 ;
    bool visit[n+1][m+1];
    queue<pair<int, int> > q;
    
    memset(visit, false, sizeof(visit));
    q.push(make_pair(y,x));
    visit[y][x] = 1;

    while(!q.empty()){
    
        pair<int, int> c = q.front();
        q.pop();
        map[c.first][c.second] = 1; 
        for(int i = 0; i<4; ++i){
            if(!map[c.first + dy[i]][c.second + dx[i]] && inside(c.first + dy[i], c.second+dx[i]) && !visit[c.first+dy[i]][c.second + dx[i]]){
                visit[c.first + dy[i]][c.second + dx[i]] = 1;
                q.push(make_pair(c.first + dy[i], c.second + dx[i]));
                ++cnt;
               
            }
        }
    }

    return cnt;
}
void proc(){

    int ans = 0;
    vector<int> area;

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(!map[i][j]){
                area.push_back(fillmap(i, j));   
                ++ans;
            }
        }
    }

    printf("%d\n", ans);
    sort(area.begin(), area.end());
    for(int i = 0 ; i<area.size();++i){
        printf("%d ", area[i]);
    }
}
int main(void){

    int lx, ly, rx, ry;
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i<k; ++i){
        scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
        for(int a = ly; a<ry; ++a){
            for(int b = lx; b<rx; ++b){
                map[a][b] = 1;
            }
        }
    }

    proc();
    return 0;
}
