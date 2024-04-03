#ifndef AGRUPACION_H_INCLUDED
#define AGRUPACION_H_INCLUDED


const int MAX = 40;
template<typename T> struct agrupacion;
template<typename T> void iniciar (agrupacion<T>& c);
template<typename T> bool anyadir (agrupacion<T>& c, const T& p);
template<typename T> bool borrarUltimo (agrupacion<T>& c);
template<typename T>
struct agrupacion{
friend void iniciar<T> (agrupacion<T>& c);
friend bool anyadir<T> (agrupacion<T>& c, const T& p);
friend bool borrarUltimo<T> (agrupacion<T>& c);
private:
T datos[MAX];
int total;
};
template<typename T>
void iniciar (agrupacion<T>& c) {
c.total = 0;
}
template<typename T>
bool anyadir (agrupacion<T>& c, const T& p) {
bool sePuede = c.total < MAX;
if (sePuede) {
c.datos[c.total] = p;
c.total++;
}
return sePuede;
}
template<typename T>
bool borrarUltimo (agrupacion<T>& c) {
bool sePuede = c.total > 0;
if (sePuede) c.total--;
return sePuede;
}
#endif // AGRUPACION_H_INCLUDED
