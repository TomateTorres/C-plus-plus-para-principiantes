/*
El siguiente programa imprime:
5 4 3 2 1
4 3 2 1
3 2 1
2 1
1
Mediante ciclos anidados.
*/

#include <iostream>

int main(){

    int ext{5};

    // El ciclo exterior es el que se mueve por filas de arriba 
    // hacia abajo.
    while (1 <= ext){ // Nos paramos en una fila y vamos desde
                      // `ext` hasta 1.
        int interior{ext}; // La variable que itera en la fila.

        while (1 <= interior){
            std::cout << interior-- << ' ';
            /*
            En este caso, usamos el operador post-decremento
            en vez del operador pre-decremento porque queremos
            primero usar el valor que tiene la variable `interior`
            y luego restarle un uno. Si usáramos `--interior`el 
            programa nos imprimiría:
            4 3 2 1 0 
            3 2 1 0 
            2 1 0 
            1 0 
            0 
            Una manera de seguir usando el operador pre-decremento
            y obtener lo que queremos sería hacer: `--interior + 1`
            */
        }

        // Imprime un salto de línea despues de cada fila:
        std::cout << '\n';

        --ext; // Bajamos en uno el valor de `ext` (aquí es
               // indistinto si usamos `--ext` ó `ext--`
    }
    return 0;
}
