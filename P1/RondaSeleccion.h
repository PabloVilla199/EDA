/*
* Dario Hueso 846125
* Pablo Villa 874773
*/


#ifndef RONDASELECCION_H_INCLUDED
#define RONDASELECCION_H_INCLUDED
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename K, typename V> struct RondaSeleccion;
template<typename K, typename V> void crear(RondaSeleccion<K,V>& c);
template<typename K, typename V> int cardinal(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool esVacia(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool pertenece(const RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> bool obtenerValor(const RondaSeleccion<K,V>& c, const K& k, V& v);
template<typename K, typename V> bool enSeleccion(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v);
template<typename K, typename V> bool quitar(RondaSeleccion<K,V>& c, const K& k);
template<typename K, typename V> void cerrarInscripcion(RondaSeleccion<K,V>& c);
template<typename K, typename V> int pasarTurno(RondaSeleccion<K,V>& c);
template<typename K, typename V> int obtenerCandidatoSuClave(RondaSeleccion<K,V>& c, K& k);
template<typename K, typename V> int obtenerCandidatoSuValor(RondaSeleccion<K,V>& c, V& v);
template<typename K, typename V> int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v);
template<typename K, typename V> int eliminarCandidato(RondaSeleccion<K,V>& c);
template<typename K, typename V> void listar(RondaSeleccion<K,V>& c);
template<typename K, typename V> void iniciarIterador(RondaSeleccion<K,V>& c);
template<typename K, typename V> bool existeSiguiente(const RondaSeleccion<K,V>& c);
template<typename K, typename V> bool siguiente(RondaSeleccion<K,V>& c, K& k, V& v);
template<typename K, typename V> bool operator == (const RondaSeleccion<K,V> &c1 , const RondaSeleccion <K,V> &c2);
template<typename K, typename V> bool operator < (const RondaSeleccion<K,V> &c1 , const RondaSeleccion <K,V> &c2);
template<typename K, typename V> void avanza(RondaSeleccion<K,V>& c);

template<typename K, typename V> struct RondaSeleccion{

    friend void crear<K,V>(RondaSeleccion<K,V>& c);
    friend int cardinal<K,V>(const RondaSeleccion<K,V>& c);
    friend bool esVacia<K,V>(const RondaSeleccion<K,V>& c);
    friend bool pertenece<K,V>(const RondaSeleccion<K,V>& c, const K& k);
    friend bool obtenerValor<K,V>(const RondaSeleccion<K,V>& c, const K& k, V& v);
    friend bool enSeleccion<K,V>(const RondaSeleccion<K,V>& c);
    friend bool anyadir<K,V>(RondaSeleccion<K,V>& c, const K& k, const V& v);
    friend bool quitar<K,V>(RondaSeleccion<K,V>& c, const K& k);
    friend void cerrarInscripcion<K,V>(RondaSeleccion<K,V>& c);
    friend int pasarTurno<K,V>(RondaSeleccion<K,V>& c);
    friend int obtenerCandidatoSuClave<K,V>(RondaSeleccion<K,V>& c, K& k);
    friend int obtenerCandidatoSuValor<K,V>(RondaSeleccion<K,V>& c, V& v);
    friend int actualizarCandidato<K,V>(RondaSeleccion<K,V>& c, const V& v);
    friend int eliminarCandidato<K,V>(RondaSeleccion<K,V>& c);
    friend void listar<K,V>(RondaSeleccion<K,V>& c);
    friend void iniciarIterador<K,V>(RondaSeleccion<K,V>& c);
    friend bool existeSiguiente<K,V>(const RondaSeleccion<K,V>& c);
    friend bool siguiente<K,V>(RondaSeleccion<K,V>& c, K& k, V& v);
    friend bool operator== (const RondaSeleccion<K,V> &c1 , const RondaSeleccion <K,V> &c2);
    friend bool operator< (const RondaSeleccion<K,V> &c1 , const RondaSeleccion <K,V> &c2);
    friend void avanza<K,V>(RondaSeleccion<K,V>& c);


private:
    struct Nodo{
        K clave;
        V valor;
        Nodo* sig;

    };
    Nodo* pri;
    Nodo* ite;
    Nodo* turno;
    int tamanio;
    bool seleccion;

};

template<typename K, typename V>
void crear(RondaSeleccion<K,V> &c) {

    c.tamanio = 0;
    c.seleccion = false;


}

template<typename K, typename V>
int cardinal(const RondaSeleccion<K,V>& c){
    return c.tamanio;

}

template<typename K, typename V>
bool esVacia(const RondaSeleccion<K,V>& c){
    return c.tamanio == 0;
}

template<typename K, typename V>
bool pertenece(const RondaSeleccion<K,V>& c, const K& k){

    typename RondaSeleccion<K,V>::Nodo* aux = c.pri;

    while (aux != nullptr) {
        if (aux->clave == k) {
            return true;
        }
        aux = aux->sig;
    }

    return false;
}

template<typename K, typename V>
 bool obtenerValor(const RondaSeleccion<K,V>& c, const K& k, V& v) {

    typename RondaSeleccion<K, V>::Nodo* actual = c.pri;
    while (actual != nullptr) {
        if (actual->clave == k) {
             v = actual->valor;
            return true;
        }
        actual = actual->sig;
    }
    return false;
}

template<typename K, typename V>
  bool enSeleccion(const RondaSeleccion<K,V>& c){
    if(c.seleccion == true){
        return true;
    }
    return false;
}

template<typename K, typename V>
bool anyadir(RondaSeleccion<K,V>& c, const K& k, const V& v) {
    if (enSeleccion(c)) return true;

    typename RondaSeleccion<K,V>::Nodo* nodo;
    typename RondaSeleccion<K,V>::Nodo* paux;

    if (c.pri == nullptr){
        c.pri = new typename RondaSeleccion<K,V>::Nodo;
        c.pri->clave = k;
        c.pri->valor = v;
        c.pri->sig = nullptr;
        c.tamanio++;

    } else if (c.pri->clave > k){
        paux = c.pri;
        c.pri = new typename RondaSeleccion<K,V>::Nodo;
        c.pri->clave = k;
        c.pri->valor = v;
        c.pri->sig = paux;
        c.tamanio++;
    }
    else if (k == c.pri->clave) {
        c.pri->valor = v;
    }
    else{
        paux = c.pri;
        while (paux->sig != nullptr && k > paux->sig->clave)
                paux = paux->sig;
                if (paux->sig != nullptr && k == paux->sig->clave) {
                    paux->sig->valor = v;
        }
        else{
            nodo = new typename RondaSeleccion<K,V>::Nodo;
            nodo->clave = k;
            nodo->valor = v;
            nodo->sig = paux->sig;
            paux->sig = nodo;
            c.tamanio++;
        }
    }
    return false;
}

template<typename K, typename V>
bool quitar(RondaSeleccion<K,V>& c, const K& k){
    if (enSeleccion(c)) return true;

    typename RondaSeleccion<K, V>::Nodo* paux1;
    typename RondaSeleccion<K, V>::Nodo* paux2;
    bool parar = false;

    if (c.pri != nullptr){
        if (c.pri->clave == k){
            paux1 = c.pri;
            c.pri = c.pri->sig;
            delete paux1;
            c.tamanio--;
            return true;
        }
        else{
            parar = false;
            paux1 = c.pri->sig;
            paux2 = c.pri;

        while (paux1 != nullptr && !parar){
            if (k < paux1->clave){
                parar = true;
            }
            else if(k == paux1->clave){
                paux2->sig = paux1->sig;
                delete paux1;
                c.tamanio--;
                return true;
            }
            else{
                paux2 = paux1;
                paux1 = paux1->sig;
            }
        }
    }
  }
  return false;
}

template<typename K, typename V>
void cerrarInscripcion(RondaSeleccion<K,V>& c){
    if (!enSeleccion(c) && !esVacia(c)) {
        c.turno = c.pri;
        c.seleccion = true;
    }
}



template<typename K, typename V>
int pasarTurno(RondaSeleccion<K,V>& c){
    if(enSeleccion(c)&& !esVacia(c)){
         if (c.turno->sig == nullptr){
             c.turno = c.pri;
        }
        else{
            c.turno = c.turno->sig;
       }
       return 1;
    }
    else{
        return 0;
    }
}


template<typename K, typename V>
 int obtenerCandidatoSuClave(RondaSeleccion<K,V>& c, K& k){
    if(enSeleccion(c)){
        k = c.turno->clave;
        return 1;
    }
    else{
       return 0;
    }
}

template<typename K, typename V>
 int obtenerCandidatoSuValor(RondaSeleccion<K,V>& c, V& v){
    if(enSeleccion(c)){
        v = c.turno->valor;
        return 1;
    }
    else{
      return 0;
    }

}

template<typename K, typename V>
int actualizarCandidato(RondaSeleccion<K,V>& c, const V& v){
    if(enSeleccion(c)||!esVacia(c)){
             c.turno->valor = v;
    }
}
 template<typename K, typename V>
int eliminarCandidato(RondaSeleccion<K, V>& c){

    typename RondaSeleccion<K, V>::Nodo* paux = c.turno;
    if (!enSeleccion(c) || esVacia(c)) {
       return -1;
    }

    if (c.turno->sig != nullptr){
        c.turno = c.turno->sig;
    }
    else{
        c.turno = c.pri;
    }

    delete paux;
    c.tamanio--;

    return 0;
}

template <typename K, typename V>
void listar(RondaSeleccion<K,V>& c){
    iniciarIterador(c);

    while(existeSiguiente(c)){
        K clave;
        V valor;

        siguiente(c, clave, valor);
        cout << "[ " << clave << "::: ";
        darDatos(valor);
        cout << "]" << endl;
    }
        cout << "[ " << c.ite->clave << "::: ";
        darDatos(c.ite->valor);
        cout << "]" << endl;
}


template<typename K, typename V>
void iniciarIterador(RondaSeleccion<K,V>& c){

    c.ite = c.pri;

}

template<typename K, typename V>
 bool existeSiguiente(const RondaSeleccion<K, V>& c){
     return c.ite->sig != nullptr;
}

template<typename K, typename V>
bool siguiente(RondaSeleccion<K,V>& c, K& k, V& v){
    if(existeSiguiente(c)){
        k = c.ite->clave;
        v = c.ite->valor;
        c.ite = c.ite->sig;
        return false;
    }
    else{
        return true;
    }

}

template<typename K, typename V>
void avanza(RondaSeleccion<K,V>& c){
    while(existeSiguiente(c)){
        c.ite = c.ite->sig;
    }

}

#endif // RONDASELECCION_H_INCLUDED
