#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

typedef struct _pair{
    int from;
    char op;
}PAIR;

PAIR value[10001];
int operD(int val){

    return (val*2)%10000;
}
int operS(int val){

    if(val == 0)
        return 9999;
    else 
        return val-1;
}
int operL(int val){

    int l = val/1000;
    int v = val%1000;

    return v*10+l;

}
int operR(int val){

    int r = val%10;
    int v = val/10;

    return r*1000 +v;
}
void init(){

    for(int i = 0; i<10001; value[i++].from = -1);
}
void proc(int from, int to){

    init();
    queue<int> q;
    q.push(from);
    value[from].from = from;
    int success = 0;

    while(!q.empty()){

        int val = q.front();
        q.pop();

        if(val == to){
            success = 1;
            break;
        }
    
        int d = operD(val);
        int s = operS(val);
        int r = operR(val);
        int l = operL(val);

        if(value[d].from == -1){
            value[d].from = val;
            value[d].op = 'D';
            q.push(d);
        }
        if(value[s].from == -1){
            value[s].from = val;
            value[s].op = 'S';
            q.push(s);
        }
        if(value[r].from == -1){
            value[r].from = val;
            value[r].op = 'R';
            q.push(r);
        }
        if(value[l].from == -1){
            value[l].from = val;
            value[l].op = 'L';
            q.push(l);
        }
    }
    
    int s = to;
    stack<char> ans_seq;
    while(s != value[s].from){
        ans_seq.push(value[s].op);
        s = value[s].from;
    }

    while(!ans_seq.empty()){
        printf("%c", ans_seq.top());
        ans_seq.pop();
    }
    printf("\n");

}

int main(void){

    int t;
    int a, b;
    scanf("%d", &t);

    for(int i = 0; i<t; ++i){
        scanf("%d %d", &a, &b);
        proc(a, b);
    }
    return 0;
}
