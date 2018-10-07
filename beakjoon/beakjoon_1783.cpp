#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int min(int a, int b){
    return a > b ?  b  :a;
}
void proc(int n, int m){

    if(n == 1)
        printf("1");
    
    else if(n == 2){
        printf("%d", min(4, (m+1)/2));
    }
    else{
        if(m<7)
            printf("%d", min(4, m));
        else
            printf("%d", m-2);
    }
}
int main(void){


    int n, m;
    scanf("%d %d", &n, &m);
    proc(n, m);

    return 0;
}
