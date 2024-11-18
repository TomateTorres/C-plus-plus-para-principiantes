/*
El siguiente programa contiene una función que recibe dos 
parámetros: Un `std::vector` y un índice. Si el índice está
fuera de rango, se imprime un error, si el índice está dentro 
del rango permitido, se imprime el valor del elemento al que le
corresponde.
*/

#include <iostream>
#include <vector>
#include <string> 

void imprimeElemento(const auto& vect, int indice){
// Pasamos el vector por referencia constante (no lo vamos a
// modificar y puede ser un objeto costoso de copiar) y usamos
// `auto` para permitir que nuestra función acepte cualquier tipo
// de vector `vect`.

    if (indice < 0 || 
        (static_cast<int>(vect.size())-1 < indice)){ 
    // Si el índice es un número negativo o es más grande que el
    // tamaño-1 del vector, está fuera de rango. Usamos `static_cast`  
    // porque `vect.size()` nos da un entero sin signo y no podemos
    // compararlo con `indice` (que es de tipo `int`).

        std::cout << "El índice está fuera de rango." << '\n';
    }

    else{

        std::cout << "El valor que corresponde a " << indice << " es "
                  << vect[static_cast<std::size_t>(indice)] << '\n';
    }
}
int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    imprimeElemento(v1, 2); // El valor que corresponde a 2 es 2
    imprimeElemento(v1, 5); // El índice está fuera de rango.

    std::vector v2 { 1.1, 2.2, 3.3 };
    imprimeElemento(v2, 0); // El valor que corresponde a 0 es 1.1
    imprimeElemento(v2, -1); // El índice está fuera de rango.

    std::vector mosqueteros { "Athos", "Porthos", "Aramis" };
    imprimeElemento(mosqueteros, 4); // El índice está fuera de rango.
    imprimeElemento(mosqueteros, 0); // El valor que corresponde a 0 es Athos

    return 0;
}
