//MATRIZES DINAMICAS 2D

for(int i=0; i<nLinhas; i++){
    free(m[i]);
}
free(m);
m = NULL;

//MATRIZES DINAMICAS 3D

for(int i=0; i<nFatias; i++){
    for(int j=0; j<nLinhas; j++){
        free(m[i][j]);
    }
    free(m[i]);
}

free(m);
m= NULL;
