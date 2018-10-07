#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int cal[10001];
vector<pair<int, int> > candy;
vector<int> ans;

int max(int a, int b){
	return a > b ? a : b;
};

int proc(int m){
	
	cal[0] = 0;
	for(int i = 1; i<=10000; ++i){
		int maxi_cal = cal[i];
		for(int j = 0; j<(int)candy.size(); ++j){
			if(i >= candy[j].second ){
				maxi_cal = max(maxi_cal, cal[i-candy[j].second] + candy[j].first);
			}
		}
		
		cal[i] = maxi_cal;
	}
	return cal[m];
}

int main(void){

    int n,a ;
    float m, b;
    while(1){
		
		memset(cal, 0, sizeof(cal));
        scanf("%d %f", &n, &m);
        if(n == 0 && m == 0)
			break;
			
        for(int i = 0; i<n; ++i){
            scanf("%d %f", &a, &b);
			candy.push_back(make_pair(a, (int)(b*100)));
		}
	
		ans.push_back(proc((int)(m*100)));
		candy.clear();
	}

	
	for(int i = 0; i<(int)ans.size(); ++i){
		printf("%d\n", ans[i]);
	}
    return 0 ;
}
