#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;
#define MAXN 501
#define INF 9999999

int memo[MAXN][MAXN];
vector<int> ans;

int proc(int seq[], int left, int right){

    
    if(left == right) 
        return  memo[left][right] = 0;

    if(memo[left][right] == -1){
        int sum = 0;
        memo[left][right] = INT_MAX;

        for(int i = left; i<=right; ++i)
            sum += seq[i];

        for(int i = left; i<right; ++i){
            int temp = proc(seq, left, i) + proc(seq, i+1, right) + sum;
            if(memo[left][right] > temp)
                memo[left][right] = temp;
        }
    }
    
    return memo[left][right];
}
int main(void){


    int n, t;
    int seq[MAXN];
    
    scanf("%d", &t);
    for(int i = 0; i<t; ++i){
        scanf("%d", &n);
        memset(seq, 0, sizeof(seq));
        memset(memo, -1, sizeof(memo));

        for(int j = 0; j<n; ++j){
            scanf("%d", seq+j);
        }
        ans.push_back(proc(seq, 0, n-1));
    }

    for(int i = 0; i<ans.size(); ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}
