#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void proc(vector<int> vec){

   unsigned long long int ans =1;
    
    sort(vec.begin(), vec.end());
    
    if(vec[0] != 1){
        printf("1");
        return ;
    }

    for(int i = 1; i<vec.size(); ++i){
        if(ans+1 >= vec[i])
            ans += vec[i];
        else
            break;
    }

    printf("%llu", ans+1);
    
}
int main(void){

    int n, a;
    vector<int> vec;
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        vec.push_back(a);
    }

    proc(vec);
    return 0;
}
