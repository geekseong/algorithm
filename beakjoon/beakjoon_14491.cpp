#include <cstdio>
#include <cstring>

void proc(int n){

    if(n <= 0){
        return ;
    }

    proc(n/9);
    printf("%d", n%9);
}
int main(void){

    int n;
    scanf("%d", &n);
    proc(n);
}
