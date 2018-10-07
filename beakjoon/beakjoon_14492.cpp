#include <cstdio>

int m1[301][301], m2[301][301];

int proc(int n){


    int sum = 0;

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            
            int a = 0;
            for(int k = 0; k<3; ++k){
                a += (m1[i][k] * m2[k][j]);
            }
            if(a)
                ++sum;
        }
    }

    return sum;
}
int main(void){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            scanf("%d", &m1[i][j]);
        }
    }
    
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            scanf("%d", &m2[i][j]);
        }
    }

    printf("%d", proc(n));
    return 0;
}
