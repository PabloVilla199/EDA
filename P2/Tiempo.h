#ifndef TIEMPO_H_INCLUDED
#define TIEMPO_H_INCLUDED


#include <iostream>
#include <iomanip>
using namespace std;

struct tiempo;

void crearTiempo(int horas, int minutos, tiempo &t);
void mostrarTiempo(const tiempo &t);

struct tiempo {
    friend void crearTiempo(int horas, int minutos, tiempo &t);
    friend void mostrarTiempo(const tiempo &t);

  private:
    int horas;
    int minutos;
};

#endif // TIEMPO_H_INCLUDED


