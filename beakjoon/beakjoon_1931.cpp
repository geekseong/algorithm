#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct meeting{

    int start;
    int end;

}meeting;
struct lesser{

    template <class T>
    bool operator()(T const &a, T const &b){
        return a.start < b.start;        
    }
};

int proc(vector<meeting> m){

    int ans = 1;
    int last = 0;
    int len = (int)m.size();
    
    for(int i = 1 ; i<len; ++i){
        
        if(m[last].end <= m[i].start){
            ans++;
            last = i;
        }
        else{
            if(m[last].end > m[i].end)
                last = i;
        }
    }

    return ans;
}
int main(void){

    vector<meeting> meeting_list;
    int n,a,b;

    scanf("%d", &n);
    for(int i = 0 ; i<n; ++i){
        scanf("%d %d", &a, &b);
        meeting_list.push_back((meeting){a, b});
    }
    
    sort(meeting_list.begin(), meeting_list.end(), lesser());
    printf("%d",proc(meeting_list));

    return 0;
}
