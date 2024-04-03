/*
* Dario Hueso 846125
* Pablo Villa 874773
*/

#include "Participante.h"
#include <iostream>

void crearParticipante(string dats, participante& p){
    p.datos = dats;
    p.pasos = 0;
    p.fallos = 0;
    p.aciertos = 0;
}

void darDatos(const participante &p){

    cout << " OK: " << p.aciertos <<  "||F: " << p.fallos <<  "||P: " << p.pasos << "||DATOS: " << p.datos;
}

void actualizarAciertos(participante &p){
    p.aciertos++;
}

void actualizarFallos(participante &p){
    p.fallos++;
}

void actualizarPasos(participante &p){
    p.pasos++;
}

void actualizarDatos(participante &p, string dat0s){
    p.datos =  dat0s;
}

