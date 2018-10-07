#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[101][101];
int check[101][101];
bool visit[101][101];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int max(int a, int b){

    return a > b ? a :b;
}
int inside(int y, int x ){

    if(y >=0 && y<n && x >=0 && x <n)
        return 1;
    else 
        return 0;
}
void print(){

    printf("\n");
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            printf("%d", check[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
void fillmap(int y, int x){

    visit[y][x] = 1;
    check[y][x] = 1;

    for(int i = 0 ; i<4; ++i){
        int yy = y + dy[i];
        int xx = x + dx[i];
        if(inside(yy, xx) && !visit[yy][xx] && !check[yy][xx]){
            fillmap(yy, xx);
        }
    }
}
int proc(int h){

    int ans = 0;
    memset(check, 0, sizeof(check));
    memset(visit, 0, sizeof(visit));

    //잠기는 위치 표시
    for(int i = 0; i< n; ++i){
        for(int j = 0 ; j<n; ++j){
            if(map[i][j] <= h)
                check[i][j] = 1;
        }
    }
    
    for(int i = 0; i< n; ++i){
        for(int j = 0; j<n; ++j){
            if(!check[i][j]){
                ++ans;
                fillmap(i, j);
            }
        }
    }  
    return ans;
}
int main(void){

    int max_height = 0;
    vector<int> ans;

    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            scanf("\n%d", &map[i][j]);
            max_height = max(max_height, map[i][j]);
        }
    }

    for(int i =0; i<=max_height; ++i){
        ans.push_back(proc(i));    
    }
    sort(ans.begin(), ans.end());
    printf("%d", ans[(int)(ans.size()-1)]);
    return 0;
}
