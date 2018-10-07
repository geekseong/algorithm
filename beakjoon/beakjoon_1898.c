#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 110
int map[MAXI][MAXI];
long long int memo[MAXI][MAXI];
int inside(int x, int y, int n){

    if( x<0 || x >=n || y < 0 || y >= n)
        return 0;
    else 
        return 1;
}
long long int proc(int x, int y, int n){

    static int visited[MAXI][MAXI]; 
    
    if(x == n-1 && y == n-1)
        return memo[y][x] = 1;

    if( memo[y][x] == 0){
        int jump = map[y][x];
        
        if( inside(x+jump, y, n) && !visited[y][x+jump]){ 
            visited[y][x+jump] = 1;
            memo[y][x] += proc(x+jump, y, n);
            visited[y][x+jump] = 0;
        }
        if( inside(x, y+jump, n) && !visited[y+jump][x]){
            visited[y+jump][x] = 1;
            memo[y][x] += proc(x, y+jump, n);
            visited[y+jump][x] = 0;
        }
    }

    return memo[y][x];
}
int main(void){

    int n;
    scanf("%d", &n);
    for(int i =0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            scanf("%d", &map[i][j]);
        }
    }

    printf("%llu",proc(0, 0, n));
}
