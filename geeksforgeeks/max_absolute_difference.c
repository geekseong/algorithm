#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 101

int ans[MAXI];

int max(int a , int b){

    return a > b ? a : b;
}
int min(int a, int b){
    return a > b ? b : a;
}

int abs(int a){

    return a < 0 ? (-1)*a : a;
}

void proc(int arr[], int n, int idx){
    
    int max_ans = -99999999;
    int left_min_sum[n];
    int left_max_sum[n];
    int right_min_sum[n];
    int right_max_sum[n];

    memset(left_min_sum, 0, sizeof(left_min_sum));
    memset(left_max_sum, 0, sizeof(left_max_sum));
    memset(right_min_sum, 0, sizeof(right_min_sum));
    memset(right_max_sum, 0, sizeof(right_max_sum));

    left_min_sum[0] = left_max_sum[0] = arr[0];
    right_min_sum[n-1] = right_max_sum[n-1] = arr[n-1];

    for(int i = 1 ; i<n; ++i){

        left_min_sum[i] = min(arr[i], left_min_sum[i-1] + arr[i]);
        left_max_sum[i] = max(arr[i], left_max_sum[i-1] + arr[i]);
        right_min_sum[n-1-i] = min(arr[n-1-i], right_min_sum[n-i] + arr[n-1-i]);
        right_max_sum[n-1-i] = max(arr[n-1-i], right_max_sum[n-i] + arr[n-1-i]);
    }

    for(int i = 0; i<n-1; ++i){
      
	int temp = max(abs(left_max_sum[i] - right_min_sum[i+1]),abs(left_min_sum[i] - right_max_sum[i+1]) );
       max_ans = max(max_ans, temp);
    }
    
    ans[idx] = max_ans;
}

int main(void){

    int testcase;
    int n;
    int arr[MAXI];

    scanf("%d", &testcase);
    for(int i = 0; i<testcase; ++i){
        
        scanf("%d", &n);
        for(int i = 0; i<n; ++i){
            scanf("%d", &arr[i]);
        }
        proc(arr, n, i);
    }
    
    for(int i = 0; i<testcase; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
