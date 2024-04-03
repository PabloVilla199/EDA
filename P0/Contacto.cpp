#include "Contacto.h"

void crear(string nom, int tlfo, contacto& c){
    c.nombre = nom;
    c.telefono = tlfo;

}
 string nombres(const contacto& c){
    return c.nombre;

 }
int telefono (const contacto& c){
    return c.telefono;
}
