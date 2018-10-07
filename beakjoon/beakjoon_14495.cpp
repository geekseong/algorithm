#include <cstdio>

int main(void){

    int n;
    int f[200];
    
    scanf("%d", &n);
    f[0] = f[1] = f[2] = 1;

    for(int i = 3; i<n; ++i){
        f[i] = f[i-1] + f[i-3];
    }   

    printf("%d", f[n-1]);
    
    return 0;

}
