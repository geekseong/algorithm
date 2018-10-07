#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int max(int a, int b){

    return a > b ? a : b;
}
int proc(int n){

    int maxi = n;
    int cur = n;

    while(cur > 1){

        if(cur%2)
            cur = cur*3 + 1;
        else
            cur/=2;

        maxi = max(maxi, cur);
    }

    return maxi;
}
int main(void){

    int n;
    vector<int> input;
    scanf("%d", &n);
    input.assign(n, 0);

    for(int i = 0; i<n; ++i)
        scanf("%d", &input[i]);
    
    for(int i = 0; i<n; ++i)
        printf("%d\n", proc(input[i]));
    return 0;
}
