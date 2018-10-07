#include <cstdio>
#include <algorithm>
#include <climits>

int MatrixChainOrder2(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    // place parenthesis at different places between first
    // and last matrix, recursively calculate count of
    // multiplications for each parenthesis placement and
    // return the minimum count
    for (k = i; k <j; k++)
    {
        count = MatrixChainOrder2(p, i, k) +
                MatrixChainOrder2(p, k+1, j) +
                p[i-1]*p[k]*p[j];
 
        if (count < min)
            min = count;
    }
 
    // Return minimum count
    return min;
}

int MatrixChainOrder(int arr[], int s, int e){

    if(e - s <= 1) return 0;

    int min = INT_MAX;
    int temp_ans;
    for(int i = s; i<e-1; ++i){

        temp_ans = MatrixChainOrder(arr, s, i+1) + MatrixChainOrder(arr, i+1, e) + arr[i+1]*arr[s]*arr[e];
        if(temp_ans < min)
            min = temp_ans;
    }

    return min;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Minimum number of multiplications is %d ",
                          MatrixChainOrder(arr, 0, n-1));
    printf("Minimum number of multiplications is %d ",
                          MatrixChainOrder2(arr, 1, n-1));
 
    getchar();
    return 0;
}
