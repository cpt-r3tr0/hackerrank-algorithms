#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000
char str[MAXN];
char res[MAXN][MAXN];

int row,col;

int main(){
   scanf("%s",str);
   int len = strlen(str); int DIFF = 1<<20; int AREA = 1<<20;
   for(int i=1; i<=100; ++i) {
     if(i*i>=len) {
         row = i; col = i; break;
     }
     if(i*(i+1)>=len){
         row = i; col = i+1; break;
     }
   }
   int id = 0;
   for(int i=0; i<MAXN; ++i) for(int j=0; j<MAXN; ++j) res[i][j] = '\0';
   for(int i=0; i<row; ++i) for(int j=0; j<col; ++j) res[i][j] = str[id++];
   for(int i=0; i<col; ++i) {
      for(int j=0; res[j][i]!='\0'; ++j) printf("%c",res[j][i]);
      printf(" ");
   }

   return 0;
}
