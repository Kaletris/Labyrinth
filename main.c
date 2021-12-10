//Papp Krisztian EAYMQL

#include "string.h"
#include <stdio.h>
#include <stdbool.h>
#include "debugmalloc.h"
#include "types.h"



int main() {
    char** tabla = tabla_lefoglalas();
    Koordinata jatekos;
    jatekos.x = 7;
    jatekos.y = 1;
    tabla_inicializacio(tabla);
    tabla_kiir(tabla);

    tabla_felszabaditas(tabla);

    return 0;
}
