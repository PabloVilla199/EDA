#include "Compra.h"

void iniciar(compra& c){
 c.total = 0;
}

bool anadir(compra& c ,const producto& p){

 bool sePuede = c.total < MAX;
 if (sePuede){
    c.laCompra[c.total] = p;
    c.total++;
 }
 return sePuede;
}
bool eliminarUltimo(compra& c){

    bool sePuede = c.total > 0;
    if(sePuede){
     c.total--;
    }
    return sePuede;
}
