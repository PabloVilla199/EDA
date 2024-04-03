#ifndef PREGUNTA_H_INCLUDED
#define PREGUNTA_H_INCLUDED

#include <iostream>
#include "Tiempo.h"
#include <string>
using namespace std;

struct pregunta;
void crearPregunta(string& Pregunta,string& opcionRespuesta1,  string& opcionRespuesta2, int& opcionRespuestaCorrecta, pregunta &p);
void mostrarPregunta(const pregunta &p);
int obtenerRespuestaCorrecta(const pregunta& p);

struct pregunta{

 friend void crearPregunta(string& Pregunta,string& opcionRespuesta1, string& opcionRespuesta2, int& opcionRespuestaCorrecta, pregunta &p);
 friend void mostrarPregunta(const pregunta &p);
 friend int obtenerRespuestaCorrecta(const pregunta& p);

 private:
    string Pregunta;
    string opcionRespuesta1;
    string opcionRespuesta2;
    int opcionRespuestaCorrecta;
    tiempo marcaTiempo;
};

#endif // PREGUNTA_H_INCLUDED
