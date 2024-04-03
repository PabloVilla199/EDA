#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

template<typename T> struct PilaDinamica;
template<typename T> void crear(PilaDinamica<T>& p);
template<typename T> void push(PilaDinamica<T>& p, const T& e);
template<typename T> T pop(PilaDinamica<T>& p);
template<typename T> bool esVacia(const PilaDinamica<T>& p);
template<typename T> int tamanyo(const PilaDinamica<T>& p);
template<typename T> void liberar(PilaDinamica<T>& p);

template<typename T> struct PilaDinamica{
 friend void crear <T>(PilaDinamica<T>& p);
 friend void push <T>(PilaDinamica<T>& p, const T& e);
 friend T pop <T>(PilaDinamica<T>& p);
 friend bool esVacia <T>(const PilaDinamica<T>& p);
 friend int tamanyo <T>(const PilaDinamica<T>& p);
 friend void liberar <T>(PilaDinamica<T>& p);

private:
    struct Nodo {
        T valor;
        Nodo* siguiente;
    };
    Nodo* elPrimero;
    int numDatos;
};

template<typename T>
void crear(PilaDinamica<T>& p){
    p.numDatos = 0;
    p.elPrimero = nullptr;
}
template<typename T>
 bool esVacia(const PilaDinamica<T>& p){
    return p.numDatos == 0;
 }

template<typename T>
void push(PilaDinamica<T>& p, const T& e){
    typename PilaDinamica<T>::Nodo* aux = p.elPrimero;
    p.elPrimero = new typename PilaDinamica<T>::Nodo;
    p.elPrimero->valor = e;
    p.elPrimero->siguiente = aux;
    p.numDatos = p.numDatos + 1;
}

template<typename T>
int tamanyo(const PilaDinamica<T>& p){
    return p.numDatos;
}
template<typename T>
T pop(PilaDinamica<T>& p){
    typename PilaDinamica<T>::Nodo* aux = p.elPrimero;
    T valorRetirado;

    if (!esVacia(p)) {
        p.elPrimero = p.elPrimero->siguiente;
        valorRetirado = aux->valor;
        delete aux;
        p.numDatos = p.numDatos - 1;
        return valorRetirado;
    } else {
        return valorRetirado;
    }
}

template<typename T>
void liberar(PilaDinamica<T>& p){
  while (!esVacia(p)) {
    typename PilaDinamica<T>::Nodo* temp = p.elPrimero;
    p.elPrimero = p.elPrimero->siguiente;
    delete temp;
    p.numDatos--;
  }
}
#endif // PILADINAMICA_H_INCLUDED
