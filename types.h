//
// Created by Kaletris on 2021. 12. 10..
//

#ifndef LABYRINTH_TYPES_H
#define LABYRINTH_TYPES_H

#include "econio.h"

typedef struct Koordinata{
    int x;
    int y;
}Koordinata;

typedef enum Irany{
    fel = KEY_UP,
    balra = KEY_LEFT,
    le = KEY_DOWN,
    jobbra = KEY_RIGHT
}Irany;

typedef enum Lepes{
    fal,
    kijarat,
    kincs,
    ures
}Lepes;

#endif //LABYRINTH_TYPES_H
