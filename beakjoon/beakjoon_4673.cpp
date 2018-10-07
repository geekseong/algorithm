#include <cstdio>
#include <cstring>

int main(void){


    int arr[10001];
    memset(arr, -1, sizeof(arr));

    for(int i = 1; i<=10000; ++i){

        if(arr[i] == -1){
            printf("%d\n", i);
            for(int eraseNum = i; eraseNum <= 10000; ){
                int temp = eraseNum;
                int sum = 0;
                for(;temp;temp/=10){
                    sum += temp%10;
                }
                eraseNum += sum;
                if(eraseNum <= 10000){
                    arr[eraseNum] = 1;
                }
            }
        }
    }

    return 0;
}
