#include <stdio.h>
#include <stdlib.h>
#include "Reserva.h"

struct reserva {
    char hospede[50];
    int quarto;
    float diaria;
    tData* dt_checkin;
    tData* dt_checkout;
};

tReserva* res_cria(const char* hospede, int quarto, float diaria,
                   tData* dt_checkin, tData* dt_checkout) {

    tReserva* r = (tReserva*) malloc(sizeof(tReserva));

    sprintf(r->hospede, "%s", hospede);
    r->quarto = quarto;
    r->diaria = diaria;
    r->dt_checkin = dt_checkin;
    r->dt_checkout = dt_checkout;

    return r;
}

void res_libera(tReserva* r) {

    dta_libera(r->dt_checkin);
    dta_libera(r->dt_checkout);

    free(r);
}

int res_calculaDiarias(tReserva* r) {

    return dta_diferenca(r->dt_checkout, r->dt_checkin);
}

float res_calculaValorTotal(tReserva* r) {

    return res_calculaDiarias(r) * r->diaria;
}

void res_exibe(tReserva* r) {

    printf("Hospede: %s\n", r->hospede);
    printf("Quarto: %d\n", r->quarto);

    printf("Check-in: ");
    dta_exibe(r->dt_checkin);

    printf("Check-out: ");
    dta_exibe(r->dt_checkout);

    printf("Diarias: %d\n", res_calculaDiarias(r));
    printf("Valor total: R$ %.2f\n", res_calculaValorTotal(r));
}