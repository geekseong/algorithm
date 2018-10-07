#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 101

// Key Idea 
// 가장 나중에 사용이 될 놈부터 뽑는다.
void proc(vector<int>seq, int tap_num){

    int ans= 0;
    int seqLen = seq.size();
    int idx = 0;
    vector<int> cnt, tap;
    
    cnt.assign(MAXN, 0);
    tap.assign(tap_num, 0);

    //비어있는 멀티텝에 탭의 갯수 만큽 꼽는다.
    for(int i = 0; idx != tap_num && i < seq.size(); ++i){
        
        int now = seq[i];
        int flag = 0;

        for(int j = 0; j<tap_num; ++j){
            if(now == tap[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            tap[idx] = now;
            ++idx;
        }
        --cnt[now];
    }

    // 이번 에 꼽을 아이템이 탭에 꼽혀 있으면 갯수증가X
    // 만약 뽑아야 한다면 탭에 꼽혀 있는 아이템중 가장 
    // 나중에 사용 될 아이템을 선택
    for(int i = idx; i < seq.size(); ++i){
    
        int now = seq[i];
        int flag = 0;
        for(int j = 0; j<tap_num; ++j){
            if(now == tap[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){

            int plug = -1;
            int item = 0;
            for(int j = 0; j<tap_num; ++j){
                
                int last = seq.size();

                for(int k = i; k<seq.size(); ++k){
                    if(tap[j] == seq[k]){
                        last = k;
                        break;
                    }
                }
                if(plug < last){
                    plug = last;
                    item = j;
                }
            }
            ++ans;
            tap[item] = now;
        }
    }

    printf("%d", ans);
}
int main(void){


    int n, m, a;

    vector<int> seq;
    
    scanf("%d %d", &n, &m);

    for(int i = 0; i<m; ++i){
        scanf("%d", &a);
        seq.push_back(a);
    }

    proc(seq, n);

    return 0;
}
