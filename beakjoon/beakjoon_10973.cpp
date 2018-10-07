#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int seq[10001];

struct greater{

    template<class T>
        bool operator()(T const &a, T const &b){
            return a > b;
        }
};

int isEnd(){

    int sorted = 1;
    for(int i = 0; i<n-1; ++i){
        if(seq[i] > seq[i+1]){
            sorted = 0;
            break;
        }
    }
    
    return sorted;
}
void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}
void proc(){

    int lastIdx = 0;
    
    //seq[i] > seq[i+1]를 만족하는 가장 마지막 i를 찾는다
    for(int i = 0; i<n-1; ++i){
        if(seq[i] > seq[i+1])
            lastIdx = i;
    }

    // seq[i]를 제외하고 seq[i+1] ~ seq[n-1] 범위에서 
    // seq[i] 보다 작은것중  가장 큰 next의 위치 idx를 구한다.
    int next = seq[lastIdx+1];
    int idx = lastIdx+1;

    for(int i = lastIdx+1; i<n; ++i){
        if(seq[lastIdx] > seq[i] && next < seq[i]){
            next = seq[i];
            idx = i;
        }
    }
    
    //위치를 바꾼다
    swap(&seq[lastIdx], &seq[idx]);

    //i+1번째 이후수들을 내림차순 sorting
    sort(seq+lastIdx+1, seq+n, greater());
    
    //출력한다.
    for(int i = 0; i<n; ++i){
        printf("%d ", seq[i]);
    }

}
void input(){

    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("\n%d", &seq[i]);
    }
}

int main(void){

    
    input();
    if(isEnd())
        printf("-1");
    else
        proc();

    return 0;
}
