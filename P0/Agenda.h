#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED


#include "Contacto.h"

const int MAX = 40;

struct agenda;
void iniciar(agenda& a);
bool anadir(agenda& a, const contacto& c);
bool eliminarUltimo(agenda& a);


struct agenda {

friend void iniciar(agenda& a);
friend bool anadir(agenda& a, const contacto& c);
friend bool eliminarUltimo(agenda& a);

private:
    contacto Agendas [MAX];
    int total;
};
#endif // AGENDA_H_INCLUDED
