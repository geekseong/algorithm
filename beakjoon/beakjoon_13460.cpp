#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct _coor{
	int ry;
	int rx;
	int by;
	int bx;
}COOR;

char map[10][10];
int ay, ax;

COOR moveLeft(COOR ball){
	
	int ry = ball.ry;
	int rx = ball.rx;
	int by = ball.by;
	int bx = ball.bx;
	
	while(map[ry][rx-1] == '.' && ry != by && rx-1 != bx){
		rx-=1;
		if(ry == ay && rx == ax){
			break;
		}
	}
	while(map[by][bx-1] == '.' && ry != by && rx != bx-1){
		bx-=1;
		if(by == ay && bx == ax){
			break;
		}
	}
	
	return (COOR){ry, rx, by, bx};
}
COOR moveRight(COOR ball){
	
	int ry = ball.ry;
	int rx = ball.rx;
	int by = ball.by;
	int bx = ball.bx;
	
	while(map[ry][rx+1] == '.'&& ry != by && rx+1 != bx){
		rx+=1;
		if(ry == ay && rx == ax){
			break;
		}
	}
	while(map[by][bx+1] == '.'&& ry != by && rx != bx+1){
		bx+=1;
		if(by == ay && bx == ax){
			break;
		}
	}
	
	return (COOR){ry, rx, by, bx};
	
};

COOR moveDown(COOR ball){
	
	int ry = ball.ry;
	int rx = ball.rx;
	int by = ball.by;
	int bx = ball.bx;
	
	while(map[ry+1][rx] == '.' && ry+1 != by && rx != bx){
		ry+=1;
		if(ry == ay && rx == ax){
			break;
		}
	}
	while(map[by+1][bx-1] == '.' && ry != by+1 && rx != bx){
		by+=1;
		if(by == ay && bx == ax){
			break;
		}
	}
	
	return (COOR){ry, rx, by, bx};
}
COOR moveUp(COOR ball){

	int ry = ball.ry;
	int rx = ball.rx;
	int by = ball.by;
	int bx = ball.bx;
	
	while(map[ry-1][rx] == '.' && ry-1 != by && rx != bx){
		ry-=1;
		if(ry == ay && rx == ax){
			break;
		}
	}
	while(map[by-1][bx] == '.' && ry != by-1 && rx != bx){
		by-=1;
		if(by == ay && bx == ax){
			break;
		}
	}
	
	return (COOR){ry, rx, by, bx};
}
int isSuccess(COOR ball){

	if(ball.by == ay && ball.bx == ax)
		return -1;
	if(ball.ry == ay && ball.rx == ax && ball.ry != ball.by && ball.rx != ball.bx)
		return 1;
	else 
		return 0;
}
void proc(int ry, int rx, int by, int bx){

	queue<COOR> q;
	q.push((COOR){ry, rx, by, bx});
	int step = -1;
	int success = 0;
	int suc;
	while(!q.empty() && !success){
		++step;
		
		int qsize = (int)q.size();
		for(int i = 0 ;i<qsize; ++i){
			COOR cur = q.front();
			q.pop();
			
			if(step >10)
				break;
			suc = isSuccess(cur);
			if( suc == 1){
				success = 1;
				break;
			}
			else if(suc == -1){
				continue;
			}
			
			q.push(moveLeft(cur));
			q.push(moveRight(cur));
			q.push(moveDown(cur));
			q.push(moveUp(cur));
		}
	}
	
	if(success) printf("%d", step);
	else printf("-1");
}
int main(void){
	
	int n, m;
	int ry, rx, by, bx;
	
	scanf("%d %d", &n, &m);
	for(int i = 0; i<n; ++i){
		for(int j = 0 ; j<m; ++j){
			scanf("\n%1c", &map[i][j]);
			if(map[i][j] == 'B'){
				by = i; 
				bx = j;
			}
			if(map[i][j] == 'R'){
				ry = i;
				rx = j;
			}
			if(map[i][j] == 'O'){
				ay = i; 
				ax = j;
				map[i][j] ='.';
			}
		}
	}
	
	proc(ry, rx, by, bx);
	return 0;
}
