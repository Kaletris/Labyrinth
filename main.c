#include "debugmalloc.h"
#include "string.h"
#include <stdio.h>

char** tabla_lefoglalas(){
    char** tabla = (char**) malloc(sizeof(char*)*10);
    for (int i = 0; i < 10; ++i) {
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

void tabla_kiir(char** tabla){
    for (int i = 0; i < 10; ++i) {
        printf("%s\n", tabla[i]);
    }
}

int main() {
    char** tabla = tabla_lefoglalas();
    tabla_inicializacio(tabla);
    tabla_kiir(tabla);

    tabla_felszabaditas(tabla);

    return 0;
}
