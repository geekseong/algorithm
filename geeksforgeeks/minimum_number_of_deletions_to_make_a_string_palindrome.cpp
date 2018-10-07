#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int memo1[100][100];
int min(int a, int b){
    
    return a > b ? b : a;
}
int max(int a, int b){

    return a > b ? a : b;
}
int exec1(char str[], int s, int e){
    
    if(s >= e)
        return 0;
    
    if(memo1[s][e] == -1){
        int isSame = str[s] == str[e];
        int ret = 0;
        if(isSame){
            memo1[s][e] = exec1(str, s+1, e-1);
        }
        else{
            //printf("s : %d, e : %d\n", s, e);
            memo1[s][e] = min( exec1(str, s+1, e), exec1(str, s, e-1) ) +1;
        }

    }
    
    return memo1[s][e];
}
int exec2(char str[]){

    int n = (int)strlen(str);
    int memo2[100][100];
   
    //문자가 1개일 경우
    for(int i = 0; i< n; ++i){
        memo2[i][i] = 1;     
    }

    //문자열을 보는 범위를 2 ~ n 까지 늘려가면서
    for(int r = 2; r <= n; ++r){
        for(int s = 0; s< n-r+1; ++s){
            
            int e = s + r -1;
            if(str[s] == str[e] && r == 2){
                memo2[s][e] = 2;
            }
            else if(str[s] == str[e]){
                memo2[s][e] = memo2[s+1][e-1] + 2;
            }
            else{
                memo2[s][e] = max(memo2[s+1][e], memo2[s][e-1]);
            }
        }
    }
    
    return n - memo2[0][n-1];

}
int main() {
	//code
    
    char str[100];
    memset(memo1, -1, sizeof(memo1));
    scanf("%s", str);
    
    printf("exec1 : %d\n", exec1(str, 0,(int)strlen(str)-1));
    printf("exec2 : %d\n", exec2(str));


	return 0;
}
