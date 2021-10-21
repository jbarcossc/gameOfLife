#include <iostream>
#include <vector>
#include <utility>
#include "auxiliares.h"
using namespace std;


//EJERCICIO 1
bool toroideValido (toroide const &t){
    bool result = false;
    if (esRectangulo(t) && filas(t) >= 3 && columnas(t) >= 3){
        result = true;
    }
    return result;
}

//EJERCICIO 2
bool toroideMuerto (toroide const &t){
    bool result = true;
    for (int i = 0; i < t.size(); i++){
        for(int j = 0; j < t[0].size(); j++){
            if (t[i][j]){
                result = false;
            }
        }
    }
    return result;
}

// EJERCICIO 3
vector<pair<int, int>> posicionesVivas(toroide const &t){
    vector<pair<int, int>> vivas;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            pair<int, int> pos(i, j);
            if (estaViva(i, j, t)){
                vivas.push_back(pos);
            }
        }
    }
    return vivas;
}

// EJERCICIO 4
float densidadPoblacion (toroide const &t) {
    float result = (float)(cantidadVivas(t)) / ((float)(t.size()) * (float)(t[0].size()));
    return result;
}




// EJERCICIO 5
int cantidadVecinosVivos (toroide const &t, int f, int c){
    int result = 0;
    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            int x = (f + i + t.size()) % t.size();
            int y = (c + j + t[0].size()) % t[0].size();
            if (t[x][y] && (x!= f || y!= c)){
                result++;
            }
        }
    }
    return result;
}
// EJERCICIO 6

bool evolucionDePosicion (toroide const &t, posicion x){
    int v = cantidadVecinosVivos(t, x.first, x.second);
    bool result = false;
    if (t[x.first][x.second] && (v == 2 || v == 3)){
        result = true;
    } else {
        if (!t[x.first][x.second] && v == 3){
            result = true;
        }
    }
    return result;
}

// EJERCICIO 7

void evolucionToroide (toroide &t){
    toroide t0 = t;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            t[i][j] = evolucionDePosicion(t0, posicion (i,j));
        }
    }
}



// EJERCICIO 8

toroide evolucionMultiple (toroide const &t, int k){
    toroide t0 = t;
    for (int i = 0; i < k; i++){
        evolucionToroide(t0);
    }
    return t0;
}


// EJERCICIO 9

bool esPeriodico(toroide const &t, int &p){
    bool result = true;
    p = 1;
    while (result && (evolucionMultiple(t, p) != t)) {
        if (toroideMuerto(evolucionMultiple(t, p))) {
            result = false;
        }
        p++;
    }
    return result;
}

// EJERCICIO 10

bool primosLejanos (toroide const &t, toroide const &u){
    toroide t0 = t;
    toroide u0 = u;
    bool result = false;
    if (esPrimoLejano(t0, u0) || esPrimoLejano(u0,t0)){
        result = true;
    }
    return result;
}

// EJERCICIO 11
int seleccionNatural (vector<toroide> ts){
    int result = 0;
    for (int i = 0; i < ts.size(); i++){
        if (ticksViva(ts[result]) <= ticksViva(ts[i])){
            result = i;
        }
    }
    return result;
}

// EJERCICIO 12
toroide fusionar (toroide const &t, toroide const &u){
    toroide f = t;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (!t[i][j] || !u[i][j]){
                f[i][j]=false;
            }
        }
    }
    return f;
}

// EJERCICIO 13
bool vistaTrasladada (toroide const &t, toroide const &u){
    bool result = false;
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (trasladar(t, i, j) == u){
                result = true;
            }
        }
    }
    return result;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t) {
    int result = t.size()*t[0].size();
    if (toroideMuerto(t)) {
        result = 0;
    }
    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t[0].size(); j++){
            if (supVivaDesde(t, posicion (i,j)) < result){
                result = supVivaDesde(t, posicion (i,j));
            }
        }
    }
    return result;
}
