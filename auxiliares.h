//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int filas (vector<vector<bool>> const &t);
int columnas (vector<vector<bool>> const &t);
bool esRectangulo (vector<vector<bool>> const &r);
bool enRangoToroide (int f, int c, toroide const &t);
int cantidadVivas (toroide const &t);
bool estaViva (int f, int c, vector<vector<bool>> const &t);
bool esPrimoLejano (toroide &t, toroide &u);
int ticksViva (toroide &t);
toroide trasladar (toroide const &t, int k, int l);
int vivasEn (toroide const &t, int x, int y, int a, int b);
int supVivaDesde (toroide const &t, posicion x);

#endif //REUNIONESREMOTAS_AUXILIARES_H
