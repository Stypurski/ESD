#include <stdio.h>
#include <stdlib.h>

int main(){

    int nFatias= 2;
    int nLinhas =2;
    int nColunas = 3;


    int ***m = NULL;

    m = (int ***)calloc(2, sizeof(int**));

    for(int i=0; i<nFatias; i++){
        m[i] = (int**)calloc(nLinhas, sizeof(int*));
        for(int j=0; j<nLinhas; j++){
            m[i][j] = (*int)calloc(nColunas, sizeof(int));
        }
    }



    int cont = 0;

    for(int i =0; i<2; i++){
        printf("&m[%d] = %p, m[%d] = %p", i, &m[i], i, m[i]);

        for(int j =0; j<2; j++){
            printf("&m[%d][%d] = %p, m[%d][%d] = %p", i, j, &m[i][j], i, j, m[i][j]);

            for(int k =0; k<3; k++){
                m[i][j][k] = cont;
                cont++;
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d", i, j, k, &m[i][j][k], i, j, k, m[i][j][k]);
            }
            puts("");
        }
        puts("");
    }
    return;
}
