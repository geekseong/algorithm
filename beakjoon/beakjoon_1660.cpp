#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define INF 99999999
vector<int> subsum;
int memo[300001];

int min(int a , int b){

    return a > b ? b : a;
}
int proc2(int n){

    if(n == 0)
        return memo[n] = 0;
    if(n == 1)
        return memo[n] = 1;

    if(memo[n] == -1){
        memo[n] = INF;
        for(int i = 0; subsum[i] <=n && i < subsum.size(); ++i){
            int temp = proc2(n-subsum[i]) + 1;
            memo[n] = min(temp, memo[n]);
        }
    }

    return memo[n];
}
int proc(int n){

    int m[300001];
    memset(m, 0, sizeof(m));

    m[0] = 0;
    m[1] = 1;

    for(int i = 2; i<=n; ++i){
        int mini = INF;
        for(int j = 0; subsum[j] <= i && j<subsum.size(); ++j){
            int temp = m[i - subsum[j]] +1;
            mini = min(temp, mini);
        }
        m[i] = mini;
    }
    return m[n];
}
int main(void){

    int n;
    int next = 1;
    int sum = 1;

    memset(memo, -1, sizeof(memo));
    
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 2;sum <=n; ++i){
        subsum.push_back(sum);
        next += i;
        sum += next;
    }
    
    printf("%d", proc(n));
    //printf("%d", proc2(n));
    return 0;
}
