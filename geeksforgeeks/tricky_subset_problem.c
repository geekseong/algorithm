#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TESTCASE 11
#define MAX_N 100001

int proc(long long int arr[], long long int s, long long int n, long long int x){
    

    long long int a[MAX_N];
    long long int b[MAX_N];

    a[0] = b[0] = s;
    
    for(int i = 1; i<=n; ++i){
        a[i] = b[i-1] + arr[i-1];
        b[i] = b[i-1] + a[i];
    }

    long long int sum = 0;
    int sp = 0;
    int is_exist = 0;
    for(int i = 0; i<=n; ++i){
        
        if(sum + a[i] > x){
            sum -= a[sp++];
            --i;
            if(sp > i){
                is_exist = 0;
                break;
            }
        }
        else{
            sum += a[i];
            if(sum == x){
                is_exist = 1;
                break;
            }
        }
    }
    
    return is_exist;
}

int main(void){

    int t;
    long long int s, n, x;
    long long int arr[MAX_N];
    int ans[MAX_N];

    scanf("%d", &t);
    for(int i = 0; i<t; ++i){
    
        scanf("%lld %lld %lld", &s, &n, &x);
        for(int j = 0; j<n; ++j)
            scanf("%lld", &arr[j]);    
        
        ans[i] = proc(arr, s, n, x);
    }

    for(int i = 0 ;i<t; ++i){
        if(ans[i]) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
