#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

int max(int a, int b){

    return a > b ? a :b;
}
void proc(int a, int b){


    int maxi = max(a,b);
    for(int i = 2; i<=(int)sqrt(maxi); ++i){

        int prime = 1;
        for(int j = 2; j*j <= i; ++j){
            
            if( i % j == 0){
                prime = 0;
                break;
            }
            
        }
        if(prime){
            while(a%i == 0 && b%i == 0){
                a /= i;
                b /= i;
            }
        }
    }

    printf("%d:%d", a, b);

}
int main(void){

    char ratio[32];
    int len;
    int a = 0, b = 0;
    int isLeft = 1;

    scanf("%s", ratio);
    len = (int)strlen(ratio);
    

    for(int i = 0; i<len; ++i){
        
        if(ratio[i] == ':'){
            isLeft = 0;
            continue;
        }
        if(isLeft){
            a = a*10 + ratio[i] - '0';
        }
        else{
            b = b*10 + ratio[i] - '0';
        }
    }
    
    proc(a,b);   

    return 0;
}
