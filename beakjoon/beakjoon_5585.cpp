#include <cstdio>
#include <cstring>

using namespace std;


int proc(int n){

    int change = 1000 - n;
    int coin[6] = {500, 100, 50, 10, 5, 1};
    int num = 0;

    for(int i = 0; i<6; ++i){
    
        int cnt = change/coin[i];
        num+= cnt;
        change -= cnt*coin[i]; 
    
    }

    return num;
}

int main(void){

    int n;
    scanf("%d", &n);
    printf("%d", proc(n));

    return 0;
}
