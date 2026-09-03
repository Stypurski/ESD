#include <stdio.h>
#include <stdlib.h>
#include "Data.h"

typedef struct {
    int dia;
    int mes; 
    int ano;
    } DataSimples;
        typedef struct {
        char descricao[50];
        float valor_original;
        DataSimples dt_vencimento;
        DataSimples dt_pagamento;
    } tConta;

int main() {
// Declaração das 7 contas
tConta c1 = {"Conta de Luz", 200.0, {20, 9, 2026}, {5, 9, 2026}}; // 15 dias antes (Desconto 10%)
tConta c2 = {"Internet", 100.0, {15, 9, 2026}, {15, 9, 2026}}; // No dia (Valor normal)
tConta c3 = {"Cartao Credito", 500.0, {10, 9, 2026}, {15, 9, 2026}}; // 5 dias de atraso (Juros)
tConta c4 = {"Condominio", 800.0, {10, 10, 2026}, {1, 10, 2026}}; // 9 dias antes (Sem desconto)
tConta c5 = {"Plano de Saude", 350.0, {30, 9, 2026}, {20, 9, 2026}}; // 10 dias antes (Desconto 10%)
tConta c6 = {"IPVA", 1200.0, {05, 8, 2026}, {25, 8, 2026}}; // 20 dias de atraso (Juros)
tConta c7 = {"Academia", 120.0, {01, 9, 2026}, {01, 9, 2026}}; // No dia (Valor normal)

// Vetor de ponteiros para struct tConta preenchido
tConta* contas[7] = {&c1, &c2, &c3, &c4, &c5, &c6, &c7};

int total_contas = 7;

for(int i=0; i<total_contas;i++){

   tData *dtVencimento = dta_cria(
            contas[i]->dt_vencimento.dia,
            contas[i]->dt_vencimento.mes,
            contas[i]->dt_vencimento.ano
        );

        tData *dtPagamento = dta_cria(
            contas[i]->dt_pagamento.dia,
            contas[i]->dt_pagamento.mes,
            contas[i]->dt_pagamento.ano
        );

        int diferenca = dta_diferenca(dtPagamento, dtVencimento);

        float valorFinal = contas[i]->valor_original;

        if(diferenca >= 10){
        valorFinal = contas[i]->valor_original * 0.90;
        }else 
        if(diferenca >= 0){
         valorFinal = contas[i]->valor_original;

        }else{
            int diasAtraso = diferenca * -1;
            valorFinal = contas[i]->valor_original + (contas[i]->valor_original *0.001 * diasAtraso);

        }

        printf("Descricao: %s\n", contas[i]->descricao);

        printf("Data de vencimento: ");
        dta_exibe(dtVencimento);

        printf("Data de pagamento: ");
        dta_exibe(dtPagamento);

        printf("Valor original: R$%.2f\n", contas[i]->valor_original);

        printf("Valor final: R$%.2f\n", valorFinal);

        dta_libera(dtVencimento);
        dta_libera(dtPagamento);
    }

return 0;

}