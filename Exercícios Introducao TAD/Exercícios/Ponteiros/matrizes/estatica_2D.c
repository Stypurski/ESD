#include <stdio.h>

int main(){

    int nL=2;
    int nc=3; 

    int m[nL][nc]={{0,1,2}, {3,4,5}};

    printf("&m = %p, \n m = %p\n", &m, m );

    for(int i=0; i<nL; i++){
        for(int j=0; j<nc;  j++){

            ´printf("&m[%d][%d] = %p, m[%d][%d] = %d", i, i, &m[i][j], m[i][j]);
        }
        puts("");
    }
    return 0;
}
