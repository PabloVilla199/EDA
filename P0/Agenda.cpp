#include "Agenda.h"

void iniciar(agenda& a){
 a.total = 0;
}

bool anadir(agenda& a,const contacto& c){

 bool sePuede = a.total < MAX;
 if (sePuede){
    a.Agendas[a.total] = c;
    a.total++;
 }
 return sePuede;
}
bool eliminarUltimo(agenda& a){

    bool sePuede = a.total > 0;
    if(sePuede){
     a.total--;
    }
    return sePuede;
}
