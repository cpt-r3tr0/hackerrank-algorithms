#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

void insertionSort(int N, int * ar) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=ar[i];
        j=i-1;
        while(j>=0 && value<ar[j])
        {
            ar[j+1]=ar[j];
            j=j-1;
        }
        ar[j+1]=value;
    }
   for(j=0;j<N;j++)
        {
            printf("%d",ar[j]);
            printf(" ");
        }
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}
