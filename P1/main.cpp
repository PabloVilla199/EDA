/*
* Dario Hueso 846125
* Pablo Villa 874773
*/

    #include <iostream>
    #include <sstream>
    #include "Participante.h"
    #include "rondaSeleccion.h"

    using namespace std;

    RondaSeleccion<string,participante> c;

    void inscripcion();
    void borrar ();
    void mostrar();
    void cerrar();
    void obtener();
    void descartar();
    void actualizar();
    void pasar();
    void listarRondaSeleccion();
    void mostrarNombre(const string& nombre);

    int main(){
        crear(c);

        char opcion;

        while(opcion != 'S'){
            cout << endl;
            cout << "Opciones ronda seleccion" << endl;
            cout << "1.- Inscribir participante" << endl;
            cout << "2.- Borrar participante" << endl;
            cout << "3.- Mostrar participante" << endl;
            cout << "4.- Cerrar inscripcion" << endl;
            cout << "5.- Obtener candidato" << endl;
            cout << "6.- Descartar candidato" << endl;
            cout << "7.- Actualizar candidato" << endl;
            cout << "8.- Pasar turno" << endl;
            cout << "9.- Listar ronda" << endl;
            cout << "S.- Salir" << endl;
            cout << endl;

            cin >> opcion;

            switch(opcion){
                case '1':
                    inscripcion();
                    break;

                case '2':
                    borrar();
                    break;

                case '3':
                    mostrar();
                    break;

                case '4':
                    cerrar();
                    break;

                case '5':
                    obtener();
                    break;

                case '6':
                    descartar();
                    break;

                case '7':
                    actualizar();
                    break;

                case '8':
                    pasar();
                    break;

                case '9':
                    listarRondaSeleccion();
                    break;

                case 'S':
                    return 0;
                    break;

                default:
                    cout << "Opcion erronea" << endl;
                    break;
            }
        }
    }

    void inscripcion(){
        string alias;
        string datos;
        participante p;

        cout << "Introducir alias " << endl;
        cin >> alias;
        fflush(stdin);
        cout << "Datos" << endl;
        cin >> datos;
        fflush(stdin);

        crearParticipante(datos,p);

        if(pertenece(c, alias)){
            anyadir(c, alias, p);

            cout << "Participante actualizado" << endl;
        }
        else{
            anyadir(c, alias, p);

            cout << "Participante inscrito" << endl;
        }
    }

    void borrar(){
        string alias;

        cout << "Introducir alias:" << endl;
        cin >> alias;

        if(pertenece(c,alias)){
            quitar(c, alias);

            cout << "Participante: ";
            cout << alias << endl;
            cout << " borrado" << endl;
        }
        else{
            cout << "Participante desconocido" << endl;
        }
    }

    void mostrar(){
        string alias;
        participante s;

        cout << "Introducir alias" << endl;
        cin >> alias;

        if(pertenece(c, alias)){
            if(obtenerValor(c, alias, s)){
                cout << "PARTICIPANTE: " << alias << endl;
                cout << "INFO:"<< endl;
                darDatos(s);
            }
            else{
                cout << "Error al obtener participante" << endl;
            }
        }
        else{
            cout << "Participante desconocido" << endl;
        }
    }

    void cerrar(){

        if(!enSeleccion(c)){
            cerrarInscripcion(c);
            cout << "Inscripcion cerrada con " << cardinal(c)
                 << " participantes" << endl;
        }
        else{
            cout << "No ha sido posible cerrar el proceso de inscripcion" << endl;
        }
    }

    void obtener(){
        participante a;

        if(enSeleccion(c)){
            if(esVacia(c)){
                cout << "Ronda vacia" << endl;
            }
            else{
                obtenerCandidatoSuValor(c, a);
                cout << "Candidato a evaluar: " << endl;
                 darDatos(a);
            }
        }
        else{
            cout << "Consulta candidato descartada" << endl;
        }
    }

    void descartar(){
        participante a;

        if(enSeleccion(c)){
            if(esVacia(c)){
                cout << "Ronda vacia" << endl;
            }
            else{
                obtenerCandidatoSuValor(c, a);
                eliminarCandidato(c);

                cout << "Candidato eliminado: " << endl;
                darDatos(a);
            }
        }
        else{
            cout << "Eliminacion candidato descartada" << endl;
        }
    }

    void actualizar(){
        participante a;
        char opcion;

        if(enSeleccion(c)){
            if(esVacia(c)){
                cout << "Ronda vacia" << endl;
            }
            else{
                obtenerCandidatoSuValor(c, a);

                cout << "Fallo (F), acierto (A) o pasa (P):" << endl;
                cin >> opcion;

                switch(toupper(opcion)){
                    case 'F':
                        actualizarFallos(a);
                         actualizarCandidato(c, a);
                        cout << "Candidato actualizado: " <<  endl;
                        darDatos(a);
                        break;

                    case 'A':
                        actualizarAciertos(a);
                         actualizarCandidato(c, a);
                        cout << "Candidato actualizado: " << endl;
                        darDatos(a);

                        break;

                    case 'P':
                        actualizarPasos(a);
                         actualizarCandidato(c, a);
                        cout << "Candidato actualizado: " << endl;
                        darDatos(a);

                        break;

                    default:
                        cout << "Opcion erronea" << endl;
                        break;
                }
            }
        }
        else{
            cout << "Actualizacion candidato descartada" << endl;
        }
    }

    void pasar(){
        participante a;
        int error;

        if(enSeleccion(c)){
            if(esVacia(c)){
                cout << "Ronda vacia" << endl;
            }
            else{
                error = pasarTurno(c);

                if(error == 1){
                    obtenerCandidatoSuValor(c, a);

                    cout << "Turno en concursante: " << endl;
                    darDatos(a);
                }
                else{
                    cout << "Error al pasar turno" << endl;
                }
            }
        }
        else{
            cout << "El concurso no esta en modo juego" << endl;
        }
    }

    void listarRondaSeleccion(){
        participante p;
        int num;

       if(enSeleccion(c)){
          cout << "*** Ronda en fase seleccion" << endl;
          cout << "Total: ";
          num = cardinal(c);
          cout << num << endl;
          if(!esVacia(c)){
             listar(c);
             cout << "Turno en candidato: ";
             obtenerCandidatoSuValor(c, p);
             darDatos(p);
          }
          cout << endl << "**" << endl << endl;
       } else{
          cout << "*** Ronda en fase inscripcion" << endl;
          cout << "Total: ";
          num = cardinal(c);
          cout << num << endl;
          if(esVacia(c) == false){
             listar(c);
          }
          cout << "***" << endl << endl;
       }
    }
    void mostrarNombre(const string& nombre) {
        cout << "Nombre: " << nombre;
    }

