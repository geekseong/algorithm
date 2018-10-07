#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n;
char sheet[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int visit[101][101];

void input(){

    scanf("%d", &n);

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            scanf("\n%1c", &sheet[i][j]);
        }
    }
}
int inside(int y, int x){

    return (y>=0 && y<n && x >=0 && x<n);
}
void search(int y, int x, char ch){

    visit[y][x] = 1;
    for(int i = 0; i<4; ++i){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(inside(yy, xx) && !visit[yy][xx] && sheet[yy][xx] == ch){
            search(yy,xx, ch);
        }
    }
}
int area(){

    int ans = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            if(!visit[i][j]){
                ++ans;
                search(i, j, sheet[i][j]);
            }
        }
    }
    return ans;
}
void chColor(){

    for(int i = 0; i<n; ++i){
        for(int j  = 0; j<n; ++j){
            if(sheet[i][j] == 'G')
                sheet[i][j] = 'R';
        }
    }

}
int main(void){

    int a, b;
    input();

    a = area();
    chColor();
    memset(visit, 0, sizeof(visit));
    b = area();

    printf("%d %d", a, b);
    return 0;
}
