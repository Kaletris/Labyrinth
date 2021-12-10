//
// Created by Kaletris on 2021. 12. 10..
//

#ifndef LABYRINTH_TYPES_H
#define LABYRINTH_TYPES_H

typedef struct Koordinata{
    int x;
    int y;
}Koordinata;

typedef enum Irany{
    fel = 'w',
    balra = 'a',
    le = 's',
    jobbra = 'd'
}Irany;

typedef enum Lepes{
    fal,
    kijarat,
    kincs,
    ures
}Lepes;

#endif //LABYRINTH_TYPES_H
