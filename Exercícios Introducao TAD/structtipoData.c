#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

typedef struct {
    char descricao[50];
    float valor_original;
    tData* dt_vencimento;
    tData* dt_pagamento;
} tConta;


tConta* criar_conta(const char* desc, float valor, int diaV, int mesV, int anoV, int diaP, int mesP, int anoP) {

    tConta* c = (tConta*) malloc(sizeof(tConta));

    sprintf(c->descricao, "%s", desc);

    c->valor_original = valor;

    c->dt_vencimento = dta_cria(diaV, mesV, anoV);
    c->dt_pagamento = dta_cria(diaP, mesP, anoP);

    return c;
}

int main() {

    tConta* contas[7];

    contas[0] = criar_conta("Conta de Luz", 200.0, 20, 9, 2026, 5, 9, 2026);
    contas[1] = criar_conta("Internet", 100.0, 15, 9, 2026, 15, 9, 2026);
    contas[2] = criar_conta("Cartao Credito", 500.0, 10, 9, 2026, 15, 9, 2026);
    contas[3] = criar_conta("Condominio", 800.0, 10, 10, 2026, 1, 10, 2026);
    contas[4] = criar_conta("Plano de Saude", 350.0, 30, 9, 2026, 20, 9, 2026);
    contas[5] = criar_conta("IPVA", 1200.0, 5, 8, 2026, 25, 8, 2026);
    contas[6] = criar_conta("Academia", 120.0, 1, 9, 2026, 1, 9, 2026);

    int total_contas = 7;

    for(int i = 0; i < total_contas; i++){

        int diferenca = dta_diferenca( contas[i]->dt_pagamento, contas[i]->dt_vencimento);

        float valorFinal = contas[i]->valor_original;

        if(diferenca >= 10){
           valorFinal = contas[i]->valor_original * 0.90;
            }else if(diferenca >= 0){
                valorFinal = contas[i]->valor_original;
                }else{
                int diasAtraso = diferenca * -1;
                valorFinal = contas[i]->valor_original +
                (contas[i]->valor_original * 0.001 * diasAtraso);
                }

        printf("Descricao: %s\n", contas[i]->descricao);

        printf("Data de vencimento: ");
        dta_exibe(contas[i]->dt_vencimento);

        printf("Data de pagamento: ");
        dta_exibe(contas[i]->dt_pagamento);

        printf("Valor original: R$ %.2f\n", contas[i]->valor_original);

        printf("Valor final: R$ %.2f\n", valorFinal);
    }

    for(int i = 0; i < total_contas; i++){

        dta_libera(contas[i]->dt_vencimento);
        dta_libera(contas[i]->dt_pagamento);
        free(contas[i]);
    }

    return 0;
}