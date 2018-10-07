#include <cstdio>
#include <vector>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
int memo[2001][2001];
int l_card[2001], r_card[2001];
int n;

int max(int a, int b){
    return a > b ? a : b;
}
int proc(int l, int r){

    if(l >= n || r >= n)
        return memo[l][r] = 0;
    
    if(memo[l][r] == -1){
        if( l_card[l] > r_card[r])
            memo[l][r] = max(memo[l][r], proc(l, r+1)+ r_card[r]);
        else
            memo[l][r] = max(proc(l+1, r+1),proc(l+1, r));
    }
    return memo[l][r];
}
int main(void){

    memset(memo, -1, sizeof(memo));

    scanf("%d", &n);
    for(int i = 0; i<n; ++i) 
        scanf("%d", &l_card[i]);
    for(int i = 0; i<n; ++i) 
        scanf("%d", &r_card[i]);

    printf("%d", proc(0, 0));
    return 0;
}
