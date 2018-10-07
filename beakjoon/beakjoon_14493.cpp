#include <cstdio>

int a[50001], b[50001];

int proc(int n){


    int total_time = b[0] + 1;

    for(int i = 1; i<n; ++i){

        int next = a[i] + b[i];
        while( next < total_time){
            next += a[i] + b[i];
        }
       
        if(total_time < next && next - a[i] <= total_time)
           ++total_time;
        else if(total_time == next)
            total_time += b[i] + 1;
        else
            total_time += (next -a[i] - total_time + 1);
    }

    return total_time;
}
int main(void){

    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; ++i){
        scanf("%d %d", &a[i], &b[i]);
    }


    printf("%d", proc(n));
    return 0;

}
