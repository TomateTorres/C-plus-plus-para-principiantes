/*
El siguiente programa: Define una función llamada `sumaA()` que
recibe un parámetro entero y nos retorna la suma de todos los 
enterior desde 1 al valor dado.
*/

#include <iostream>

int sumaA(int valor){ // `valor` es el número hasta el que vamos
                      // a sumar.
    
    int acumulador{}; //Vamos a ir guardando los valores sumados
                      // en cada iteración (o sea: En la iteración 1
                      // `acumulador == 1`, en la 2 `acumulador == 1 + 2`, 
                      // ...)
    for (int i{1}; i<=valor; ++i){ // La variable `i` es sólo para 
                                   // 'movernos' del 1 al valor dado.
        acumulador += i;
    }
    return acumulador; // Al final del ciclo, tendremos 1 + 2 + ... + valor
}

int main(){
    int valor{4}; // Queremos la suma del 1 al 4
    std::cout << "La suma de 1 a " << valor << " es: "
              << sumaA(valor) << '\n';

    return 0;
}


