#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 300001

pair<int, int >jewel[MAXN];
int bag[MAXN];
priority_queue<int>pq;

int main(void){

    int n, k;
    long long int ans = 0;

    scanf("%d %d", &n, &k);
    
    for(int i = 0; i<n; ++i) scanf("%d %d", &jewel[i].first, &jewel[i].second);
    for(int i = 0; i<k; ++i) scanf("%d", bag+i);

    sort(jewel, jewel+n);
    sort(bag, bag+k);

    for(int i = 0, j = 0; i<k; ++i){

        while(j<n && jewel[j].first <= bag[i]) pq.push(jewel[j++].second);
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }

    printf("%lld", ans);
    return 0;
}
