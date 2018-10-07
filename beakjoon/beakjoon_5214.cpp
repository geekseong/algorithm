#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int n, k, m;
vector<vector<int> > graph(200001);
int visit[200002];
void print(){
	
	for(int i = 1; i<=n; ++i){
		printf("%2d", visit[i]);
	}
	printf("\n");
}
void proc(){
	
	queue<int> q;
	q.push(1);
	memset(visit, -1 ,sizeof(visit));
	
	visit[1] = 0;
	
	while(!q.empty() && !(~visit[n])){	
		int node = q.front(); q.pop();
		for(int i = 0; i<(int)graph[node].size(); ++i){
			if( !(~visit[graph[node][i]]) ){
				visit[graph[node][i]] = visit[node] + 1;
				q.push(graph[node][i]) ;
			}
		}
		print();
	}
	
	if(visit[n]  == -1)
		printf("-1");
	else
		printf("%d", visit[n]/2 + 1);

}
int main(void){

	int v;
	scanf("%d %d %d", &n, &k, &m);
	
	for(int i = 0; i<m; ++i){
		for(int j = 0; j<k; ++j){
			scanf("%d", &v);
			graph[v].push_back(100001+i);
			graph[100001+i].push_back(v);
		}
	}
	proc();
	return 0;
}
