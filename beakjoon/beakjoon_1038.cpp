#include <cstdio>
#include <cstring>

long long int decre[1023];


long long int pow(long long int a, int n){

    if(n == 0)
        return 1;

    while(--n > 0){
        a*=10;
    }

    return a;
}
void memo(void){

    int s = 0;
    int e = 9;
    int pt =10;
    int nr = 1;
    
    for(int i = 0; i<=9; ++i)
        decre[i] = i;

    while(nr != 10){
        long long int div = pow(10, nr-1);
        for(int i = 1; i<=9; ++i){
            for(int j = s; j<=e; ++j){
                int tn = decre[j]/div;
                
                if(tn < i){
                    decre[pt++] = decre[j]+i*pow(10, nr);
                }
            }
        }

        ++nr;
        s = e+1;
        e = pt-1;
    }
}
int main(void){

    int n;
    memset(decre, -1, sizeof(decre));
    memo();
    scanf("%d", &n);
    if(n > 1022)
        printf("%d", -1);
    else
        printf("%lld", decre[n]);

    return 0;
}
