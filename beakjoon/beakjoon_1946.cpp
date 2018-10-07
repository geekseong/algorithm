#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct score{
    int a, b;
}SCORE;

struct lesser{
 
    template <class T>
        bool operator()(T const &a, T const &b){
            return a.a < b.a;
        }
};

int proc(vector<SCORE> score){

    int len = (int)score.size();
    int ans = (int)score.size();
    int cur = 0;

    sort(score.begin(), score.end(), lesser());
    
    for(int i = 1; i<len; ++i)
        score[i].b > score[cur].b ? --ans : cur = i;

    return ans;
};

int main(void){

    int t;
    int a,b, m;
    vector <SCORE> score;
    vector <int> ans;

    scanf("%d", &t);
    for(int i = 0; i<t; ++i){
        
        scanf("%d", &m);
        for(int j = 0; j<m; ++j){
            scanf("%d %d", &a, &b);
            score.push_back((SCORE){a,b});
        }

        ans.push_back(proc(score));
        score.clear();
    }

    for(int i = 0; i<ans.size(); ++i){
        printf("%d\n", ans[i]);
    }
    return 0;
}
