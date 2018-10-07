#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;
int map[102][102];
int apple_check[100];
vector<pair<int, int> > apple_coor;
vector<pair<int, int> > snake;
vector<pair<int, char> > direction;

int hasApple(int y, int x){

    for(int i = 0; i<apple_coor.size(); ++i){
        if(y == apple_coor[i].first && x == apple_coor[i].second && !apple_check[i]){
            apple_check[i] = 1;
            return 1;
        }
    }

    return 0;
};
int isCollision(int y, int x){

    //벽에 부딛힌거
    if(y == 0 || x == 0 || x == n+1 || y == n+1)
        return 1;
    //자기 몸통에  부딛힌거
    for(int i = 0; i<snake.size()-1; ++i){
        if(snake[i].first == y && snake[i].second == x)
            return 1;
    }
    return 0;
};
int needDirChange(int sec){

    for(int i = 0; i<direction.size(); ++i){
        if(sec == direction[i].first)
            return i;
    }

    return -1;
}
void playGame(){

    int dir = 0;
    int head = 0;
    int sec = 0;
    int chDirIdx;

    while(++sec){
       
        //충돌검사
        if(isCollision(snake[head].first + dy[dir], snake[head].second + dx[dir])){
            break;
        }
        // 사과 먹었을 경우
        if(hasApple(snake[head].first + dy[dir], snake[head].second + dx[dir])){
            snake.push_back(make_pair(snake[head].first + dy[dir], snake[head].second + dx[dir]));
            ++head;
        }
        else{
            for(int i = 1; i < snake.size(); ++i){
                snake[i-1].first = snake[i].first;
                snake[i-1].second = snake[i].second;
            }
        
            snake[head].first += dy[dir];
            snake[head].second += dx[dir];
        }        
        //방향을 바꿔야 하면
        if( (chDirIdx = needDirChange(sec)) != -1){
            if(direction[chDirIdx].second == 'L')
                dir = (dir + 4-1)%4;
            else 
                dir = (dir + 4+1)%4;
        }
    }

    printf("%d", sec);
};

int main(void){

    int a, b;
    int d;
    char ch;

    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; ++i){
        scanf("%d %d", &a, &b);
        apple_coor.push_back(make_pair(a,b));
    }
    
    scanf("%d", &d);
    for(int i = 0; i<d; ++i){
        scanf("%d %c", &a, &ch);
        direction.push_back(make_pair(a, ch));
    }

    for(int i = 0; i<=n+1; ++i)
        map[0][i] = map[i][0] = map[n+1][i] = map[i][n+1] =  -1;


    snake.push_back(make_pair(1,1));
    playGame();

    return 0;
}
