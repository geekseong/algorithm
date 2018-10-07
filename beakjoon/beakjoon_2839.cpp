#include <cstdio>
#include <cstring>
#include <climits>
#define MAXN 5001

int min(int a, int b){
    return a > b ? b :a;
}
int proc(int n){

    int arr[MAXN];
    memset(arr, -1, sizeof(arr));
    arr[3] = arr[5] = 1;

    for(int i = 6; i<=n; ++i){
        int _3kg;
        int _5kg;
        if(arr[i-3] != -1) _3kg = arr[i-3] + 1;
        else _3kg = INT_MAX;

        if(arr[i-5] != -1) _5kg = arr[i-5] + 1;
        else _5kg = INT_MAX;

        if(_3kg == INT_MAX && _5kg == INT_MAX)
            arr[i] = -1;
        else
            arr[i] = min(_3kg, _5kg);
    }
    
    return arr[n];
}
int main(void){

    int n;
    
    scanf("%d", &n);
    printf("%d", proc(n));

    return 0;
}
