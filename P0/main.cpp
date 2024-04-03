#include <iostream>
#include "Contacto.h"
#include "product0.h"
#include "agrupacion.h"

using namespace std;

int main()
{
producto nar;
crear("naranjas", 2, nar);
producto per;
crear("peras", 4, per);
agrupacion<producto> compra; iniciar(compra);
anyadir(compra, nar); anyadir(compra, per);
contacto c1;
crear("pablo",85426,c1);
contacto c2;
crear("ana", 976444444, c2);
agrupacion<contacto> agenda;
iniciar(agenda);
anyadir(agenda, c1);
anyadir(agenda, c2);
nombre(nar);

for(int i = 0; i < 5; i++){

}






}
