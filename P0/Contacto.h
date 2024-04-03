// Contacto.h

#ifndef CONTACTO_H_INCLUDED
#define CONTACTO_H_INCLUDED

#include <iostream>
using namespace std;

struct contacto; // Declaración anticipada

void crear(string nom, int tlfo, contacto& c);
string nombres(const contacto& c);
int telefono(const contacto& c);

struct contacto {
    friend void crear(string nom, int tlfo, contacto& c);
    friend string nombres(const contacto& c);
    friend int telefono(const contacto& c);

private:
    string nombre;
    int telefono;
};

#endif
