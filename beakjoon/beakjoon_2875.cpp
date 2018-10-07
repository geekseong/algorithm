#include <cstdio>
#include <vector>

int max(int a , int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a <= b ? a : b;
}
int main(void){

    int n, m, k;
    int ans = 0;
    
    scanf("%d %d %d", &n,&m,&k);

    for(int i = 0; i<=k; ++i){
	int temp = 0;
        if(m >=i && n >= (k-i)){
            int men = m-i;
            int women = n-(k-i);
            temp = min(women/2, men);
        }
        ans = max(ans, temp);
    }
    printf("%d", ans);

    return 0;

}
