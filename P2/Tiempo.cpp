#include "Tiempo.h"
#include <iostream>
#include <iomanip>
using namespace std;

void crearTiempo(int horas, int minutos, tiempo &t) {
    t.horas = horas;
    t.minutos = minutos;
}

void mostrarTiempo(const tiempo &t) {
    cout << setfill('0') << setw(2) << t.horas << ":" << setw(2) << t.minutos << setfill(' ') << endl;
}
