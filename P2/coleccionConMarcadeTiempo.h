#ifndef COLECCIONCONMARCATIEMPO_H_INCLUDED
#define COLECCIONCONMARCATIEMPO_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>
#include "PilaDinamica.h"

using namespace std;

template<typename K, typename V, typename T> struct ColeccionMT;
template<typename K, typename V, typename T> void crear(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool esVacia(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool existeClave(const ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> void insertar(ColeccionMT<K,V,T>& c, const K& k, const V& v);
template<typename K, typename V, typename T> bool tieneTiempo(const ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> bool obtenerDato(const ColeccionMT<K,V,T>& c, const K& k, V& v);
template<typename K, typename V, typename T> void obtenerTiempo(const ColeccionMT<K,V,T>& c, const K& k, T& t);
template<typename K, typename V, typename T> bool marcarTiempo(ColeccionMT<K,V,T>& c, const K& k, const T& t);
template<typename K, typename V, typename T> void borrar(ColeccionMT<K,V,T>& c, const K& k);
template<typename K, typename V, typename T> int tamanyo(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> void vaciar(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> string listar(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> void iniciarIterador(ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool existeSiguiente(const ColeccionMT<K,V,T>& c);
template<typename K, typename V, typename T> bool siguiente(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool&tienemarca);
template<typename K, typename V, typename T> void insertarRec(typename ColeccionMT<K,V,T>::Nodo*& nodo, const K& k, const V& v, bool& metido);
template<typename K, typename V, typename T> typename ColeccionMT<K,V,T>::Nodo* buscarNodo(typename ColeccionMT<K,V,T>::Nodo* nodo, const K& k);
template<typename K, typename V, typename T> void borrarRec(typename ColeccionMT<K,V,T>::Nodo*& nodo, const K& k, bool& borrado);
template<typename K, typename V, typename T> void borrarMaximo(typename ColeccionMT<K,V,T>::Nodo*& nodo, K& k, V& v, T& t);

template<typename K, typename V,typename T> bool operator == (const ColeccionMT<K,V,T> &c1 , const ColeccionMT <K,V,T> &c2);
template<typename K, typename V, typename T> bool operator < (const ColeccionMT<K,V,T> &c1 , const ColeccionMT <K,V,T> &c2);


template<typename K, typename V, typename T> struct ColeccionMT{

    friend void crear <K,V,T>(ColeccionMT<K,V,T>& c);
    friend bool esVacia <K,V,T>(const ColeccionMT<K,V,T>& c);
    friend bool existeClave <K,V,T>(const ColeccionMT<K,V,T>& c, const K& k);
    friend void insertar <K,V,T>(ColeccionMT<K,V,T>& c, const K& k, const V& v);
    friend bool tieneTiempo <K,V,T>(const ColeccionMT<K,V,T>& c, const K& k);
    friend bool obtenerDato <K,V,T>(const ColeccionMT<K,V,T>& c, const K& k, V& v);
    friend void obtenerTiempo <K,V,T>(const ColeccionMT<K,V,T>& c, const K& k, T& t);
    friend bool marcarTiempo <K,V,T>(ColeccionMT<K,V,T>& c, const K& k, const T& t);
    friend void borrar <K,V,T>(ColeccionMT<K,V,T>& c, const K& k);
    friend int tamanyo <K,V,T>(const ColeccionMT<K,V,T>& c);
    friend void vaciar <K,V, T>(ColeccionMT<K,V,T>& c);
    friend string listar <K,V,T>(ColeccionMT<K,V,T>& c);
    friend void iniciarIterador <K,V,T>(ColeccionMT<K,V,T>& c);
    friend bool existeSiguiente <K,V,T>(const ColeccionMT<K,V,T>& c);
    friend bool siguiente <K,V,T>(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool&tienemarca);


    private:
        struct Nodo{
            K clave;
            V valor;
            T tiempo;
            bool tieneMarca;
            Nodo* izqda;
            Nodo* drcha;
        };

        Nodo* pri;
        PilaDinamica <ColeccionMT<K,V,T>::Nodo*> d;
        int tamanio;

    friend void insertarRec <K,V,T>(typename ColeccionMT<K,V,T>::Nodo*& nodo,const K& k, const V& v, bool& metido);
    friend Nodo* buscarNodo <K,V,T>(typename ColeccionMT<K,V,T>::Nodo* nodo, const K& k);
    friend void borrarRec <K,V,T>(typename ColeccionMT<K,V,T>::Nodo*& nodo, const K& k, bool& borrado);
    friend void borrarMaximo <K,V,T>(typename ColeccionMT<K,V,T>::Nodo*& nodo, K& k, V& v, T& t);


};

template<typename K, typename V, typename T>
typename ColeccionMT<K, V, T>::Nodo* buscarNodo(typename ColeccionMT<K, V, T>::Nodo* nodo, const K& k) {
    if (nodo != nullptr) {
        if (k < nodo->clave) {return buscarNodo<K, V, T>(nodo->izqda, k);}
        if (k > nodo->clave) {return buscarNodo<K, V, T>(nodo->drcha, k);}
        if (k == nodo->clave) {return nodo;}
    }
}


template<typename K, typename V, typename T>
void crear(ColeccionMT<K,V,T>& c){
    c.tamanio = 0;
    c.pri = nullptr;
}

template<typename K, typename V , typename T>
bool esVacia(const ColeccionMT<K,V,T>& c){
    return c.pri == nullptr;
}

template<typename K, typename V, typename T>
bool existeClave(const ColeccionMT<K,V,T>& c, const K& k){
    typename ColeccionMT<K,V,T>::Nodo* nodo;
    nodo = buscarNodo<K,V,T>(c.pri, k);
    return nodo != nullptr;
}

template<typename K, typename V, typename T>
void insertar(ColeccionMT<K,V,T>& c, const K& k, const V& v){
    bool metido = false;
    insertarRec<K,V,T>(c.pri, k, v, metido);
    if(metido) c.tamanio++;
}

template<typename K, typename V, typename T>
bool tieneTiempo(const ColeccionMT<K,V,T>& c, const K& k){
    typename ColeccionMT<K,V,T>::Nodo* nodo;

    if(existeClave(c,k)){
        nodo = buscarNodo<K,V,T>(c.pri, k);
        if(nodo->tieneMarca){
            return true;
        }
    }
    return false;
}

template<typename K, typename V, typename T>
bool obtenerDato (const ColeccionMT<K,V,T>& c, const K& k, V& v){
    typename ColeccionMT<K,V,T>::Nodo* nodo;
    nodo = buscarNodo<K,V,T>(c.pri, k);
    if(nodo != nullptr){
        v = nodo->valor;
        return true;
    }
    return false;
}

template<typename K, typename V, typename T>
void obtenerTiempo(const ColeccionMT<K,V,T>& c, const K& k, T& t){
    typename ColeccionMT<K,V,T>::Nodo* nodo;
    nodo = buscarNodo<K,V,T>(c.pri, k);
    if(nodo != nullptr && tieneTiempo(c, k)){
        t = nodo->tiempo;
    }
}

template<typename K, typename V, typename T>
bool marcarTiempo(ColeccionMT<K,V,T>& c, const K& k, const T& t){
    typename ColeccionMT<K,V,T>::Nodo* nodo;
    nodo = buscarNodo<K,V,T>(c.pri, k);
    if(nodo != nullptr){
        nodo->tiempo = t;
        return true;
    }
    return false;
}

template<typename K, typename V, typename T>
void borrar(ColeccionMT<K,V,T>& c, const K& k){
    bool borrado = false;
    borrarRec<K,V,T>(c.pri, k, borrado);
    if(borrado){
        c.tamanio--;
    }
}

template<typename K, typename V, typename T>
int tamanyo(const ColeccionMT<K,V,T>& c){
    return c.tamanio;
}

template<typename K, typename V, typename T>
void vaciar(ColeccionMT<K,V,T>& c){
    iniciarIterador(c);
    while (c.pri != nullptr) {
        typename ColeccionMT<K,V,T>::Nodo* aux = c.pri;
        c.pri = c.pri->izqda;
        delete aux;
    }
    c.tamanio = 0;
}

template<typename K, typename V, typename T>
string listar(ColeccionMT<K,V,T>& c){

    ostringstream listado;
    K clave;
    V valor;
    T tiempo;
    bool tieneMarca;

    iniciarIterador(c);
    while(existeSiguiente(c)){
        if(siguiente(c,clave,valor,tiempo,tieneMarca)){
            listado << "[";
            listado << clave << ":::";

            if (tieneTiempo(c,clave)) {
                listado << "";
                 mostrarTiempo(tiempo);
            }
            else {
                listado << "-";
            }
            listado << "]" << endl;
            listado <<"";
            mostrarPregunta(valor);
        }
    }
    return listado.str();
}


template<typename K, typename V, typename T>
void iniciarIterador(ColeccionMT<K,V,T>& c){
    typename ColeccionMT<K,V,T>::Nodo* aux = c.pri;
    crear(c.d);
    while(aux != nullptr){
        push(c.d, aux);
        aux = aux->izqda;
    }
}

template<typename K, typename V, typename T>
bool existeSiguiente(const ColeccionMT<K,V,T>& c){
    return !(esVacia(c.d));
}

template<typename K, typename V, typename T>
bool siguiente(ColeccionMT<K,V,T>& c, K& k, V& v, T& t, bool& tienemarca){
    typename ColeccionMT<K,V,T>::Nodo* aux;
    if(existeSiguiente(c)){
        aux = pop(c.d);
        k = aux->clave;
        v = aux->valor;
        t = aux->tiempo;
        tienemarca = aux->tieneMarca;
        aux = aux->drcha;
        while(aux != nullptr){
            push(c.d, aux);
            aux = aux->izqda;
        }
        return true;

    }
   return false;
}


template<typename K, typename V, typename T>
void insertarRec(typename ColeccionMT<K,V,T>::Nodo*& nodo, const K& k, const V& v, bool& metido){
    if(nodo == nullptr){
        nodo = new typename ColeccionMT<K,V,T>::Nodo;
        nodo->clave = k;
        nodo->valor = v;
        nodo->tieneMarca = false;
        nodo->izqda = nullptr;
        nodo->drcha = nullptr;
        metido = true;
    } else if(k == nodo->clave){
        nodo->valor = v;
        nodo->tieneMarca = false;
    } else if(k <= nodo->clave){
        insertarRec<K,V,T>(nodo->izqda, k, v, metido);
    } else {
        insertarRec<K,V,T>(nodo->drcha, k, v, metido);
    }
}

template<typename K, typename V, typename T>
void borrarMaximo(typename ColeccionMT<K,V,T>::Nodo*& nodo, K& k, V& v, T& t){
    typename ColeccionMT<K,V,T>::Nodo* aux;
    if(nodo->drcha == nullptr){
        k = nodo->clave;
        v = nodo->valor;
        t = nodo->tiempo;
        aux = nodo;
        nodo = nodo->izqda;
        delete aux;
    } else {
        borrarMaximo(nodo->drcha, k, v, t);
    }
}

template<typename K, typename V, typename T>
void borrarRec(typename ColeccionMT<K,V,T>::Nodo*& nodo, const K& k, bool& borrado){
    if (nodo == nullptr) {
        borrado = false;
    } else if (k < nodo->clave) {
        borrarRec<K,V,T>(nodo->izqda, k, borrado);
    } else if (k > nodo->clave) {
        borrarRec<K,V,T>(nodo->drcha, k, borrado);
    } else {
        typename ColeccionMT<K,V,T>::Nodo* aux = nodo;
        if (nodo->izqda == nullptr) {
            nodo = nodo->drcha;
        } else if (nodo->drcha == nullptr) {
            nodo = nodo->izqda;
        } else {
            borrarMaximo(nodo->izqda, aux->clave, aux->valor, aux->tiempo);
        }
        delete aux;
        borrado = true;
    }
}

#endif // COLECCIONCONMARCATIEMPO_H_INCLUDED

