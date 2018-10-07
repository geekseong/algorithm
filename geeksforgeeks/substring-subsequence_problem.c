#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 110
#define MAX_TESTCASE 13
int ans[MAX_TESTCASE];
int max(int a ,int b){
    return a > b ? a : b;
}
void proc(char str1[], char str2[], int idx){

    int ret;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int memo[MAX_STRING_LENGTH][MAX_STRING_LENGTH];

    if(str1[0] == str2[0]) 
        memo[0][0] = 1;
    else
        memo[0][0] = 0;

    ret = memo[0][0];
    for(int i = 1; i<len1; ++i)
        if(str1[i] == str2[0])
            memo[0][i] = 1;
        else 
            memo[0][i] = memo[0][i-1];

    for(int i = 1; i<len2; ++i){
        for(int j = 0; j<len1; ++j){
            
            if(str2[i] == str1[j]){
                if(j == 0)  memo[i][j] = 1;
                else        memo[i][j] = memo[i-1][j-1] + 1;           
            }
            else{
                if(j == 0)  memo[i][j] = 0;
                else        memo[i][j] = memo[i][j-1];
            }

            ret = max(ret, memo[i][j]);
        }
    }
    ans[idx] = ret;
}
int main(void){

    int testcase;
    char str1[MAX_STRING_LENGTH];
    char str2[MAX_STRING_LENGTH];

    scanf("%d", &testcase);
    for(int i = 0; i<testcase; ++i){

        scanf("%s %s", str1, str2);
        proc(str1, str2, i);
    }
    for(int i = 0; i<testcase; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
