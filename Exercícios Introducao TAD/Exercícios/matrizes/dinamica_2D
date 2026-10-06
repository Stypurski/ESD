#include <stdio.h>
#include <stdlib.h>

int main(){

int nLinhas = 2;
int nColunas =3;

int **m= NULL; 

m = (int **)calloc(nLinhas, sizeof(int*));
for(int i=0; i<NLinhas; i++){
    m[i]= (int *)calloc(nColuas, sizeof(int));
}

int contador =0;

printf("&m = %p, m = %p\n\n", &m, m);

for(int i=0; i< nLinhas; i++){

    printf("&m[%d] = %p, m[%d] = %p", i, &m[i], i, m[i]);

    for(int j=0; j<nColunas; j++){
        m[i][j]= contador;
        contador++;
        printf("&m[%d][%d] = %p, m[%d][%d] = %d", i, j, &m[i][j], i, j, m[i][j]);
    }
    puts("");
}

// falta desalocar, ainda nao dado

return 0;
}
