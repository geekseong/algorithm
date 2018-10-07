#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int ax, ay;
char map[51][51];
int visit[51][51][64];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void input(){

    scanf("%d %d", &n, &m );
    for(int i =0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            scanf("\n%1c", &map[i][j]);
            if(map[i][j] =='0'){
                ay = i;
                ax = j;
            }
        }
    }
}
int inside(int y, int x ){
    return (y>=0 && y<n && x>=0 && x<m);
}
void search(){

    queue<pair<int, int> > q;
    q.push(make_pair(ay*50 + ax, 0));
    visit[ay][ax][0] = 1;
    int ans = 0;
    int success = 0;

    while(!q.empty() ){
    
        int qsize = q.size();
        while(qsize--){
            
            int yy = q.front().first/50;
            int xx = q.front().first%50;
            int key = q.front().second;
            q.pop();

            if(map[yy][xx] == '1'){
                success = 1;
                break;
            }

            for(int i = 0; i<4; ++i){
                int cy = yy + dy[i];
                int cx = xx + dx[i];
                int nkey = key;

                if(!inside(cy, cx) || map[cy][cx] == '#') 
                    continue;
                if(map[cy][cx]>='a' && map[cy][cx]<='f'){
                    nkey = key | (1<<(map[cy][cx]-'a'));
                    if(visit[cy][cx][key])
                        continue;
                }
                else if(map[cy][cx]>='A' && map[cy][cx]<='F')
                    if( !(key & (1<<(map[cy][cx]-'A'))) )
                        continue;
                else if(visit[cy][cx][key])
                    continue;

                visit[cy][cx][key] = 1;
                q.push(make_pair(cy*50 + cx, key));
                
            }
        }
        if(success)
            break;
        ++ans;
    }

    if(success)
        printf("%d", ans);
    else
        printf("-1");
    return ;
}
int main(void){

    input();
    search();
}
