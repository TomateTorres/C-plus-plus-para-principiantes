/*
En el siguiente programa le pedimos al usuario que nos de un 
número entero en el intervalo [0, 9] y le dice si es un número
primo o no.
*/

/*
El siguiente programa muestra:
1. Que podemos definir funciones tipo `bool` (cosa que a lo mejor
en principio no es tan obvia a porque probablemente no lo hemos
hecho antes).
2. Un ejemplo de encadenamiento de condiciones `if`
*/

#include <iostream>


bool esPrimo(int x)
{
    if (x == 2)
        return true;
    else if (x == 3)
        return true;
    else if (x == 5)
        return true;
    else if (x == 7)
        return true;
    
// Todas las condiciones anteriores son para verificar si `x` es 
// un número primo dentro del intervalo [0, 9]

    return false; // Si `x` no es primo, el valor devuelto es `false`
}

int main()
{
    std::cout << "Dame un entero en el intervalo [0, 9]: ";
    int x{};
    std::cin >> x;

    if ( esPrimo(x) ) 
        std::cout << "Tu entero es primo.\n";
    // Si `x` es primo, al evaluarlo en la función `esPrimo`, 
    // `esPrimo(x)` tiene por valor a `true`. Por tanto, la condición
    // es verdadera y se ejecuta la instrucción inmediata despues de
    // `if ( esPrimo(x) )`
    
    else 
        std::cout << "Tu entero no es primo.\n";
    // Si `x` no esprimo, al evaluarlo en la función `esPrimo`, 
    // `esPrimo(x)` tiene por valor a `false`. Por tanto, la condición
    // después de `if` no es verdadera, así que el programa se salta 
    // la línea inmediata posterior (`std::cout << "Tu entero es primo.\n";`)
    // y se ejecuta la instrucción inmediata despues de `else`.

    return 0;
}
