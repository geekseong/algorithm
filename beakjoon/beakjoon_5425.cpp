#include <cstdio>
#include <vector>
using namespace std;

long long int proc(int a, int b){

    long long int  sum = 0;
    for(long long int i = a; i<=b;++i){
        long long int k = i;
        while(k){
            sum+= k%10;
            k/=10;
        }
    }

    return sum;
}
int main(void){

    int t;
    long long int a, b;
    vector<long long int> ans;

    scanf("%d", &t);
    for(int i = 0; i < t ; ++i){

        scanf("%lld %lld", &a, &b);
        ans.push_back(proc(a, b));    
    }

    for(int i = 0; i<t; ++i){
        printf("%lld\n", ans[i]);
    }

}
