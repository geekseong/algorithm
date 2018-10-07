#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TESTCASE 101
#define MAX_N 51

int ans[MAX_TESTCASE];
int max(int a, int b){

    return a > b ? a : b;
}
int proc(int arr[], int n){

    int increSum[n+1];
    int decreSum[n+1];
    int ans_max = -1;
    
    for(int i = 0; i<n; ++i){
        increSum[i] = arr[i];
        for(int j= 0; j<i; ++j){
            if(arr[i] > arr[j] && increSum[i] < increSum[j] + arr[i])
                increSum[i] = increSum[j] + arr[i];
        }
    }

    for(int i = n-1; i>=0; --i){
        decreSum[i] = arr[i];
        for(int j = n-1; j>i; --j){
            if(arr[i] > arr[j] && decreSum[i] < decreSum[j] + arr[i])
                decreSum[i] = decreSum[j] + arr[i];
        }
    }

    for(int i = 0; i<n-1; ++i){
        for(int j = i+1 ; j<n; ++j){
            if(ans_max < increSum[i] + decreSum[j] && arr[i] > arr[j]){
                ans_max = increSum[i] + decreSum[j];
            }
        }
    }
    
    int t1 = max(increSum[0], decreSum[0]);
    int t2 = max(increSum[n-1], decreSum[n-1]);
    return max(ans_max, max(t1, t2));
    
}
int main(void){

    int testcase;
    int n;
    int arr[MAX_N];

    scanf("%d", &testcase);
    for(int i = 0; i<testcase; ++i){
        
        scanf("%d", &n);
        for(int j = 0; j<n; ++j)
            scanf("%d", &arr[j]);
    
        ans[i] = proc(arr, n);
    }

    for(int i = 0; i<testcase; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
