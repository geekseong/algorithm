#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

void proc(vector<int>check, int a, int b){

    int n = a;
    int p = b;
    int cnt = 1;
    int ans = 1;
    int c;
    while( !check[n] ){
        check[n] = cnt++;
        n = (n*n)%p;
    }
    c = n;
    
    if(n == (n*n)%p) printf("1");
    else{
        for(c = (c*c)%p; c != n; ++ans, c = (c*c)%p);
        printf("%d", ans + 1);
    }
}
int main(void){

    int a, b;
    vector<int> check;
    check.assign(1000001, 0); 

    scanf("%d %d", &a, &b);

    proc(check, a, b);
    return 0;
}
