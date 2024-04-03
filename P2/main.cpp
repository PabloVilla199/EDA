#include <iostream>
#include "coleccionConMarcadeTiempo.h"
#include "PilaDinamica.h"
#include "Tiempo.h"
#include "Partcipante.h"
#include "Pregunta.h"
#include <string>

participante concursante;
ColeccionMT<int, pregunta,tiempo > c;

void introducir_pregunta();
void borrar_pregunta();
void listar_pregunta();
void listar_preguntas();
void marcar_una_pregunta_con_tiempo();
void inscribir_concursante(participante& concursante, bool& hay_concursante);
void mostrar_concursante(participante& concursante, bool& hay_concursante);
void probar_concursante(participante& concursante, bool& hay_concursante);

using namespace std;
int main() {

    setlocale(LC_ALL,"");

    bool hay_concursante = false;
    int opcion;

    do {
        cout << endl;
        cout << "MENU DE OPCIONES:" << endl;
        cout << "1. Introducir pregunta (ip)" << endl;
        cout << "2. Listar pregunta (lp)" << endl;
        cout << "3. Borrar pregunta (bp)" << endl;
        cout << "4. Listar todas las preguntas (lc)" << endl;
        cout << "5. Marcar con tiempo una pregunta (mp)" << endl;
        cout << "6. Inscribir concursante (ipa)" << endl;
        cout << "7. Mostrar concursante (lr)" << endl;
        cout << "8. Probar concursante actual (pca)" << endl;
        cout << "0. Salir" << endl;

        cout << "Introduce el n�mero de la opci�n que desea: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                introducir_pregunta ();
                break;

            case 2:
                listar_pregunta();
                break;

            case 3:
                borrar_pregunta();
                break;

            case 4:
                listar_preguntas();
                break;

            case 5:
                marcar_una_pregunta_con_tiempo();
                break;

            case 6:
                inscribir_concursante(concursante,hay_concursante);
                break;

            case 7:
                mostrar_concursante(concursante,hay_concursante);
                break;

            case 8:
                probar_concursante(concursante, hay_concursante);
                break;

            case 0:
                cout << "Saliendo del programa. �Hasta luego!" << endl;
                break;

            default:
                cout << "Opci�n no v�lida. Int�ntelo de nuevo." << endl;
        }

    } while (opcion != 0);

    return 0;
}

void introducir_pregunta(){
    int clave = 0;
    pregunta p;
    string Pregunta;
    string respuestaA;
    string respuestaB;
    int respuestaCorrecta;
    cout << "Introduce una clave: ";
    cin >> clave;
    cout << "Introduce la pregunta" << endl;
    cin.ignore();
    getline(cin,Pregunta);
    cout << "Introduce la respuesta A " << endl;
    cin >> respuestaA;
    cout << "Introduce la respuesta B " << endl;
    cin >> respuestaB;
    cout << "Introduce la respuesta correcta " << endl;
    cin >> respuestaCorrecta;
    crearPregunta(Pregunta,respuestaA,respuestaB,respuestaCorrecta,p);

    if(existeClave(c,clave)){
        cout << "La pregunta ha sido introducida anteriormente" << endl;
    }
    else{
        insertar(c, clave , p);
        if(existeClave(c,clave)){
            cout << "Pregunta introducida con �xito" << endl;
        }
        else{
            cout << "La pregunta no ha sido introducida. Insercion descartada" << endl;
        }
    }
    cout << endl;
}

void listar_pregunta() {
    int  clave = 0;
    pregunta p;
    tiempo t;

    cout << "Introduce la clave de la pregunta a listar: ";
    cin >> clave;

    if (existeClave(c, clave)) {
        obtenerDato(c, clave, p);
        obtenerTiempo(c,clave,t);
        cout << "PREGUNTA ENCONTRADA: " << clave << ":::";
        cout << "TIEMPO:";
        mostrarTiempo(t);
        cout << endl;
        mostrarPregunta(p);
    } else {
        cout << "PREGUNTA NO ENCONTRADA: " << clave << endl;
    }
}

void borrar_pregunta() {
    pregunta p;
    int clave;
    cout << "Introduce la clave de la pregunta a borrar: ";
    cin >> clave;

    if (existeClave(c, clave)) {
        obtenerDato(c, clave, p);
        mostrarPregunta(p);
        borrar(c, clave);
        if( ! existeClave(c,clave)){
           cout << "PREGUNTA BORRADA: " << endl;
        }
        else{
            cout << "PREGUNTA  NO BORRADA: " << endl;
        }
    }
    else {
        cout << "BORRADO DESCARTADO: " << clave << endl;
    }
}
void listar_preguntas(){
    cout << "Preguntas del Concurso: " << endl;
    listar(c);
}

void inscribir_concursante(participante & concursante, bool& hay_concursante){

    if(! hay_concursante){
        string nombre;
        cout << "Introduzca un nombre" << endl;
        cin >> nombre;
        crearParticipante(nombre, concursante);
        hay_concursante = true;
    }
   else {
        cout << " Ya hay un concursante inscrito" << endl;
    }

}

void mostrar_concursante(participante & concursante, bool& hay_concursante){
    if(hay_concursante){
        cout << "Informacion del participante: " << endl;
        darDatos(concursante);
        cout << endl;
    }
    else{
        cout << "No hay concursante que mostrar " << endl;
    }

}
void marcar_una_pregunta_con_tiempo(){
    int clave = 0;
    int horas = 0;
    int minutos = 0;
    tiempo t;

    cout << "Introducir una clave: " << endl;
    cin >> clave;
    if(existeClave(c,clave)){
        cout << "Introduce una hora v�lida de 0h-23h";
        cin >> horas;

        while (horas < 0 || horas > 23 ){
           cout << "Hora no v�lida" << endl;
           cout << " Introduce una hora v�lida de 0h-23h: ";
           cin >> horas;
        }
        cout << "Introduce minutos v�lidos de 0min - 59min: ";
        cin >> minutos;

        while (minutos < 0 || minutos > 59){
            cout << "Minutos no v�lidos";
            cout << "Introduce minutos v�lidos de 0min - 59min: ";
            cin >> minutos;
        }
        crearTiempo(horas,minutos,t);
         if (marcarTiempo(c, clave, t)){
            cout << "PREGUNTA MARCADA" << endl;
         }
         else{
            cout << "MARCA DESCARTADA " << endl;
         }
    }
    else{
        cout << "No existe clave " << endl;
    }
}

void probar_concursante(participante& concursante, bool& hay_concursante){
    int clave = 0;
    int hora = 0;
    int minutos = 0;
    pregunta p;
    int respuesta = 0;
    int respuestaCorrecta = 0;
    tiempo t;
    string nombre = "";


  if(hay_concursante){
        cout << "Introduce una clave: ";
        cin >> clave;
        cout << "Introduce hora de la pregunta: ";
        cin >> hora;
        cout << "Introduce minutos: ";
        cin >> minutos;
        crearTiempo(hora, minutos,t);
        marcarTiempo(c,clave,t);

        if(obtenerDato(c,clave,p)){
            obtenerTiempo(c,clave,t);
            cout << "+++ RESPONDE CONCURSANTE +++" << endl;
            cout << "CONCURSANTE: ";
            darDatos(concursante);
            cout << endl;
            cout << "PREGUNTA: ";
            mostrarPregunta(p);
            cout << endl;
            cout << "RESPUESTA DADA " << "(0, 1, o 2): ";
            cin >> respuesta;
            cout << "TIEMPO: ";
            mostrarTiempo(t);

            respuestaCorrecta = obtenerRespuestaCorrecta(p);
            if(respuesta == 0){
                actualizarPasos(concursante);
            }
            else if(respuesta == respuestaCorrecta){
                actualizarAciertos(concursante);
             }
            else{
                actualizarFallos(concursante);
            }
        }

        nombre = obtenerNombre(concursante);
        if(nombre == ""){
            cout << "CONCURSANTE ELIMINADO" << endl;
            hay_concursante = false;
        }
  }
        else{
            cout << " Debes crear un concursante primero" << endl;

        }
}
