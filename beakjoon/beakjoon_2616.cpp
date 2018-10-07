#include <cstdio>
#include <cstring>
#define MAXN 50001
int m[4][MAXN];

int max(int a , int b){
    return a > b ? a : b;
}
int main(void){


    int n, k;
    int arr[MAXN];

    scanf("%d", &n);
    for(int i = 1; i<=n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &k);

    for(int i = k; i<=n; ++i){
        int sum = 0;
        for(int j = i; j>i-k; --j)
            sum += arr[j];

        m[0][i] = sum;
    }

    for(int i = 1; i<=3; ++i){

        if(i == 1){
            int maxi = m[i-1][k];
            int temp;
            for(int j = k; j<=n; ++j){
                maxi = max(maxi, m[i-1][j]);
                m[i][j] = maxi;
            }
        }
        else{

            int maxi = m[i-1][i*k-k] + m[0][i*k];
            for(int j = i*k; j<=n; ++j){
                maxi = max(maxi, m[i-1][j-k] + m[0][j]);
                m[i][j] = maxi;
            }
        }
    }
    printf("%d", m[3][n]);
    return 0;
}
