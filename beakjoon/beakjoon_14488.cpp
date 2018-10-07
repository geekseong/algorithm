#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<int> pos, speed;

int proc(double v){

    double s, e;
    int success = 1;
    s = pos[0] - v * speed[0];
    e = pos[0] + v * speed[0];

    if(s <= 0) s = 1;
    if(e > 1000000000) e = 1000000000;


    for(int i = 1; i<(int)pos.size(); ++i){

        double ts = pos[i] - v * speed[i];
        double te = pos[i] + v * speed[i];
    
        if(ts <= 0) ts = 1;
        if(te > 1000000000) te = 1000000000;
        
        if(ts <= s && te >= e){
            continue;
            //printf("1 : %lf, %lf\n", s, e);
        }
        else if(ts >= s && te <= e){
            s = ts;
            e = te;
            
            //printf("2 : %lf, %lf\n", s, e);
        }
        else if(ts < s && te >= s && te <= e){
            e = te;
            //printf("3 : %lf, %lf\n", s, e);
        }
        else if(te > e && ts >= s && ts <= e){
            s = ts;
            //printf("4 : %lf, %lf\n", s, e);
        }
        else{
            success = 0;
            break;
        }
    }

    return success;
}
int main(){

    int n;
    double v;
    int a;

    scanf("%d %lf", &n, &v);

    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        pos.push_back(a);
    }
    
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        speed.push_back(a);
    }
    
    printf("%d", proc(v));
    return 0;
}
