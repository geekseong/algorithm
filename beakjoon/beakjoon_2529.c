#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10

int max_ans[MAXN];
int min_ans[MAXN];
char inequ[MAXN];

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}
int check(int set[], int n){

    int s = set[0];
    for(int i = 0; i<n-1; ++i){
        if(inequ[i] == '>'){
            if(s > set[i+1])
                s = set[i+1];
            else
                return 0;
        }
        else{
            if(s < set[i+1])
                s = set[i+1];
            else 
                return 0;
        }
    }
    return 1;
}
int isMax(int set[], int n){

    for(int i = 0; i<n; ++i){
        if(max_ans[i] != set[i]){
            if(max_ans[i] > set[i])
                return 0;
            else
                return 1; 
        }
    }

    return 0;
}

int isMin(int set[], int n){

    for(int i = 0; i<n; ++i){
        if(min_ans[i] != set[i]){
            if(min_ans[i] < set[i])
                return 0;
            else
                return 1; 
        }
    }
    return 0;
}
void renewal(int set[], int n, int flag){
    
    for(int i = 0; i<n; ++i){
        if(!flag)
            max_ans[i] = set[i];
        else
            min_ans[i] = set[i];
    }

}
void proc(int set[], int n, int idx, int flag){

    if(n == idx){
        if(!flag){
            if(check(set, n) && isMax(set, n)){
                renewal(set, n, flag);
            }
        }
        else{
            if(check(set, n) && isMin(set, n)){
                renewal(set, n, flag);
            }
        }
        return ;
    }
    if(!flag){
        for(int i = 0; i<=idx; ++i){
            if(set[i] < max_ans[i])
                return ;
        }
    }
    if(flag){
        for(int i = 0; i<=idx; ++i){
            if(set[i] > min_ans[i])
                return ;
        }
    }

    for(int i = idx; i<n; ++i){
        swap(&set[i], &set[idx]);
        proc(set, n, idx+1, flag);
        swap(&set[i], &set[idx]);
    }
}
int main(void){

    int n;
    int max_arr[MAXN];
    int min_arr[MAXN];

    scanf("%d",&n);
   
    for(int i = 0; i<n; ++i)
        scanf("\n%c", &inequ[i]);
    for(int i = MAXN; i>=MAXN-n; --i){
        max_arr[MAXN-i] = i-1;
        min_arr[MAXN-i] = MAXN-i;
    }
    for(int i = 0; i<MAXN;++i){
        max_ans[i] = 0;
        min_ans[i] = 9;
    }
    proc(max_arr, n+1, 0, 0);
    proc(min_arr, n+1, 0, 1);
    
    for(int i = 0; i<=n; ++i)
        printf("%d", max_ans[i]);
    printf("\n");
    for(int i = 0; i<=n; ++i)
        printf("%d", min_ans[i]);
    return 0;
}
