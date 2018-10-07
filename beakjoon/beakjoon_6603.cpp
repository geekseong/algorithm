#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<vector<int> > seq(10000);
void print(int set[]){

    for(int i = 0; i<6; ++i){
        printf("%d ", set[i]);
    }
    printf("\n");

}
void proc(int set[], int set_idx, int idx, int size, int left, int t){


    //printf("set_idx%d idx%d size%d left%d t%d\n", set_idx, idx, size, left, t);
    if(left == 0){
        print(set);
        return ;
    }

    int lim = (size-idx) - left;

    if(lim == 0 ){
        set[set_idx] = seq[t][idx];
        proc(set, set_idx+1, idx+1, size, left-1, t);
    }
    else{
        set[set_idx] = seq[t][idx];
        proc(set, set_idx+1, idx+1, size, left-1, t);
        proc(set, set_idx, idx+1, size, left, t);
    }
}
int main(void){

    int t =0;
    int a;
    int set[13];

    while(1){

        scanf("%d", &n);
        if(n == 0 )
            break;

        for(int i = 0 ; i<n; ++i){
            scanf("%d", &a);
            seq[t].push_back(a);
        }
        ++t;
    }
    for(int i = 0; i<t; ++i){
        proc(set, 0, 0, seq[i].size(), 6, i);
        printf("\n");
    }
    return 0;
}
