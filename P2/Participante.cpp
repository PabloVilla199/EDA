/*
* Dario Hueso 846125
* Pablo Villa 874773
*/

#include "Partcipante.h"
#include <iostream>
#include <string>

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
    if(p.fallos > 2){
        crearParticipante("", p);
    }
}

void actualizarPasos(participante &p){
    p.pasos++;
    if(p.pasos > 1){
        crearParticipante("",p);

    }
}

string obtenerNombre(participante& p){

 return(p.datos);

}

