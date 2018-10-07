#include <cstdio>
#include <vector>
using namespace std;

int main(void){

    int t;
    int y, k,a ,b;
    int res;
    vector<int> ans;

    scanf("%d", &t);

    for(int i = 0; i<t; ++i){
        
        y = k = 0;
        for(int j = 0; j<9;++j){
            scanf("%d %d", &a, &b);
            y+=a;
            k+=b;
        }

        if(y>k)
            res = 0;
        else if(y == k)
            res == 1;
        else 
            res = 2;
        ans.push_back(res);
    }

    for(int i = 0; i<ans.size();++i){
        
        if(ans[i] == 0)
            printf("Yonsei\n");
        else if(ans[i] == 1)
            printf("Draw\n");
        else
            printf("Korea\n");
    }
}
