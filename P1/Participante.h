/*
* Dario Hueso 846125
* Pablo Villa 874773
*/

#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED

#include <iostream>
using namespace std;

struct participante;
void crearParticipante(string dats, participante& p);
void darDatos(const participante &p);
void actualizarAciertos(participante &p);
void actualizarFallos(participante &p);
void actualizarPasos(participante &p);
void actualizarDatos(participante &p, string dat0s);

struct participante{
    friend void crearParticipante (string dats, participante& p);
    friend void darDatos(const participante &p);
    friend void actualizarAciertos(participante &p);
    friend void actualizarFallos(participante &p);
    friend void actualizarPasos(participante &p);
    friend void actualizarDatos(participante &p, string dat0s);


  private:
    string datos;
    int aciertos;
    int fallos;
    int pasos;
};

#endif // PARTICIPANTE_H_INCLUDED
