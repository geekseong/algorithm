#include <cstdio>
#include <algorithm>
using namespace std;

struct greater{

    template<class T>
    bool operator()( T const &a, T const &b){
        return a > b;
    }
};

void swap(int *a, int *b){

    int temp  = *a;
    *a = *b;
    *b = temp;
}

void proc(int n){

    int arr[11];
    int num = n;
    int len = 0;

    for(int i = 0; num > 0; num/=10, ++i ){
        ++len;
        arr[i] = num%10;
    }

    sort(arr, arr+len, greater());

    for(int i = 0; i<len; ++i)
        printf("%d", arr[i]);
}

int main(void){

    int n;
    scanf("%d", &n);
    proc(n);

    return 0;
}
