#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

typedef struct {
    char modulo[50];
    int horas_estimadas;
    tData* dt_prazo;
    tData* dt_entrega;
} tEntregavel;

tEntregavel* criar_entregavel(const char* mod, int horas, tData* dt_prazo, tData* dt_entrega) {

    tEntregavel* e = (tEntregavel*) malloc(sizeof(tEntregavel));

    sprintf(e->modulo, "%s", mod);

    e->horas_estimadas = horas;

    e->dt_prazo = dt_prazo;
    e->dt_entrega = dt_entrega;

    return e;
}

int main() {

    tEntregavel* projeto[6];

    projeto[0] = criar_entregavel("Modulo de Autenticacao", 40, dta_cria(15, 10, 2026), dta_cria(5, 10, 2026));
    projeto[1] = criar_entregavel("API de Pagamentos", 80, dta_cria(20, 10, 2026), dta_cria(20, 10, 2026));
    projeto[2] = criar_entregavel("Relatorios em PDF", 30, dta_cria(10, 10, 2026), dta_cria(14, 10, 2026));
    projeto[3] = criar_entregavel("Dashboard Analytics", 60, dta_cria(25, 10, 2026), dta_cria(22, 10, 2026));
    projeto[4] = criar_entregavel("Modulo de Notificacao", 20, dta_cria(5, 10, 2026), dta_cria(30, 9, 2026));
    projeto[5] = criar_entregavel("Integracao Gateway", 50, dta_cria(1, 11, 2026), dta_cria(15, 11, 2026));

    int total_entregaveis = 6;

    for(int i = 0; i < total_entregaveis; i++){

        int diferenca = dta_diferenca(
            projeto[i]->dt_entrega,
            projeto[i]->dt_prazo
        );

        float pontuacao = projeto[i]->horas_estimadas;

        if(diferenca <= -5){
            pontuacao = projeto[i]->horas_estimadas * 1.20;

            }else if(diferenca <= 0){
                pontuacao = projeto[i]->horas_estimadas;

                }else{
                    pontuacao = projeto[i]->horas_estimadas - (projeto[i]->horas_estimadas * 0.05 * diferenca);
                     if(pontuacao < 0){
                        pontuacao = 0;
                    }
            }

        printf("Modulo: %s\n", projeto[i]->modulo);
        printf("Data do prazo: ");
        dta_exibe(projeto[i]->dt_prazo);

        printf("Data da entrega: ");
        dta_exibe(projeto[i]->dt_entrega);

        if(diferenca < 0){
           printf("Dias de antecedencia: %d\n", diferenca * -1);
            }else if(diferenca == 0){
                printf("Entrega no dia do prazo.\n");
                }else{
                    printf("Dias de atraso: %d\n", diferenca);
                }

        printf("Horas estimadas: %d\n", projeto[i]->horas_estimadas);
        printf("Pontuacao final: %.2f\n", pontuacao);
    }

    for(int i = 0; i < total_entregaveis; i++){

        dta_libera(projeto[i]->dt_prazo);
        dta_libera(projeto[i]->dt_entrega);
        free(projeto[i]);
    }

    return 0;
}