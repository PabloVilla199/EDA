#ifndef PRODUCT0_H_INCLUDED
#define PRODUCT0_H_INCLUDED
#include <iostream>
using namespace std;


struct producto;
void crear(string nom,int cant, producto& p);
string nombre(producto& p);
int cantidad(producto& p);


struct producto{

friend void crear(string nom,int cant, producto& p);
friend string nombre (const producto& p);
friend int cantidad(const producto& p);

private:
    int cantidad;
    string nombre;
};
#endif // PRODUCT0_H_INCLUDED
