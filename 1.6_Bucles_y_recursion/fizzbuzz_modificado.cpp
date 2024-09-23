/*
Esta es una modificación a 'fizzzbuzz.cpp' que agrega la regla
de que los números divisibles entre 7 deben ser reemplazados por
la palabra "pop".
*/

#include <iostream>

void fizzbuzzpop(int num){
    for (int i{1}; i<=num; ++i){ // `i` va desde 1 al número dado
        
        bool impreso{false}; // Definimos una variable que nos
                             // determinará si una (o más) partes
                             // de "FizzBuzzPop" se imprime.

        if (i % 3 == 0){ // Si el número en que vamos es divisible
                         // entre 3.
            std::cout << "Fizz";
            impreso = true; // Cambiamos el valor de verdad de 
                            // impreso.
        }
        if (i % 5 == 0){ // Si el número en que vamos es divisible
                         // entre 5.
            std::cout << "Buzz";
            impreso = true; // Cambiamos el valor de verdad de 
                            // impreso.
        }
        if (i % 7 == 0){ // Si el número en que vamos es divisible
                         // es divisible entre 7.
            std::cout << "Pop";
            impreso = true; // Cambiamos el valor de verdad de 
                            // impreso.
        }
        
        if (!impreso){ // Si impreso es `false` (o sea, si no se 
                       // ha impreso una o más partes de "FizzBuzzPop")
                       // entonces se imprime el número. Esto es porque 
                       // si `impreso` se quedó como `false` hasta aquí
                       // (porque el número no era divisible ni entre 3, 
                       // 5 ó 7), entonces `!impreso` es `true` y este 
                       // condicional se ejecuta.
            std::cout << i;
        }

        std::cout << '\n'; // Hasta el final de la verificación de
                           // todas las condiciones es que hacemos el
                           // salto de línea.
    }
}


int main(){

    fizzbuzzpop(105); // Corremos hasta el 105 porque este es mínimo 
                      // común múltiplo de (3, 5, 7).
    return 0;
}
