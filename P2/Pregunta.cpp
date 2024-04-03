#include "Pregunta.h"
#include <iostream>

void crearPregunta(string& Pregunta, string& opcionRespuesta1,  string& opcionRespuesta2,  int& opcionRespuestaCorrecta, pregunta &p) {
    p.Pregunta = Pregunta;
    p.opcionRespuesta1 = opcionRespuesta1;
    p.opcionRespuesta2 = opcionRespuesta2;
    p.opcionRespuestaCorrecta = opcionRespuestaCorrecta;
}

void mostrarPregunta(const pregunta &p) {
    cout << "Pregunta: " << p.Pregunta << endl;
    cout << "Opción A: " << p.opcionRespuesta1 << endl;
    cout << "Opción B: " << p.opcionRespuesta2 << endl;
    cout << "Respuesta Correcta: " << p.opcionRespuestaCorrecta << endl;

}
int obtenerRespuestaCorrecta(const pregunta& p){
    return(p.opcionRespuestaCorrecta);
}
