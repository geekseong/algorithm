#include <cstdio>
#include <queue>
using namespace std;

typedef struct _coor{
    int r;
    int b;
}COOR;

int n, m;
int r, b, o;
queue<COOR> q;
char map[11][11];
int visit[11][11][11][11];


void input(){

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            scanf("\n%1c", &map[i][j] );
            if( map[i][j] == 'R')
                r = i*11 + j;
            else if(map[i][j] == 'B')
                b = i*11 + j;
            else if(map[i][j] == 'O')
                o = i*11 + j;
        }
    }
}
void MoveLeft(int ry, int rx, int by, int bx){
    
    int r_y = ry;
    int r_x = rx;
    int b_y = by;
    int b_x = bx;
    int hasNextBlock = 0;
    int success = -1;
    
    if(rx < bx){
            for(; map[r_y][r_x-1] == 'O' || map[r_y][r_x -1] == '.' && !( r_y == b_y && r_x == b_x ) ; --r_x ){
                if(map[r_y][r_x-1] == 'O'){
                    success = 1;
                    break;
                }
            }
            for(; map[b_y][b_x-1] == 'O' || map[b_y][b_x-1] == '.' && !( r_y == b_y && r_x == b_x ); --b_x){
                if(map[b_y][b_x-1] == 'O'){
                    success = 0;
                    break;
                }
            }
    }
    else{
            for(; map[b_y][b_x-1] == 'O' || map[b_y][b_x -1] == '.' && !( r_y == b_y && r_x == b_x ); --b_x){
                if(map[b_y][b_x -1] == 'O'){
                    success = 0;
                    break;
                }
            }
            
            for(; success != 0 && map[r_y][r_x -1] == 'O' || map[r_y][r_x -1] == '.' && !( r_y == b_y && r_x == b_x ) ; --r_x ){
                if(map[r_y][r_x - 1] == 'O'){
                    success = 1;
                    break;
                }
            }
    }
    
    if(success == 1)
        q.push((COOR){-1, -1});
    else if(success != 0 ){
        q.push((COOR){r_y*11 + r_x, b_y*11 + b_x});
    }
}
void MoveRight(int ry, int rx, int by, int bx){
    
    int r_y = ry;
    int r_x = rx;
    int b_y = by;
    int b_x = bx;
    int hasNextBlock = 0;
    int success = -1;
    
    if(rx > bx){
            for(; map[r_y][r_x+1] == 'O' || map[r_y][r_x +1] == '.' && !( r_y == b_y && r_x == b_x ) ; ++r_x ){
                if(map[r_y][r_x+1] == 'O'){
                    success = 1;
                    break;
                }
            }
            for(; map[b_y][b_x+1] == 'O' && map[b_y][b_x+1] == '.' && !( r_y == b_y && r_x == b_x ); ++b_x){
                if(map[b_y][b_x+1] == 'O'){
                    success = 0;
                    break;
                }
            }
    }
    else{
            for(; map[b_y][b_x+1] == 'O' && map[b_y][b_x +1] == '.' && !( r_y == b_y && r_x == b_x ); ++b_x){
                if(map[b_y][b_x +1] == 'O'){
                    success = 0;
                    break;
                }
            }
            
            for(; success!= 0 && map[r_y][r_x +1] == 'O' || map[r_y][r_x + 1] == '.' && !( r_y == b_y && r_x == b_x ) ; ++r_x ){
                if(map[r_y][r_x + 1] == 'O'){
                    success = 1;
                    break;
                }
            }
    }
    
    if(success == 1)
        q.push((COOR){-1, -1});
    else if(success != 0 ){
        q.push((COOR){r_y*11 + r_x, b_y*11 + b_x});
    }
}
void MoveDown(int ry, int rx, int by, int bx){
    
    int r_y = ry;
    int r_x = rx;
    int b_y = by;
    int b_x = bx;
    int hasNextBlock = 0;
    int success = -1;
    if(ry > by){
            for(; map[r_y + 1][r_x] == 'O' || map[r_y + 1][r_x] == '.' && !( r_y == b_y && r_x == b_x ) ; ++r_y ){
                if(map[r_y + 1][r_x] == 'O'){
                    success = 1;
                    break;
                }
            }
            for(; map[b_y + 1][b_x] == 'O' || map[b_y + 1][b_x] == '.' && !( r_y == b_y && r_x == b_x ); ++b_y){
                if(map[b_y + 1][b_x] == 'O'){
                    success = 0;
                    break;
                }
            }
    }
    else{
            for(; map[b_y + 1][b_x] == 'O' || map[b_y + 1][b_x] == '.' &&!( r_y == b_y && r_x == b_x ); ++b_y){
                if(map[b_y + 1][b_x] == 'O'){
                    success = 0;
                    break;
                }
            }
            
            for(; success != 0 && map[r_y + 1][r_x] == 'O' || map[r_y + 1][r_x] == '.' && !( r_y == b_y && r_x == b_x ) ; ++r_y ){
                if(map[r_y + 1][r_x] == 'O'){
                    success = 1;
                    break;
                }
            }
    }

    if(success == 1)
        q.push((COOR){-1, -1});
    else if(success != 0){
        q.push((COOR){r_y*11 + r_x, b_y*11 + b_x});
    }
}
void MoveUp(int ry, int rx, int by, int bx){
    
    int r_y = ry;
    int r_x = rx;
    int b_y = by;
    int b_x = bx;
    int hasNextBlock = 0;
    int success = -1;
    if(ry < by){
            for(; map[r_y - 1][r_x] == 'O' || map[r_y - 1][r_x] == '.' && !( r_y == b_y && r_x == b_x ) ; --r_y ){
                if(map[r_y - 1][r_x] == 'O'){
                    success = 1;
                    break;
                }
            }
            for(; map[b_y - 1][b_x] == 'O' || map[b_y - 1][b_x] == '.' && !( r_y == b_y && r_x == b_x ); --b_y){
                if(map[b_y - 1][b_x] == 'O'){
                    success = 0;
                    break;
                }
            }
    }
    else{
            for(; map[b_y - 1][b_x] == 'O' || map[b_y - 1][b_x] == '.' && !( r_y == b_y && r_x == b_x ); --b_y){
                if(map[b_y - 1][b_x] == 'O'){
                    success = 0;
                    break;
                }
            }
            
            for(; success != 0 && map[r_y - 1][r_x] == 'O' || map[r_y - 1][r_x] == '.' && !( r_y == b_y && r_x == b_x ) ; --r_y ){
                if(map[r_y - 1][r_x] == 'O'){
                    success = 1;
                    break;
                }
            }
    }
    
    if(success == 1)
        q.push((COOR){-1, -1});
    else if(success != 0 ){
        q.push((COOR){r_y*11 + r_x, b_y*11 + b_x});
       
    }
}

void search(){

    int step = 0;
    int success = 0;
    int ry, rx, by, bx;
    q.push((COOR){r, b});
    

    while(!q.empty() && step <=10){
        int qsize = q.size();
        for(int i = 0; i<qsize; ++i){

            COOR c = q.front();
            q.pop();
            if(c.r == -1 && c.b == -1){
                success = 1;
                break;
            }
            
            ry = c.r/11;
            rx = c.r%11;
            by = c.b/11;
            bx = c.b%11;
            
            MoveLeft(ry, rx, by, bx);
            MoveRight(ry, rx, by, bx);
            MoveDown(ry, rx, by, bx);
            MoveUp(ry, rx, by, bx);
        }
            if(success)
                break;

            ++step;
    }

    if(success)
        printf("1");
    else
        printf("0");
}
int main(void){

    input();
    search();
    
    return 0;
}
