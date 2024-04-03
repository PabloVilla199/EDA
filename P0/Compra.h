#ifndef COMPRA_H_INCLUDED
#define COMPRA_H_INCLUDED
#include "product0.h"

const int MAX = 40;

struct compra;
void iniciar(compra& c);
bool anadir(compra& c, const producto& p);
bool eliminarUltimo(compra& c);


struct compra {

friend void iniciar(compra& c);
friend bool anadir(compra& c, const producto& p);
friend bool eliminarUltimo(compra& c);

private:
    producto laCompra [MAX];
    int total;
};


#endif // COMPRA_H_INCLUDED
