#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int m, n, i, j, x, rings;
    long long int r, arr[300][300], p ,q, temp_r;;
    char str[10000];
    char* _p;
    scanf("%d%d%lld", &m, &n, &r);
    fgetc(stdin);

    for(i=0; i<m; i++)
        {
        fgets(str, 10000, stdin);
        for(_p=strtok(str, " "), j=0; _p!=NULL; _p=strtok(NULL, " "), j++)
            {
            arr[i][j] = atoll(_p);
        }
    }

    rings = (m<n)?m:n;
    int ring_m, ring_n;
    ring_m = m;
    ring_n = n;

    for(x=0; x<(rings/2); x++)
        {
        temp_r = r % ( ( (m-(x*2)) + (n-(x*2)) - 2 )*2 );

        while(temp_r>0)
            {
            i=j=x;
            p = arr[i][j];
            while(i<ring_m)
                {
                q = arr[i][j];
                arr[i][j] = p;
                p = q;
                i++;
            }
            i--;
            j++;
            while(j<ring_n)
                {
                q = arr[i][j];
                arr[i][j] = p;
                p = q;
                j++;
            }
            j--;
            i--;
            while(i>=x)
                {
                q = arr[i][j];
                arr[i][j] = p;
                p = q;
                i--;
            }
            i++;
            j--;
            while(j>=x)
                {
                q = arr[i][j];
                arr[i][j] = p;
                p = q;
                j--;
            }
        temp_r--;
        }
        ring_m--;
        ring_n--;
    }
    for(i=0; i<m; i++)
        {
        for(j=0; j<n; j++)
            {
            printf("%lld ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
