#include <stdio.h>

int isEqualarray(int* x, int* y, int n);
void printResult(int result);

int main(void)
{
    int a[] = {4, 7, 9, 3, 6};
    int b[] = {4, 7, 9, 3, 6};
    int c[] = {10, 20, 30, 40, 50};
    int d[] = {4, 7, 9, 3, 9};
    int e[] = {4, 7, 9, 3, 9};

    printResult (isEqualarray(a,b,5));
    printResult (isEqualarray(a,c,5));
    printResult (isEqualarray(b,d,5));
    printResult (isEqualarray(b,d,5));

    return 0;
}

int isEqualarray(int* x, int* y, int n){
    int i = 0;
    int cnt = 0;

    for(i = 0; i < n; i++){
        if(x[i] == y[i])
        cnt = cnt + 1;
    }
    if(cnt == n)
        return 1;
    else
        return 0;
}