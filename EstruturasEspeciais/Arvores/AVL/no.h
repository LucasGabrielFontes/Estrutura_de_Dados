#ifndef NO_H
#define NO_H

struct no {
    struct no *esq;
    int info;
    struct no *dir;
};

#endif 