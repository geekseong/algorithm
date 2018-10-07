#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int mdx[4] = {0, 1, 0, -1};
int mdy[4] = {-1, 0, 1, 0};
int map[201][201];
int w, h, k;
int visit[201][201][31];

typedef struct _move{
    int pos;
    int left;
}MOVE;

int inside(int y, int x){

    return (y>=0 && y<h && x>=0 && x<w);
}
void proc(){

    int step = 0;
    int success = 0;
    queue<MOVE> q;
    q.push((MOVE){0, k});
    visit[0][0][k] = 1;

    
    if(w == 1 && h == 1){
        if(!map[0][0]){
            success = 1;
            q.pop();
        }   
        else{
            q.pop();
        }
    }
    
    while(!q.empty()){

        int qsize = q.size();
        vector<MOVE> store;
        while(qsize--){
           store.push_back(q.front());
           q.pop();
        }
        
        
        for(int i = 0; i<store.size(); ++i){
            MOVE c = store[i];
            int y = c.pos/200;
            int x = c.pos%200;
            int left = c.left;
            if(y == h-1 && x == w-1){
                success = 1;
                break;
            }
            //원숭이 움직임
            for(int j = 0; j<4; ++j){
                int yy = y + mdy[j];
                int xx = x + mdx[j];
                
                if(inside(yy,xx) && !visit[yy][xx][left] && map[yy][xx] == 0){
                    
                    visit[yy][xx][left] = 1;
                    q.push((MOVE){yy*200 + xx, left});
                }
            }
            //말 움직임
            if(left){
                for(int j = 0; j<8; ++j){
                    int yy = y + hdy[j];
                    int xx = x + hdx[j];
                
                    if(inside(yy,xx) && !visit[yy][xx][left-1] && !map[yy][xx]){
                        visit[yy][xx][left-1] = 1;
                        q.push((MOVE){yy*200+xx, left-1});
                    }
                }
            }
        }
        if(success) break;
        ++step;
    }

    if(success)
        printf("%d", step);
    else 
        printf("-1");
    
}


int main(void){

    scanf("%d %d %d", &k, &w, &h);

    for(int i = 0; i<h; ++i){
        for(int j = 0; j<w; ++j){
            scanf("\n%d", &map[i][j]);
        }
    }
    proc();

    return 0;
}
