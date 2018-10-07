#include <cstdio>
#include <cstring>
#include <vector>
#define MAXN 100001
using namespace std;

int min(int a, int b){

    return a > b ? b :a;
}

int main(void){

    int n,s;
    int arr[MAXN][4];
    int m[MAXN][4];

    vector<int> ans;
    
    while(1){
        s = 2;
        memset(arr, 0, sizeof(arr));
        memset(m, 0, sizeof(m));

        scanf("%d", &n);
        if(n == 0)
            break;

        for(int i = 1; i<=n; ++i)
            scanf("%d %d %d", &arr[i][1], &arr[i][2], &arr[i][3]);

        for(int i = 1; i<=3; ++i)
            m[1][i] = arr[1][i] ;
        if(m[1][3] < 0){
            m[1][3] += m[1][2];
            s = 3;
        }
        for(int i = 2; i<=n; ++i){
            if(i == 2){
                
                m[i][1] = m[i-1][2] + arr[i][1];

                if(s == 2){
                    m[i][2] = min(m[i-1][2], m[i][1]) + arr[i][2];
                    m[i][3] = m[i-1][2] + arr[i][3];
                }
                else{

                    m[i][2] = min(m[i-1][3], m[i][1]) + arr[i][2];
                    m[i][3] = min(m[i-1][3], m[i][2]) + arr[i][3];
                }

                continue;
            }

            for(int j = 1; j<=3; ++j){
                if(j == 1){
                    m[i][j] = min(m[i-1][j], m[i-1][j+1]) + arr[i][j]; 
                }
                if(j == 2){
                    int m1 = min(m[i-1][j-1], m[i-1][j]);
                    int m2 = min(m[i-1][j+1], m[i][j-1]);
                    m[i][j] = min(m1, m2) + arr[i][j];
                }
                if(j == 3){
                    m[i][j] = min(min(m[i-1][j], m[i-1][j-1]),m[i][j-1]) + arr[i][j];
                }
            }
               
        }
        
        ans.push_back(m[n][2]);

    }
    for(int i = 0; i<ans.size(); ++i){
        printf("%d. %d\n",i+1, ans[i]);
    }
}
