#include <cstdio>
#include <cstring>

int main(void){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a+b >= 2*c){
        printf("%d", a + b - 2*c);
    }
    else
        printf("%d", a+b);
        
    return 0;
}
