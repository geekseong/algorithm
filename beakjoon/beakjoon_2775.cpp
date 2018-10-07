#include <cstdio>
#include <vector>
using namespace std;

vector<int>ans;
int apartment[15][15];

void init(){

    for(int i = 1; i<=14; ++i){
        apartment[0][i] = i;
    }
    for(int i = 1; i<=14; ++i){
        int sum = 0;
        for(int j = 0; j<=14; ++j){
            sum += apartment[i-1][j];
            apartment[i][j] = sum;
        }
    }
}
int main(void){

    int t;
    int n, k;

    init();
    scanf("%d", &t);
    for(int i = 0; i<t; ++i){

        scanf("%d %d", &n, &k);
        ans.push_back(apartment[n][k]);
    }
    for(int i = 0; i<ans.size(); ++i){
        printf("%d\n", ans[i]);
    }

    return 0;
}

