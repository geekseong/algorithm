#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int a, b;
int visit[101];
vector< vector<int> > rel(101);

void proc(){


    int success = 0;
    int ans = 0;
    queue<int> q;
    q.push(a);
    visit[a] = 1;
    
    while(!q.empty() && !success){

        int qsize = q.size();
        for(int i = 0 ;i<qsize; ++i){
            
            int someone = q.front();
            q.pop();
            if(someone == b){
                success = 1;
                break;
            }

            int ssize = rel[someone].size();
            for(int j = 0; j<ssize; ++j){
                if(!visit[rel[someone][j]]){
                    q.push(rel[someone][j]);
                    visit[rel[someone][j]] = 1;
                }
            }
        }
        if(!success)
            ++ans;
    }

    if(success)
        printf("%d", ans);
    else 
        printf("-1");
}
int main(void){

    int from, to;
    scanf("%d %d %d %d", &n, &a, &b, &m);
   
    for(int i = 0; i<m; ++i){
    
        scanf("%d %d", &from, &to);
        rel[from].push_back(to);
        rel[to].push_back(from);
    }
    
    proc();

    return 0;
}
