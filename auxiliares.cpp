#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}
int filas (vector<vector<bool>> const &t){
    return t.size();
}


int columnas (vector<vector<bool>> const &t){
    int result = 0;
    if (filas(t) > 0){
        result = t[0].size();
    }
    return result;
}

bool esRectangulo (vector<vector<bool>> const &r) {
    int i = 0;
    while (i < r.size() && r[i].size() == r[0].size()){
        i++;
    }
    bool result = (r.size() > 0) && (r[0].size() > 0) && (i == r.size());
    return result;
}
bool enRangoToroide (int f, int c, toroide const &t){
    return (0 <= f && f < t.size() && 0 <= c && c < t[0].size());
}

int cantidadVivas (toroide const &t){
    int c = 0;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (t[i][j]){
                c++;
            }
        }
    }
    return c;
}

bool estaViva (int f, int c, vector<vector<bool>> const &t){
    bool result = false;
    if (enRangoToroide(f, c, t) && t[f][c]){
        result = true;
    }
    return result;
}
bool esPrimoLejano (toroide &t, toroide &u){
    int i = 0;
    int p = 0;
    bool periodico = esPeriodico(t, p); //Por si es periodico
    bool result = false;
    while (!result && (!(toroideMuerto(evolucionMultiple(u, i))) && !(esPeriodico(u, p) && (i > p)))){
        if (evolucionMultiple(u, i) == t){
            result = true;
        }
        i++;
    }
    return result;
}

int ticksViva (toroide &t) {
    int i = 0;
    while (!toroideMuerto(evolucionMultiple(t, i))){
        i++;
    }
    return i;
}

toroide trasladar (toroide const &t, int k, int l){
    toroide t0 = t;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            t0[(i+k) % t.size()][(j+l) % t[0].size()] = t[i][j];
        }
    }
    return t0;
}

int vivasEn (toroide const &t, int x, int y, int a, int b){
    int i = 0;
    int j = 0;
    int result = 0;
    while (i <= (a - x)%t.size()){
        j = 0;
        while (j <= (b - y)%t[0].size()){
            if (t[(x+i) % t.size()][(y+j) % t[0].size()]){
                result++;
            }
            j++;
        }
        i++;
    }
    return result;
}

int supVivaDesde (toroide const &t, posicion x){
    int result = t.size() * t[0].size();
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            int sup = (i+1)*(j+1);
            if (sup < result && cantidadVivas(t)==vivasEn(t, x.first, x.second, x.first + i, x.second + j)){
                result = sup;
            }
        }
    }
    return result;
}