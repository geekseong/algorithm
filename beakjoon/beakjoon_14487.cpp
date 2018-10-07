#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
vector<int> dist, dleft, dright;

int min(int a, int b){

    return a > b ? b : a;
}
int proc(){

    int left_min, right_min;
    int left_sum = 0, right_sum = 0;
    int n = (int)dist.size();

    for(int i = 0; i<n-1; ++i){
        left_sum += dleft[i];
    }

    left_min = left_sum;
    for(int i = 1; i<n; ++i){
        
        left_sum = left_sum - dleft[i-1] + dleft[i + n - 2];
        if(left_sum < left_min)
            left_min = left_sum;
    }
    
    for(int i = 0; i<n-1; ++i){
        right_sum += dright[i];
    }

    right_min = right_sum;
    for(int i = 1; i<n; ++i){
        
        right_sum = right_sum - dright[i-1] + dright[i + n - 2];
        if(right_sum < right_min)
            right_min = right_sum;
    }

    return min(left_min, right_min);
}

int main(void){

    int a, n;

    scanf("%d", &n);
    for(int i  =0 ; i<n; ++i){
        scanf("%d", &a);
        dist.push_back(a);
    }

    for(int i = 0; i< n + n-2; ++i){
        dleft.push_back(dist[i%n]);   
        dright.push_back(dist[(n-1) - i%n]);
    }
    
    printf("%d", proc());
    
    return 0;

}
