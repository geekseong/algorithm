#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_STR_LEN 51

int min(int a, int b){

    return a < b ? a : b;
};

int proc(char A[], char B[]){

    int ans = 99999;
    int aLen = strlen(A);
    int bLen = strlen(B);
    int len = bLen- aLen;

    for(int i = 0; i<= len; ++i){
        int diff = 0; 
        for(int j = 0; j<=aLen; ++j){
            if(A[j] != B[i+j]){
                ++diff;
            }
        }
        ans = min(ans, diff);
    }

    return ans;
};
int main(void){

    char A[MAX_STR_LEN];
    char B[MAX_STR_LEN];

    scanf("%s %s", A,B);

    printf("%d", proc(A,B));
    return 0;
}
