#ifndef RESERVA_H
#define RESERVA_H

#include "Data.h"

typedef struct reserva tReserva;

tReserva* res_cria(const char* hospede, int quarto, float diaria, tData* dt_checkin, tData* dt_checkout);

void res_libera(tReserva* r);
int res_calculaDiarias(tReserva* r);
float res_calculaValorTotal(tReserva* r);

void res_exibe(tReserva* r);

#endif