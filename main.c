//Papp Krisztian EAYMQL

#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "types.h"
#include "jatek.h"
#include "econio.h"

int main() {
    char** tabla = tabla_lefoglalas();
    Koordinata jatekos;
    jatekos.x = 7;
    jatekos.y = 1;
    tabla_inicializacio(tabla);
    bool jatekVege = false;
    econio_rawmode();
    int lenyomott;
    Lepes lepes;
    econio_clrscr();
    tabla_kiir(tabla);
    while (!jatekVege){
        lenyomott = econio_getch();
        switch (lenyomott) {
            case fel:
                lepes = tabla_jatekos_leptetes(tabla, fel);
                break;
            case le:
                lepes =tabla_jatekos_leptetes(tabla, le);
                break;
            case balra:
                lepes =tabla_jatekos_leptetes(tabla, balra);
                break;
            case jobbra:
                lepes =tabla_jatekos_leptetes(tabla, jobbra);
                break;
            default:
                break;
        }
        econio_clrscr();
        switch (lepes) {
            case ures:
                tabla_kiir(tabla);
                break;
            case kincs:
                tabla_kiir(tabla);
                printf("\n\nKincset talaltal!\n\n");
                break;
            case fal:
                tabla_kiir(tabla);
                printf("\n\nFalba nem lehet lepni!\n\n");
                break;
            case kijarat:
                if(tabla_kincsek_szama(tabla) == 0){
                    tabla_kiir(tabla);
                    printf("\n\nNyertel!\n\n");
                    jatekVege = true;
                } else {
                    tabla_kiir(tabla);
                    printf("\n\nVesztettel!\n\n");
                    jatekVege = true;
                }
                break;
            default:
                tabla_kiir(tabla);
                break;
        }
    }
    printf("\n\nKilepeshez nyomj meg egy billentyut!\n");
    econio_getch();
    econio_normalmode();

    tabla_felszabaditas(tabla);

    return 0;
}
