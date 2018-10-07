#include <cstdio>
using namespace std;

void proc(int a, int b, int c){

    int si = a;
    
    si += c/60;
    c %= 60;
    
    si += (b+c)/60;
    b = (b+c)%60;
    
    printf("%d %d\n",si%24, b);
}
int main(void){


    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    proc(a,b,c);

    return 0;
}
