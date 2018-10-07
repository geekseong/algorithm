#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<int> > g(1001);
int visit[1001];

void proc(int k){

    visit[k] = 1;
    for(int i = 0; i<g[k].size(); ++i){
        if(!visit[g[k][i]]){
            proc(g[k][i]);
        }
    }
}
int main(void){

    int ans = 0;
    int from, to;

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i<m; ++i){
        scanf("%d %d", &from, &to);
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for(int i = 1; i<=n; ++i){
        if(!visit[i]){
            ++ans;
            proc(i);
        }
    }
    printf("%d", ans);
    return 0; 
}
