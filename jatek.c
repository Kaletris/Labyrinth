//
// Created by Kaletris on 2021. 12. 10..
//

#include "jatek.h"
#include <stdio.h>
#include "debugmalloc.h"
#include <string.h>
#include "types.h"
#include <stdbool.h>

char** tabla_lefoglalas(){
    //10sor
    char** tabla = (char**) malloc(sizeof(char*)*10);
    for (int i = 0; i < 10; ++i) {
        //10+1 oszlop ('\0')
        tabla[i] = (char*) malloc(sizeof(char)*11);
    }
    return tabla;
}

void tabla_felszabaditas(char** tabla){
    for (int i = 0; i < 10; ++i) {
        free(tabla[i]);
    }
    free(tabla);
}

void tabla_inicializacio(char** tabla){
    strcpy(tabla[0], "###### ###\0");
    strcpy(tabla[1], "#$   #   #\0");
    strcpy(tabla[2], "#### ### #\0");
    strcpy(tabla[3], "#        #\0");
    strcpy(tabla[4], "# #### ###\0");
    strcpy(tabla[5], "# #    #$#\0");
    strcpy(tabla[6], "# ##$# # #\0");
    strcpy(tabla[7], "#@ ### # #\0");
    strcpy(tabla[8], "#   $#   #\0");
    strcpy(tabla[9], "##########\0");
}

Koordinata tabla_jatekos_helyzete(char** tabla){
    Koordinata jatekos;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(tabla[i][j] == '@'){
                jatekos.x = i;
                jatekos.y = j;
                return jatekos;
            }
        }
    }
}

int tabla_kincsek_szama(char** tabla){
    int kincsekSzama = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(tabla[i][j] == '$'){
                kincsekSzama++;
            }
        }
    }
    return kincsekSzama;
}

void tabla_kiir(char** tabla){
    for (int i = 0; i < 10; ++i) {
        printf("%s\n", tabla[i]);
    }
}

bool mehet(char** tabla, Irany irany){
    Koordinata jatekos = tabla_jatekos_helyzete(tabla);
    switch (irany) {
        case fel:
            if(tabla[jatekos.x-1][jatekos.y] == '#'){
                return false;
            }
            return true;
        case le:
            if(tabla[jatekos.x+1][jatekos.y] == '#'){
                return false;
            }
            return true;
        case balra:
            if(tabla[jatekos.x][jatekos.y-1] == '#'){
                return false;
            }
            return true;
        case jobbra:
            if(tabla[jatekos.x][jatekos.y+1] == '#'){
                return false;
            }
            return true;
        default:
            return false;
    }
}

Lepes tabla_jatekos_leptetes(char** tabla, Irany irany){
    Koordinata jatekos = tabla_jatekos_helyzete(tabla);
    int x = jatekos.x;
    int y = jatekos.y;
    if(!mehet(tabla, irany)){
        return fal;
    }
    switch (irany) {
        case fel:
            tabla[x][y] = ' ';
            tabla[--x][y] = '@';
            break;
        case le:
            tabla[x][y] = ' ';
            tabla[++x][y] = '@';
            break;
        case balra:
            tabla[x][y] = ' ';
            tabla[x][--y] = '@';
            break;
        case jobbra:
            tabla[x][y] = ' ';
            tabla[x][++y] = '@';
            break;
        default:
            break;
    }

    if(x == 0 || x == 9 || y == 0 || y == 9){
        return kijarat;
    }

    if (tabla[x][y] == '$'){
        return kincs;
    }
    return ures;
}
