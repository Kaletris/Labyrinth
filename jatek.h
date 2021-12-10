//
// Created by Kaletris on 2021. 12. 10..
//

#ifndef LABYRINTH_JATEK_H
#define LABYRINTH_JATEK_H

#include "types.h"
#include <stdbool.h>

char** tabla_lefoglalas();

void tabla_felszabaditas(char** tabla);

void tabla_inicializacio(char** tabla);

Koordinata tabla_jatekos_helyzete(char** tabla);

int tabla_kincsek_szama(char** tabla);

void tabla_kiir(char** tabla);

bool mehet(char** tabla, Irany irany);

Lepes tabla_jatekos_leptetes(char** tabla, Irany irany);

void iranyitas_kiiras();

#endif //LABYRINTH_JATEK_H
