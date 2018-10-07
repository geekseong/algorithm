#include <cstdio>
#include <vector>

using namespace std;

void proc(vector<int> info){

    int len = (int)info.size();
    vector<int> check;
    check.assign(len, 0);

    for(int i = 0; i< len; ++i){

        int cnt = 0;
        for(int j = 0; j<len; ++j){
            if(cnt == info[i]){
		        int k = j;
                for(k = j; k<len && check[k]; ++k);
	 	        check[k] = i+1;      
                break;
            }
            if(!check[j]) 
                cnt++;
        }
    }

    for(int i = 0; i<len; ++i)
        printf("%d ", check[i]);
};

int main(void){

    int n, a;
    vector<int> info;

    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        info.push_back(a);
    }

    proc(info);
    return 0;
}
