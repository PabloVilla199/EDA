#include "Product0.h"

void crear(string nom, int cant , producto& p){
    p.cantidad = cant;
    p.nombre = nom;
}

string nombre(const producto& p){
    return p.nombre;
}

int cantidad(const producto& p){
    return p.cantidad;
}
